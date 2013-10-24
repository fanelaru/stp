/* 
 * File:   Stare.h
 * Author: sboros
 *
 * Created on October 24, 2013, 9:27 AM
 */

#ifndef STARE_H
#define STARE_H

//Model - aceasta clasa/biblioteca memoreaza pozitionarea noastra in Meniu
//si inca citeva functii adaugatoare

class Stare
{
    short stareFiltru, stareMeniuPrincipal,
    starePozInLista, stareOptiuneCont, stareOptiuneContEdit,
    stareAutoSalvare, stareAdaugaContact, stareAdaugaContactOptiuniTip, pozMaxLista,
    stareModificari, stareModificariPentruSort;

public:

    Stare()
    {
        stareFiltru=3; //Indica ce Filtru e selectat in Meniu - pe orizontala
        stareMeniuPrincipal=0; //Indica unde ma aflu in Meniul Principal - pe verticala
        starePozInLista=0; //Pozitia in Lista
        stareOptiuneCont=0; //...
        stareOptiuneContEdit=0;
        stareAutoSalvare=0;
        stareAdaugaContact=0;
        stareAdaugaContactOptiuniTip=0;
        stareModificari=0;
        stareModificariPentruSort = 0;
        pozMaxLista=0;
    }

    //Functii de obtinere si modifcare a datelor
    inline short obtineStareFiltru(void) const;
    inline short obtineStareMeniuPrincipal(void) const;
    inline short obtineStarePozInLista(void) const;
    inline short obtineStareOptiuneCont(void) const;
    inline short obtineStareOptiuneContEdit(void) const;
    inline short obtineStareAutoSalvare(void) const;
    inline short obtineStareAdaugaContact(void) const;
    inline short obtineStareAdaugaContactOptiuniTip(void) const;
    inline short obtineStareModificari(void) const;
    inline short obtinePozMaxLista(void) const;
    inline short obtineStareModificariPentruSort(void) const;

    inline void modificaStareFiltru(short);
    inline void modificaStareMeniuPrincipal(short);
    inline void modificaStarePozInLista(short);
    inline void modificaStareOptiuneCont(short);
    inline void modificaStareOptiuneContEdit(short);
    inline void modificaStareAutoSalvare(short);
    inline void modificaStareAdaugaContact(short);
    inline void modificaStareAdaugaContactOptiuniTip(short);
    inline void modificaStareModificari(short);
    inline void modificaPozMaxLista(short);
    inline void modificaStareModificariPentruSort(short);

    inline void incrementeazaStareFiltru(void);
    inline void incrementeazaStareMeniuPrincipal(void);
    inline void incrementeazaStarePozInLista(void);//
    inline void incrementeazaStareOptiuneCont(void);
    inline void incrementeazaStareOptiuneContEdit(void);//tre Schimbat
    inline void incrementeazaStareAutoSalvare(void);
    inline void incrementeazaStareAdaugaContact(void);
    inline void incrementeazaStareAdaugaContactOptiuniTip(void);
    inline void incrementeazaPozMaxLista(void);

    inline void decrementeazaStareFiltru(void);
    inline void decrementeazaStareMeniuPrincipal(void);
    inline void decrementeazaStarePozInLista(void);
    //aratand cat e minimum de decrementat in parametri formali
    inline void decrementeazaStareOptiuneCont(void);
    inline void decrementeazaStareOptiuneContEdit(void);
    inline void decrementeazaStareAutoSalvare(void);
    inline void decrementeazaStareAdaugaContact(void);
    inline void decrementeazaStareAdaugaContactOptiuniTip(void);
    inline void decrementeazaPozMaxLista(void);

    inline void switchStareAutoSalvare(void);

};

inline short Stare::obtineStareModificariPentruSort() const
{
    return this->stareModificariPentruSort;
}

inline void Stare::modificaStareModificariPentruSort(short stareModificariPentruSort)
{
    this->stareModificariPentruSort = stareModificariPentruSort;
}

inline void Stare::switchStareAutoSalvare(void)
{
    if(this->stareAutoSalvare == 1)
        this->stareAutoSalvare=0;
    else
        this->stareAutoSalvare=1;
}


//Decrementeaza--------------------
inline void Stare::decrementeazaPozMaxLista(void)
{
    this->pozMaxLista--;
}

inline void Stare::decrementeazaStareAdaugaContactOptiuniTip(void)
{
    if(this->stareAdaugaContactOptiuniTip == 0)
        this->stareAdaugaContactOptiuniTip=3;
    else
        this->stareAdaugaContactOptiuniTip--;
}

inline void Stare::decrementeazaStareAdaugaContact(void)
{
    if(this->stareAdaugaContact == 0)
        this->stareAdaugaContact=8;
    else
        this->stareAdaugaContact--;
}

inline void Stare::decrementeazaStareAutoSalvare(void)
{
    if(this->stareAutoSalvare == 0)
        this->stareAutoSalvare=1;
    else
        this->stareAutoSalvare--;
}

inline void Stare::decrementeazaStarePozInLista(void)
{
    if( starePozInLista == 0 )
        this->starePozInLista = pozMaxLista;
    else
        this->starePozInLista--;
}

inline void Stare::decrementeazaStareOptiuneCont(void)
{
    if(this->stareOptiuneCont == 0)
        this->stareOptiuneCont=3;
    else
        this->stareOptiuneCont--;
}

