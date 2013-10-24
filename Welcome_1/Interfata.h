/* 
 * File:   Interfata.h
 * Author: sboros
 *
 * Created on October 24, 2013, 9:24 AM
 */

#ifndef INTERFATA_H
#define INTERFATA_H

#include "Stare.h"
#include "String.h"
#include "OperatiiContact.h"
#include "CrossClrScr.h"

//View - aceasta clasa/biblioteca raspunde de tot ce trebuie sa se afiseze pe ecran

class Interfata
{
    Stare *stare; //Indica unde sunt pozitionat in Menu
    OperatiiContact *operatiiContact; //Controllerul - aici au loc operatiile de
    //Stergere, adaugare, ...
    String advancedFilter; //Filtrul folosit pentru cautarea/filtrarea datelor afisate
    char keyPressed; //Folosita pentru a determina ce tasta a fost apasata
    int nrDeElemente; //Var auxiliara pentru a tine minte cite Elemente sunt in lista
public:

    Interfata()
    {
        stare = new Stare;
        operatiiContact = new OperatiiContact;
        keyPressed = ' ';
        nrDeElemente = 0;
    }
    ~Interfata(){ delete stare; delete operatiiContact; }

    bool display(void); //Functia principala de afisare a meniului
    void displayFilter(void); //Afiseaza legata de Filtru
    void displayAdvancedFilter(void); //Afiseaza partea legata de Filtrul Avansat/Cautarea
    void displayAdaugaUnContact(void); //...
    void displayNavigheazaContacte(void);
    void displayListaCuContacte(void);
    void displaySubMenuOperatiiCuAgenda(void);
    void displayCreareaUneiNoiAgende(void);
    void displaySalvareaAgendei(void);
    void displayIncarcareaAgendei(void);
    void displayAutoSalvare(void);
    void displayIesire(void);
    void navigare(void); //Functia ce determina in ce directie ma misc prin Meniu

    //Interfete
    void interfataAdaugaUnContact(void);//...
    void interfataEditeazaContact(void);
    void interfataSalvareDate(void);
    void interfataCreareaUneiNoiAgenda(void);
    void interfataIncarcaDate(void);

    inline String obtineAdvancedFilter(void) const;
    inline void modificaAdvancedFilter(String);

    bool controleazaButoaneleDeMiscare(char);

};

void Interfata::interfataIncarcaDate(void)
{
    clrscr();
    cout<<endl<<"Introduceti denumirea fisierului: ";
    char denFis[30];
    cin>>denFis;

    delete stare;
    delete operatiiContact;
    stare = new Stare;
    operatiiContact = new OperatiiContact;

    operatiiContact->incarcaDatele(denFis);
    operatiiContact->sorteaza();
}

void Interfata::interfataSalvareDate(void)
{
    clrscr();
    cout<<endl<<"Introduceti denumirea fisierului: ";
    char denFis[30];
    cin>>denFis;
    operatiiContact->salveazaDatele(denFis, stare->obtineStareFiltru());
    stare->modificaStareModificari(0);
}

void Interfata::interfataCreareaUneiNoiAgenda(void)
{
    clrscr();
    if( stare->obtineStareModificari() )
    {
        cout<<"Vreti sa salvati Agenda?(y/n): ";
        char k;
        cin>>k;
        if( k == 'y' )
        {
            cout<<endl<<"Introduceti denumirea fisierului: ";
            char denFis[30];
            cin>>denFis;
            operatiiContact->salveazaDatele(denFis, stare->obtineStareFiltru());
            delete stare;
            delete operatiiContact;
            stare = new Stare;
            operatiiContact = new OperatiiContact;
        }
        else
        {
            delete stare;
            delete operatiiContact;
            stare = new Stare;
            operatiiContact = new OperatiiContact;
        }
    }
    else
    {
        delete stare;
        delete operatiiContact;
        stare = new Stare;
        operatiiContact = new OperatiiContact;
    }
}

bool Interfata::controleazaButoaneleDeMiscare(char k)
{
    if( k == (75 || 77 || 80 || 72 || 13 || 27) )
        return 1;
    else
        return 0;
}

