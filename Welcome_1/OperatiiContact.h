/* 
 * File:   OperatiiContact.h
 * Author: sboros
 *
 * Created on October 24, 2013, 9:26 AM
 */

#ifndef OPERATIICONTACT_H
#define OPERATIICONTACT_H

#include "Contact.h"
#include <fstream>

using namespace std;

#pragma pack(push)
#pragma pack(1)

//Controller - aceasta clasa/biblioteca raspunde de toate operatiile asupra datelor
//( adaugarea unui contact, stergerea unui contact ... )

class OperatiiContact
{
    struct listaContact
    {
        Contact contact; //Model - aici se afla datele principale
        listaContact *next, *prev;
    } *prim, *q, *p, *z, *x;
    //prim - nu il mut pentru ca e primul element
    //p - e ultimul
    //q - se foloseste la adaugaContact ca element de legatura| nu tre schimbat
    //z - se foloseste ca element de legatura pentru stergereCuFiltru();
    //x - il folosesc la returnarea unui User aplicand Filtru
    //temp - se foloseste la
    int nrDeElemente, pozInitiala;
public:
    OperatiiContact(){ prim= 0; nrDeElemente = 0; pozInitiala = 0; }
    ~OperatiiContact()
    {
        while(prim!=NULL)
        {
            q=prim;
            prim=prim->next;
            delete q;
        }
    }

    //Adauga un Contact nou
    void adaugaContact(String nume, String prenume, String adresa,
                       String ziDeNastere, String tel_dom,
                       String tel_mob, String email, short tipContact);

    //Functii de modificare/obtinere a datelor
    inline String obtineNume(void) const;
    String obtineNumeCuFiltru(String, short);
    inline String obtineNumeDupaFiltru(void) const;
    inline String obtinePrenume(void) const;
    inline String obtinePrenumeDupaNumeCuFiltru() const;
    inline String obtineAdresa(void) const;
    inline String obtineAdresaDupaFiltru(void) const;
    inline String obtineZiDeNastere(void) const;
    inline String obtineZiDeNastereDupaFiltru(void) const;
    inline String obtineTelDom(void) const;
    inline String obtineTelDomDupaFiltru(void) const;
    inline String obtineTelMob(void) const;
    inline String obtineTelMobDupaFiltru(void) const;
    inline String obtineEmail(void) const;
    inline String obtineEmailDupaFiltru(void) const;

    inline String modificaNume(String);
    inline String modificaPrenume(String);
    inline String modificaAdresa(String);
    inline String modificaZiDeNastere(String);
    inline String modificaTelDom(String);
    inline String modificaTelMob(String);
    inline String modificaEmail(String);
    inline String modificaTipContactPrieten(bool);
    inline String modificaTipContactServiciu(bool);
    inline String modificatipContactFamilie(bool);

    inline bool obtineTipContactPrietenDupaFiltru(void) const;
    inline bool obtineTipContactServiciuDupaFiltru(void) const;
    inline bool obtineTipContactFamilieDupaFiltru(void) const;

    int obtineNrDeElementeCuFiltru(String, short);
    inline int getIfIsNull(void);

    inline int obtineNrDeElemente(void) const
    {
        return this->nrDeElemente;
    }

    inline void incrementeazaNrDeElemente(void);
    inline void decrementeazaNrDeElemente(void);
    inline void listaFiltrataResetToPrim(void);
    inline void listaFiltrataMoveToNextElement(void);

    void stergeContact();

    inline char schimbaInteractivNume();
    inline char schimbaInteractivPrenume();
    inline char schimbaInteractivAdresa();
    inline char schimbaInteractivZiDeNastere();
    inline char schimbaInteractivTelDom();
    inline char schimbaInteractivTelMob();
    inline char schimbaIntercativEmail();

    void salveazaDatele(char [], short);
    void incarcaDatele(char []);

    void sorteaza();

};