inline void Stare::decrementeazaStareOptiuneContEdit(void)
{
    if(this->stareOptiuneContEdit == 0)
        this->stareOptiuneContEdit=8;
    else
        this->stareOptiuneContEdit--;
}

inline void Stare::decrementeazaStareFiltru(void)
{
    if(this->stareFiltru == 0)
        this->stareFiltru=3;
    else
        this->stareFiltru--;
}

inline void Stare::decrementeazaStareMeniuPrincipal(void)
{
    if(this->stareMeniuPrincipal == 0)
        this->stareMeniuPrincipal=9;
    else
        this->stareMeniuPrincipal--;
}

//Incrementeaza------------------------
inline void Stare::incrementeazaPozMaxLista(void)
{
    this->pozMaxLista++;
}

inline void Stare::incrementeazaStareAdaugaContactOptiuniTip(void)
{
    if(this->stareAdaugaContactOptiuniTip == 3)
        this->stareAdaugaContactOptiuniTip=0;
    else
        this->stareAdaugaContactOptiuniTip++;
}

inline void Stare::incrementeazaStareAdaugaContact(void)
{
    if(this->stareAdaugaContact == 8)
        this->stareAdaugaContact=0;
    else
        this->stareAdaugaContact++;
}

inline void Stare::incrementeazaStareAutoSalvare(void)
{
    if(this->stareAutoSalvare == 1)
        this->stareAutoSalvare=0;
    else
        this->stareAutoSalvare++;
}

inline void Stare::incrementeazaStarePozInLista(void)
{
    if( starePozInLista == pozMaxLista )
        this->starePozInLista = 0;
    else
        this->starePozInLista++;
}

inline void Stare::incrementeazaStareOptiuneCont(void)
{
    if(this->stareOptiuneCont == 3)
        this->stareOptiuneCont=0;
    else
        this->stareOptiuneCont++;
}

inline void Stare::incrementeazaStareOptiuneContEdit(void)
{
    if(this->stareOptiuneContEdit == 8)
        this->stareOptiuneContEdit=0;
    else
        this->stareOptiuneContEdit++;
}

inline void Stare::incrementeazaStareFiltru(void)
{
    if(this->stareFiltru == 3)
        this->stareFiltru=0;
    else
        this->stareFiltru++;
}

inline void Stare::incrementeazaStareMeniuPrincipal(void)
{
    if(this->stareMeniuPrincipal == 9)
        this->stareMeniuPrincipal=0;
    else
        this->stareMeniuPrincipal++;
}

//Obtine----------------------
inline short Stare::obtineStareModificari(void) const
{
    return this->stareModificari;
}

inline short Stare::obtinePozMaxLista(void) const
{
    return this->pozMaxLista;
}

inline short Stare::obtineStareAdaugaContactOptiuniTip(void) const
{
    return this->stareAdaugaContactOptiuniTip;
}

inline short Stare::obtineStareAdaugaContact(void) const
{
    return this->stareAdaugaContact;
}

inline short Stare::obtineStareAutoSalvare(void) const
{
    return this->stareAutoSalvare;
}

inline short Stare::obtineStarePozInLista(void) const
{
    return this->starePozInLista;
}

inline short Stare::obtineStareOptiuneCont(void) const
{
    return this->stareOptiuneCont;
}

inline short Stare::obtineStareOptiuneContEdit(void) const
{
    return this->stareOptiuneContEdit;
}

inline short Stare::obtineStareFiltru(void) const
{
    return this->stareFiltru;
}

inline short Stare::obtineStareMeniuPrincipal(void) const
{
    return this->stareMeniuPrincipal;
}

//Modifica----------------
inline void Stare::modificaStareModificari(short stareModificari)
{
    this->stareModificari=stareModificari;
}

inline void Stare::modificaPozMaxLista(short pozMaxLista)
{
    this->pozMaxLista=pozMaxLista;
}

inline void Stare::modificaStareAdaugaContactOptiuniTip(short stareAdaugaContactOptiuniTip)
{
    this->stareAdaugaContactOptiuniTip=stareAdaugaContactOptiuniTip;
}

inline void Stare::modificaStareAdaugaContact(short stareAdaugaContact)
{
    this->stareAdaugaContact=stareAdaugaContact;
}

inline void Stare::modificaStareAutoSalvare(short stareAutoSalvare)
{
    this->stareAutoSalvare=stareAutoSalvare;
}

inline void Stare::modificaStarePozInLista(short starePozInLista)
{
    this->starePozInLista=starePozInLista;
}

inline void Stare::modificaStareOptiuneCont(short stareOptiuneCont)
{
    this->stareOptiuneCont=stareOptiuneCont;
}

inline void Stare::modificaStareOptiuneContEdit(short stareOptiuneContEdit)
{
    this->stareOptiuneContEdit=stareOptiuneContEdit;
}

inline void Stare::modificaStareFiltru(short modificaInStareFiltru)
{
    this->stareFiltru=modificaInStareFiltru;
}

inline void Stare::modificaStareMeniuPrincipal(short modificaStareMeniuPrincipal)
{
    this->stareMeniuPrincipal=modificaStareMeniuPrincipal;
}

#endif // STARE_H