void Interfata::interfataEditeazaContact(void)
{
    String nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email;
    short tipContact;
    clrscr();
    cout<<"Modificati datele Contactului:"<<endl<<endl;
    cout<<"Nume: "; cin>>nume;
    cout<<"Prenume: "; cin>>prenume;
    cout<<"Adresa: "; cin>>adresa;
    cout<<"Ziua de Nastere: "; cin>>ziDeNastere;
    cout<<"Tel. Dom.: "; cin>>tel_dom;
    cout<<"Tel. Mob.: "; cin>>tel_mob;
    cout<<"Email: "; cin>>email;
    cout<<"Categoria(1 - Prieten, 2 - Coleg de Serviciu, 3 - Membri de Familie, 4 - Nici o categorie):"<<endl;
    cin>>tipContact;

    int pozMea = stare->obtineStarePozInLista();
    operatiiContact->listaFiltrataResetToPrim();
    for(register int i = 0; i < pozMea; i++)
    {
        operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru());
        operatiiContact->listaFiltrataMoveToNextElement();
    }
    operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru());
    operatiiContact->stergeContact();
    stare->modificaStarePozInLista(0);
    nrDeElemente--;
    stare->modificaStareModificari(1);
    stare->modificaStareModificariPentruSort(1);

    operatiiContact->adaugaContact(nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email, tipContact);
    this->nrDeElemente++;
    stare->modificaPozMaxLista( nrDeElemente );
}

void Interfata::interfataAdaugaUnContact(void)
{
    String nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email;
    short tipContact;
    clrscr();
    cout<<"Introduceti datele despre Contact:"<<endl<<endl;
    cout<<"Nume: "; nume.citLitere();
    cout<<"Prenume: "; prenume.citLitere();
    cout<<"Adresa: "; cin>>adresa;
    cout<<"Ziua de Nastere: "; cin>>ziDeNastere;
    cout<<"Tel. Dom.: "; tel_dom.citCifre();
    cout<<"Tel. Mob.: "; tel_mob.citCifre();
    cout<<"Email: "; cin>>email;
    cout<<"Categoria(1 - Prieten, 2 - Coleg de Serviciu, 3 - Membri de Familie, 4 - Nici o categorie):"<<endl;
    cin>>tipContact;
    operatiiContact->adaugaContact(nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email, tipContact);
    this->nrDeElemente++;
    stare->modificaPozMaxLista( nrDeElemente );
    operatiiContact->sorteaza();

}

inline String Interfata::obtineAdvancedFilter(void) const
{
    return this->advancedFilter;
}

inline void Interfata::modificaAdvancedFilter(String advancedFilter)
{
    this->advancedFilter=advancedFilter;
}

bool Interfata::display(void)
{
    while(1)
    {
        clrscr();
        this->displayFilter();
        this->displayAdvancedFilter();
        this->displayAdaugaUnContact();
        this->displayNavigheazaContacte();
        this->displayListaCuContacte();
        this->displaySubMenuOperatiiCuAgenda();
        this->displayCreareaUneiNoiAgende();
        this->displaySalvareaAgendei();
        this->displayIncarcareaAgendei();
        this->displayAutoSalvare();
        this->displayIesire();
        this->navigare();
        operatiiContact->listaFiltrataResetToPrim();
    }
    return 0;
}