void OperatiiContact::sorteaza()
{
    listaContact *temp = prim, *temp2;

    while(temp != 0)
    {
        temp2 = prim;
        while( temp2 != temp )
        {
            if( temp2->contact.obtineNume() > temp->contact.obtineNume() )
            {
                String aux;
                bool aux2;
                aux = temp->contact.obtineNume();
                temp->contact.modificaNume(temp2->contact.obtineNume());
                temp2->contact.modificaNume(aux);

                aux = temp->contact.obtinePrenume();
                temp->contact.modificaPrenume(temp2->contact.obtinePrenume());
                temp2->contact.modificaPrenume(aux);

                aux = temp->contact.obtineAdresa();
                temp->contact.modificaAdresa(temp2->contact.obtineAdresa());
                temp2->contact.modificaAdresa(aux);

                aux = temp->contact.obtineZiDeNastere();
                temp->contact.modificaZiDeNastere(temp2->contact.obtineZiDeNastere());
                temp2->contact.modificaZiDeNastere(aux);

                aux = temp->contact.obtineTelDom();
                temp->contact.modificaTelDom(temp2->contact.obtineTelDom());
                temp2->contact.modificaTelDom(aux);

                aux = temp->contact.obtineTelMob();
                temp->contact.modificaTelMob(temp2->contact.obtineTelMob());
                temp2->contact.modificaTelMob(aux);

                aux = temp->contact.obtineEmail();
                temp->contact.modificaEmail(temp2->contact.obtineEmail());
                temp2->contact.modificaEmail(aux);

                aux2 = temp->contact.obtineTipContactPrieten();
                temp->contact.modificaTipContactPrieten(temp2->contact.obtineTipContactPrieten());
                temp2->contact.modificaTipContactPrieten(aux2);

                aux2 = temp->contact.obtineTipContactFamilie();
                temp->contact.modificaTipContactFamilie(temp2->contact.obtineTipContactFamilie());
                temp2->contact.modificaTipContactFamilie(aux2);

                aux2 = temp->contact.obtineTipContactServiciu();
                temp->contact.modificaTipContactServiciu(temp2->contact.obtineTipContactServiciu());
                temp2->contact.modificaTipContactServiciu(aux2);
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}

void OperatiiContact::incarcaDatele(char numeFis[30])
{
    ifstream f(numeFis);

    String nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email;
    short tipContact;

    char sirul[30];
    int l = 0; //lungimea sirului
    int nrElem = 0; //Contoleaza care element se citeste la moment
    int check = 0; //Controleaza daca s-a citit ultima variabila

    while(!f.eof())
    {
        check = 0;
        if( nrElem < 7 )
        {
            f>>sirul[l];
            switch( nrElem )
            {
            case 0:
                if( sirul[l] != '|' )
                    nume += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 1:
                if( sirul[l] != '|' )
                    prenume += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 2:
                if( sirul[l] != '|' )
                    adresa += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 3:
                if( sirul[l] != '|' )
                    ziDeNastere += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 4:
                if( sirul[l] != '|' )
                    tel_dom += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 5:
                if( sirul[l] != '|' )
                    tel_mob += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            case 6:
                if( sirul[l] != '|' )
                    email += sirul[l];
                else
                {
                    nrElem++;
                    sirul[0] = 0;
                }
                break;
            default:
                break;
            }

            if( sirul[l] != '|' )
                l++;
            else
                l = 0;
        }
        else
        {
            f>>tipContact;
            nrElem = 0;
            l = 0;
            check = 1;
        }

        if( check )
        {
            adaugaContact(nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email, tipContact);
            nume.reinitializeaza();
            prenume.reinitializeaza();
            adresa.reinitializeaza();
            ziDeNastere.reinitializeaza();
            tel_dom.reinitializeaza();
            tel_mob.reinitializeaza();
            email.reinitializeaza();
        }
    }

    f.close();
}

void OperatiiContact::salveazaDatele(char numeFis[30], short stareFiltru)
{
    ofstream f(numeFis);

    listaContact *temp = prim;
    while( temp != 0 )
    {
        f<<temp->contact.obtineNume()<<"|"<<temp->contact.obtinePrenume()<<"|"<<temp->contact.obtineAdresa()<<"|"<<temp->contact.obtineZiDeNastere();
        f<<"|"<<temp->contact.obtineTelDom()<<"|"<<temp->contact.obtineTelMob()<<"|"<<temp->contact.obtineEmail()<<"|";

        if( temp->contact.obtineTipContactPrieten() || temp->contact.obtineTipContactServiciu() || temp->contact.obtineTipContactFamilie())
        {
            if( temp->contact.obtineTipContactPrieten() )
                f<<"1"<<endl;
            if( temp->contact.obtineTipContactServiciu() )
                f<<"2"<<endl;
            if( temp->contact.obtineTipContactFamilie() )
                f<<"3"<<endl;
        }
        else
            f<<"4"<<endl;
        temp = temp->next;
    }

    f.close();
}

inline char OperatiiContact::schimbaInteractivNume()
{
    return this->x->contact.schimbaInteractivNume();
}

inline char OperatiiContact::schimbaInteractivPrenume()
{
    return this->x->contact.schimbaInteractivPrenume();
}

inline char OperatiiContact::schimbaInteractivAdresa()
{
    return this->x->contact.schimbaInteractivAdresa();
}

inline char OperatiiContact::schimbaInteractivZiDeNastere()
{
    return this->x->contact.schimbaInteractivZiDeNastere();
}

inline char OperatiiContact::schimbaInteractivTelDom()
{
    return this->x->contact.schimbaInteractivTelDom();
}

inline char OperatiiContact::schimbaInteractivTelMob()
{
    return this->x->contact.schimbaInteractivTelMob();
}

inline char OperatiiContact::schimbaIntercativEmail()
{
    return this->x->contact.schimbaInteractivEmail();
}

inline String OperatiiContact::modificatipContactFamilie(bool familie)
{
    this->x->contact.modificaTipContactFamilie(familie);
}

inline String OperatiiContact::modificaTipContactServiciu(bool serviciu)
{
    this->x->contact.modificaTipContactServiciu(serviciu);
}

inline String OperatiiContact::modificaTipContactPrieten(bool prieten)
{
    this->x->contact.modificaTipContactPrieten(prieten);
}

inline String OperatiiContact::modificaNume(String nume)
{
    this->x->contact.modificaNume(nume);
}

inline String OperatiiContact::modificaPrenume(String prenume)
{
    this->x->contact.modificaPrenume(prenume);
}

inline String OperatiiContact::modificaAdresa(String adresa)
{
    this->x->contact.modificaAdresa(adresa);
}

inline String OperatiiContact::modificaZiDeNastere(String ziDeNastere)
{
    this->x->contact.modificaZiDeNastere(ziDeNastere);
}

inline String OperatiiContact::modificaTelDom(String telDom)
{
    this->x->contact.modificaTelDom(telDom);
}

inline String OperatiiContact::modificaTelMob(String telMob)
{
    this->x->contact.modificaTelMob(telMob);
}

inline String OperatiiContact::modificaEmail(String email)
{
    this->x->contact.modificaEmail(email);
}


bool OperatiiContact::obtineTipContactPrietenDupaFiltru(void) const
{
    return x->contact.obtineTipContactPrieten();
}

bool OperatiiContact::obtineTipContactServiciuDupaFiltru(void) const
{
    return x->contact.obtineTipContactServiciu();
}

bool OperatiiContact::obtineTipContactFamilieDupaFiltru(void) const
{
    return x->contact.obtineTipContactFamilie();
}

inline int OperatiiContact::getIfIsNull(void)
{
    if( x == 0 )
        return 1;
    else
        return 0;
}

int OperatiiContact::obtineNrDeElementeCuFiltru(String advancedFilter, short tipContact)
{
    int nr = 0;
    listaContact *temp = prim;
    while(temp != 0)
    {
        if( tipContact == 0 )
            if( (cauta_cuvintNoCaseSensitive(temp->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(temp->contact.obtinePrenume(), advancedFilter) ) && temp->contact.obtineTipContactPrieten() ) //Controleaza tipContact + InteractiveFiltre
                nr++;
        if( tipContact == 1 )
            if( (cauta_cuvintNoCaseSensitive(temp->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(temp->contact.obtinePrenume(), advancedFilter) ) && temp->contact.obtineTipContactServiciu() ) //Controleaza tipContact + InteractiveFiltre
                nr++;
        if( tipContact == 2 )
            if( (cauta_cuvintNoCaseSensitive(temp->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(temp->contact.obtinePrenume(), advancedFilter) ) && temp->contact.obtineTipContactFamilie() ) //Controleaza tipContact + InteractiveFiltre
                nr++;
        if( tipContact == 3 )
            if( cauta_cuvintNoCaseSensitive(temp->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(temp->contact.obtinePrenume(), advancedFilter) )
                nr++;
        temp = temp->next;
    }
    return nr;
}

inline void OperatiiContact::listaFiltrataMoveToNextElement(void)
{
    if(this->x != 0)
    {
        this->x = this->x->next;
    }
}

inline void OperatiiContact::listaFiltrataResetToPrim(void)
{
    this->x = this->prim;
}

String OperatiiContact::obtineNumeCuFiltru(String advancedFilter, short tipContact)
{
    while(x != 0)
    {
        if( tipContact == 0 )
            if( (cauta_cuvintNoCaseSensitive(x->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(x->contact.obtinePrenume(), advancedFilter) ) && x->contact.obtineTipContactPrieten() ) //Controleaza tipContact + InteractiveFiltre
                return x->contact.obtineNume();
        if( tipContact == 1 )
            if( (cauta_cuvintNoCaseSensitive(x->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(x->contact.obtinePrenume(), advancedFilter) ) && x->contact.obtineTipContactServiciu() ) //Controleaza tipContact + InteractiveFiltre
                return x->contact.obtineNume();
        if( tipContact == 2 )
            if( (cauta_cuvintNoCaseSensitive(x->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(x->contact.obtinePrenume(), advancedFilter) ) && x->contact.obtineTipContactFamilie() ) //Controleaza tipContact + InteractiveFiltre
                return x->contact.obtineNume();
        if( tipContact == 3 )
            if( cauta_cuvintNoCaseSensitive(x->contact.obtineNume(), advancedFilter) || cauta_cuvintNoCaseSensitive(x->contact.obtinePrenume(), advancedFilter) )
                return x->contact.obtineNume();
        x = x->next;
    }
}

inline String OperatiiContact::obtinePrenumeDupaNumeCuFiltru() const
{
    if( x != 0)
        return x->contact.obtinePrenume();
}

inline String OperatiiContact::obtineNume(void) const
{
    if(z != 0)
        return z->contact.obtineNume();
}

inline String OperatiiContact::obtineNumeDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineNume();
}

inline String OperatiiContact::obtinePrenume(void) const
{
    if(z != 0)
        return z->contact.obtinePrenume();
}

inline String OperatiiContact::obtineAdresa(void) const
{
    if(z != 0)
        return z->contact.obtineAdresa();
}

inline String OperatiiContact::obtineAdresaDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineAdresa();
}

inline String OperatiiContact::obtineZiDeNastere(void) const
{
    if(z != 0)
        return z->contact.obtineZiDeNastere();
}

inline String OperatiiContact::obtineZiDeNastereDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineZiDeNastere();
}

inline String OperatiiContact::obtineTelDom(void) const
{
    if(z != 0)
        return z->contact.obtineTelDom();
}

inline String OperatiiContact::obtineTelDomDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineTelDom();
}

inline String OperatiiContact::obtineTelMob(void) const
{
    if(z != 0)
        return z->contact.obtineTelMob();
}

inline String OperatiiContact::obtineTelMobDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineTelMob();
}

inline String OperatiiContact::obtineEmail(void) const
{
    if(z != 0)
        return z->contact.obtineEmail();
}

inline String OperatiiContact::obtineEmailDupaFiltru(void) const
{
    if(x != 0)
        return x->contact.obtineEmail();
}


inline void OperatiiContact::incrementeazaNrDeElemente(void)
{
    this->nrDeElemente++;
}

inline void OperatiiContact::decrementeazaNrDeElemente(void)
{
    this->nrDeElemente--;
}

void OperatiiContact::stergeContact()
{
    if(x != 0)
    {
        if(x == prim)
        {
            x = prim;
            prim = prim->next;
            if( prim != 0)
                prim->prev = 0;
            delete x;
            x = prim;
            nrDeElemente--;
        }
        else
        {
            listaContact *temp = x->prev;
            temp->next = x->next;
            if( x->next != 0 )
                x->next->prev = temp;
            temp = x;
            x = x->next;
            delete temp;
            nrDeElemente--;
            if( nrDeElemente == 1)
            {
                q = prim;
            }
        }
    }
}

void OperatiiContact::adaugaContact(String nume, String prenume, String adresa,
                                    String ziDeNastere, String tel_dom,
                                    String tel_mob, String email, short tipContact)
{
    if(prim == 0)
    {
        prim = new listaContact;
        prim->contact.modificaNume(nume);
        prim->contact.modificaPrenume(prenume);
        prim->contact.modificaAdresa(adresa);
        prim->contact.modificaZiDeNastere(ziDeNastere);
        prim->contact.modificaTelDom(tel_dom);
        prim->contact.modificaTelMob(tel_mob);
        prim->contact.modificaEmail(email);
        switch(tipContact)
        {
        case 1:
            prim->contact.modificaTipContactPrieten(1);
            prim->contact.modificaTipContactServiciu(0);
            prim->contact.modificaTipContactFamilie(0);
            break;
        case 2:
            prim->contact.modificaTipContactPrieten(0);
            prim->contact.modificaTipContactServiciu(1);
            prim->contact.modificaTipContactFamilie(0);
            break;
        case 3:
            prim->contact.modificaTipContactPrieten(0);
            prim->contact.modificaTipContactServiciu(0);
            prim->contact.modificaTipContactFamilie(1);
            break;
        case 4:
            prim->contact.modificaTipContactPrieten(0);
            prim->contact.modificaTipContactServiciu(0);
            prim->contact.modificaTipContactFamilie(0);
            break;
        default:
            break;
        }
        prim->next=NULL;
        prim->prev=NULL;
        z=x=q=prim;
        this->nrDeElemente++;
    }
    else
    {
        p=new listaContact;
        p->contact.modificaNume(nume);
        p->contact.modificaPrenume(prenume);
        p->contact.modificaAdresa(adresa);
        p->contact.modificaZiDeNastere(ziDeNastere);
        p->contact.modificaTelDom(tel_dom);
        p->contact.modificaTelMob(tel_mob);
        p->contact.modificaEmail(email);
        switch(tipContact)
        {
        case 1:
            p->contact.modificaTipContactPrieten(1);
            p->contact.modificaTipContactServiciu(0);
            p->contact.modificaTipContactFamilie(0);
            break;
        case 2:
            p->contact.modificaTipContactPrieten(0);
            p->contact.modificaTipContactServiciu(1);
            p->contact.modificaTipContactFamilie(0);
            break;
        case 3:
            p->contact.modificaTipContactPrieten(0);
            p->contact.modificaTipContactServiciu(0);
            p->contact.modificaTipContactFamilie(1);
            break;
        case 4:
            p->contact.modificaTipContactPrieten(0);
            p->contact.modificaTipContactServiciu(0);
            p->contact.modificaTipContactFamilie(0);
            break;
        default:
            break;
        }
        p->next=NULL;
        p->prev=q;
        q->next=p;
        q = p;
        this->nrDeElemente++;
    }
}

#pragma pack(pop)

#endif // OPERATIICONTACT_H