void Interfata::navigare()
{
    if(keyPressed==13 || keyPressed==27 || keyPressed==72 || keyPressed==75 || keyPressed==77 || keyPressed==80)
    {
        int pozMea = stare->obtineStarePozInLista();
        switch(stare->obtineStareMeniuPrincipal())
        {
        case 0:
            switch(keyPressed)
            {
            case 75:
                stare->decrementeazaStareFiltru();
                break;
            case 77:
                stare->incrementeazaStareFiltru();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 1:
            switch(keyPressed)
            {
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 2:
            switch(keyPressed)
            {
            case 13:
                this->interfataAdaugaUnContact();
                stare->modificaStareModificari(1);
                stare->modificaStareModificariPentruSort(1);
                if( stare->obtineStareAutoSalvare() && stare->obtineStareModificari())
                {
                    operatiiContact->salveazaDatele("autosalvare.txt", stare->obtineStareFiltru());
                    stare->modificaStareModificari(0);
                }
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 3:
            switch(keyPressed)
            {
            case 13:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 4:
            switch(stare->obtineStareOptiuneCont())
            {
            case 0:
                switch(keyPressed)
                {
                case 27:
                    stare->decrementeazaStareMeniuPrincipal();
                    stare->modificaStareOptiuneCont(0);
                    stare->modificaStarePozInLista(0);
                    if( stare->obtineStareAutoSalvare() && stare->obtineStareModificari())
                    {
                        operatiiContact->salveazaDatele("autosalvare.txt", stare->obtineStareFiltru());
                        stare->modificaStareModificari(0);
                    }
                    break;
                case 75:
                    stare->decrementeazaStareOptiuneCont();
                    break;
                case 77:
                    stare->incrementeazaStareOptiuneCont();
                    break;
                case 80:
                    stare->incrementeazaStarePozInLista();
                    break;
                case 72:
                    stare->decrementeazaStarePozInLista();
                    break;
                case 13:
                    stare->modificaStareOptiuneCont(1);
                    break;
                default:
                    break;
                }
                break;
            case 1:
                switch(keyPressed)
                {
                case 13:
                    this->interfataEditeazaContact();
                    break;
                case 75:
                    stare->decrementeazaStareOptiuneCont();
                    break;
                case 77:
                    stare->incrementeazaStareOptiuneCont();
                    break;
                case 80:
                    stare->incrementeazaStarePozInLista();
                    break;
                case 72:
                    stare->decrementeazaStarePozInLista();
                    break;
                case 27:
                    stare->decrementeazaStareMeniuPrincipal();
                    stare->modificaStareOptiuneCont(0);
                    stare->modificaStarePozInLista(0);
                    if( stare->obtineStareAutoSalvare() && stare->obtineStareModificari())
                    {
                        operatiiContact->salveazaDatele("autosalvare.txt", stare->obtineStareFiltru());
                        stare->modificaStareModificari(0);
                    }
                    break;
                default:
                    break;
                }
                break;
            case 2:
                switch(keyPressed)
                {
                case 75:
                    stare->decrementeazaStareOptiuneCont();
                    break;
                case 77:
                    stare->incrementeazaStareOptiuneCont();
                    break;
                case 80:
                    stare->incrementeazaStarePozInLista();
                    break;
                case 72:
                    stare->decrementeazaStarePozInLista();
                    break;
                case 27:
                    stare->decrementeazaStareMeniuPrincipal();
                    stare->modificaStareOptiuneCont(0);
                    stare->modificaStarePozInLista(0);
                    if( stare->obtineStareAutoSalvare() && stare->obtineStareModificari())
                    {
                        operatiiContact->salveazaDatele("autosalvare.txt", stare->obtineStareFiltru());
                        stare->modificaStareModificari(0);
                    }
                default:
                    break;
                }
                break;
            case 3:
                switch(keyPressed)
                {
                case 13:
                    operatiiContact->listaFiltrataResetToPrim();
                    for(register int i = 0; i < pozMea; i++)
                    {
                        operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru());
                        operatiiContact->listaFiltrataMoveToNextElement();
                    }
                    operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru());
                    operatiiContact->stergeContact();
                    stare->modificaStarePozInLista(0);
                    nrDeElemente--;
                    stare->modificaStareModificari(1);
                    stare->modificaStareModificariPentruSort(1);
                    break;
                case 75:
                    stare->decrementeazaStareOptiuneCont();
                    break;
                case 77:
                    stare->incrementeazaStareOptiuneCont();
                    break;
                case 80:
                    stare->incrementeazaStarePozInLista();
                    break;
                case 72:
                    stare->decrementeazaStarePozInLista();
                    break;
                case 27:
                    stare->decrementeazaStareMeniuPrincipal();
                    stare->modificaStareOptiuneCont(0);
                    stare->modificaStarePozInLista(0);
                    if( stare->obtineStareAutoSalvare() && stare->obtineStareModificari())
                    {
                        operatiiContact->salveazaDatele("autosalvare.txt", stare->obtineStareFiltru());
                        stare->modificaStareModificari(0);
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;
        case 5:
            switch(keyPressed)
            {
            case 13:
                this->interfataCreareaUneiNoiAgenda();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 6:
            switch(keyPressed)
            {
            case 13:
                this->interfataSalvareDate();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 7:
            switch(keyPressed)
            {
            case 13:
                this->interfataIncarcaDate();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 8:
            switch(keyPressed)
            {
            case 13:
                stare->switchStareAutoSalvare();
                break;
            case 75:
                stare->switchStareAutoSalvare();
                break;
            case 77:
                stare->switchStareAutoSalvare();
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        case 9:
            switch(keyPressed)
            {
            case 13:
                //Propune sa salvezi in caz ca sunt modificari
                exit(1);
                break;
            case 80:
                stare->incrementeazaStareMeniuPrincipal();
                break;
            case 72:
                stare->decrementeazaStareMeniuPrincipal();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        keyPressed=' ';
    }                     //Sfirsit de IF//
    else
    {
        String citeste;
        bool tipContact;
        switch(stare->obtineStareMeniuPrincipal())
        {
        case 1:
            keyPressed=advancedFilter.passReadNoOutputLitere();
            break;
        case 4:
            switch(stare->obtineStareOptiuneCont())
            {
            case 0:
                keyPressed=advancedFilter.passReadNoOutputLitere();
                break;
            default:
                keyPressed = citeste.passReadNoOutput();
                break;
            }
            break;
        default:
            keyPressed = citeste.passReadNoOutput();
            break;
        }
    }
}
//////////////////////////////
///// Sfirsit Navigare!! /////
//////////////////////////////
void Interfata::displayIesire(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 9:
        cout<<"[Iesire]"<<endl;
        break;
    default:
        cout<<" Iesire"<<endl;
        break;
    }
}

void Interfata::displayAutoSalvare(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 8:
        switch(stare->obtineStareAutoSalvare())
        {
        case 0:
            cout<<"[Auto-Salvare]: [ON]  OFF"<<endl;
            break;
        case 1:
            cout<<"[Auto-Salvare]:  ON  [OFF]"<<endl;
            break;
        default:
            break;
        }
        break;
    default:
        cout<<" Auto-Salvare"<<endl;
        break;
    }
}

void Interfata::displayIncarcareaAgendei(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 7:
        cout<<"[Incarcarea unei Agende dintr-un fisier]"<<endl;
        break;
    default:
        cout<<" Incarcarea unei Agende dintr-un fisier"<<endl;
        break;
    }
}

void Interfata::displaySalvareaAgendei(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 6:
        if( stare->obtineStareModificari() == 1 )
            cout<<"[Salvarea agendei intr-un fisier*]"<<endl;
        else
            cout<<"[Salvarea agendei intr-un fisier]"<<endl;
        break;
    default:
        if( stare->obtineStareModificari() == 1 )
            cout<<" Salvarea agendei intr-un fisier*"<<endl;
        else
            cout<<" Salvarea agendei intr-un fisier"<<endl;
        break;
    }
}

void Interfata::displayCreareaUneiNoiAgende(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 5:
        cout<<"[Crearea unei noi Agende]"<<endl;
        break;
    default:
        cout<<" Crearea unei noi Agende"<<endl;
        break;
    }
}

void Interfata::displaySubMenuOperatiiCuAgenda(void)
{
    cout<<endl<<"_____Operatii cu Agenda_____"<<endl<<endl;
}

void Interfata::displayListaCuContacte(void) //Needs FKN modifications
//Afisarea sa se faca aici dar nu in Controller!(OperatiiContact.h)
//Make your fkn genius brain to work hard!
{
    nrDeElemente = operatiiContact->obtineNrDeElementeCuFiltru(advancedFilter, stare->obtineStareFiltru());
    int pozMea = stare->obtineStarePozInLista();
    stare->modificaPozMaxLista(nrDeElemente - 1);

    for(register int i = 0; i < nrDeElemente; i++)
    {
        //Afisarea
        if(stare->obtineStareMeniuPrincipal() == 4)
        {
            if( i == pozMea )
            {
                switch( stare->obtineStareOptiuneCont() )
                {
                case 0:
                    cout<<"["<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
                    cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<"]    Editeaza     Toata Informatia     Sterge"<<endl;
                    operatiiContact->listaFiltrataMoveToNextElement();
                    break;
                case 1:
                        cout<<"|"<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
                        cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<"|   [Editeaza]    Toata Informatia     Sterge"<<endl;
                    operatiiContact->listaFiltrataMoveToNextElement();
                    break;
                case 2:
                    cout<<"|"<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
                    cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<"|    Editeaza    [Toata Informatia]    Sterge"<<endl;
                    cout<<"  Nume:             "<<operatiiContact->obtineNumeDupaFiltru()<<endl;
                    cout<<"  Prenume:          "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<endl;
                    cout<<"  Adresa:           "<<operatiiContact->obtineAdresaDupaFiltru()<<endl;
                    cout<<"  Ziua de Nastere:  "<<operatiiContact->obtineZiDeNastereDupaFiltru()<<endl;
                    cout<<"  Tel. Dom.:        "<<operatiiContact->obtineTelDomDupaFiltru()<<endl;
                    cout<<"  Tel. Mob.:        "<<operatiiContact->obtineTelMobDupaFiltru()<<endl;
                    cout<<"  Email:            "<<operatiiContact->obtineEmailDupaFiltru()<<endl;
                    cout<<"  Categoria:        ";
                    if( operatiiContact->obtineTipContactPrietenDupaFiltru() )
                        cout<<"Prieten"<<endl<<endl;
                    if( operatiiContact->obtineTipContactServiciuDupaFiltru() )
                        cout<<"Serviciu"<<endl<<endl;
                    if( operatiiContact->obtineTipContactFamilieDupaFiltru() )
                        cout<<"Familie"<<endl<<endl;
                    operatiiContact->listaFiltrataMoveToNextElement();
                    break;
                case 3:
                    cout<<"|"<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
                    cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<"|    Editeaza     Toata Informatia    [Sterge]"<<endl;
                    operatiiContact->listaFiltrataMoveToNextElement();
                    break;
                }
            }
            else
            {
                cout<<" "<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
                cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<endl;
                operatiiContact->listaFiltrataMoveToNextElement();
            }
        }
        else
        {
            cout<<" "<<operatiiContact->obtineNumeCuFiltru(advancedFilter, stare->obtineStareFiltru())<<" ";
            cout<<" "<<operatiiContact->obtinePrenumeDupaNumeCuFiltru()<<endl;
            operatiiContact->listaFiltrataMoveToNextElement();
        }
    }

    /*if(stare->obtineStareMeniuPrincipal() == 4)
    switch(stare->obtineStareOptiuneCont())
    {
    case 0:
//        cout<<"["<<z->contact.obtineNume()<<" "<<z->contact.obtinePrenume()<<"]";
        //if()
        cout<<"["<<operatiiContact->obtineNume()<<" "<<operatiiContact->obtinePrenume()<<"]";
        cout<<"   Editeaza    Toata Informatia    Sterge"<<endl;
        break;
    case 1:
        cout<<"|"<<operatiiContact->obtineNume()<<" "<<operatiiContact->obtinePrenume()<<"|";
        cout<<"  [Editeaza]   Toata Informatia    Sterge"<<endl;
        //de agaugat subMeniul Editeaza
        break;
    case 2:
        cout<<"|"<<operatiiContact->obtineNume()<<" "<<operatiiContact->obtinePrenume()<<"|";
        cout<<"   Editeaza   [Toata Informatia]   Sterge"<<endl;
        break;
    case 3:
        cout<<"|"<<operatiiContact->obtineNume()<<" "<<operatiiContact->obtinePrenume()<<"|";
        cout<<"   Editeaza    Toata Informatia   [Sterge]"<<endl;
        break;
    default:
        break;
    }
    else
    {}*/
}

void Interfata::displayNavigheazaContacte(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 3:
        cout<<"[Navigheaza lista cu Contacte]"<<endl<<endl;
        break;
    case 4:
        cout<<"|Navigheaza lista cu Contacte|"<<endl<<endl;
        break;
    default:
        cout<<" Navigheaza lista cu Contacte"<<endl<<endl;
        break;
    }
}

void Interfata::displayAdaugaUnContact(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 2:
        cout<<"[Adauga un contact]"<<endl;
        break;
    default:
        cout<<" Adauga un contact"<<endl;
        break;
    }
}

void Interfata::displayAdvancedFilter(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 1:
        cout<<"[Filtrare avansata(dupa Nume/Prenume)]: "<<this->advancedFilter<<endl;
        break;
    default:
        cout<<" Filtrare avansata(dupa Nume/Prenume) : "<<this->advancedFilter<<endl;
        break;
    }
}

void Interfata::displayFilter(void)
{
    switch(stare->obtineStareMeniuPrincipal())
    {
    case 0:
        switch(stare->obtineStareFiltru())
        {
        case 0:
            cout<<"|Filtrati dupa tipul de contacte|:  [Prieteni]   Serviciu   Familie   Toate"<<endl;
            break;
        case 1:
            cout<<"|Filtrati dupa tipul de contacte|:   Prieteni  [Serviciu]   Familie   Toate"<<endl;
            break;
        case 2:
            cout<<"|Filtrati dupa tipul de contacte|:   Prieteni   Serviciu  [Familie]   Toate"<<endl;
            break;
        case 3:
            cout<<"|Filtrati dupa tipul de contacte|:   Prieteni   Serviciu   Familie  [Toate]"<<endl;
            break;
        }
        break;
    default:
        switch(stare->obtineStareFiltru())
        {
        case 0:
            cout<<" Filtrati dupa tipul de contacte :  [Prieteni]   Serviciu   Familie   Toate"<<endl;
            break;
        case 1:
            cout<<" Filtrati dupa tipul de contacte :   Prieteni  [Serviciu]   Familie   Toate"<<endl;
            break;
        case 2:
            cout<<" Filtrati dupa tipul de contacte :   Prieteni   Serviciu  [Familie]   Toate"<<endl;
            break;
        case 3:
            cout<<" Filtrati dupa tipul de contacte :   Prieteni   Serviciu   Familie  [Toate]"<<endl;
            break;
        }
        break;
    }
}

#endif // INTERFATA_H