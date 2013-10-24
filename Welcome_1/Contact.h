/* 
 * File:   Contact.h
 * Author: sboros
 *
 * Created on October 23, 2013, 5:23 PM
 */

#ifndef CONTACT_H
#define CONTACT_H

#include "String.h"
#include "TipContact.h"

//Model - aici se afla datele principale

class Contact
{
    String nume, prenume, adresa, ziDeNastere, tel_dom, tel_mob, email;
    TipContact *tipContact;

public:

    Contact(){ tipContact=new TipContact; }
    ~Contact(){ delete tipContact; }

    //Functii de modificare si obtinere a datelor
    inline String obtineNume(void) const;
    inline String obtinePrenume(void) const;
    inline String obtineAdresa(void) const;
    inline String obtineZiDeNastere(void) const;
    inline String obtineTelDom(void) const;
    inline String obtineTelMob(void) const;
    inline String obtineEmail(void) const;
    inline bool obtineTipContactPrieten(void) const;
    inline bool obtineTipContactServiciu(void) const;
    inline bool obtineTipContactFamilie(void) const;

    inline void modificaNume(String);
    inline void modificaPrenume(String);
    inline void modificaAdresa(String);
    inline void modificaZiDeNastere(String);
    inline void modificaTelDom(String);
    inline void modificaTelMob(String);
    inline void modificaEmail(String);

    inline void modificaNumeChar(char*);
    inline void modificaPrenumeChar(char*);
    inline void modificaAdresaChar(char*);
    inline void modificaZiDeNastereChar(char*);
    inline void modificaTelDomChar(char*);
    inline void modificaTelMobChar(char*);
    inline void modificaEmailChar(char*);

    inline void modificaTipContactPrieten(bool);
    inline void modificaTipContactServiciu(bool);
    inline void modificaTipContactFamilie(bool);

    char schimbaInteractivNume(void);
    char schimbaInteractivPrenume(void);
    char schimbaInteractivAdresa(void);
    char schimbaInteractivZiDeNastere(void);
    char schimbaInteractivTelDom(void);
    char schimbaInteractivTelMob(void);
    char schimbaInteractivEmail(void);

};

char Contact::schimbaInteractivNume(void)
{
    char k;
    k = nume.passReadNoOutputLitere();
    return k;
}

char Contact::schimbaInteractivPrenume(void)
{
    char k;
    k = prenume.passReadNoOutputLitere();
    return k;
}

char Contact::schimbaInteractivAdresa(void)
{
    char k;
    k = adresa.passReadNoOutput();
    return k;
}

char Contact::schimbaInteractivZiDeNastere(void)
{
    char k;
    k = ziDeNastere.passReadNoOutput();
    return k;
}

char Contact::schimbaInteractivTelDom(void)
{
    char k;
    k = tel_dom.passReadNoOutput();
    return k;
}

char Contact::schimbaInteractivTelMob(void)
{
    char k;
    k = tel_mob.passReadNoOutput();
    return k;
}

char Contact::schimbaInteractivEmail(void)
{
    char k;
    k = email.passReadNoOutput();
    return k;
}

inline String Contact::obtineNume(void) const
{
    return this->nume;
}

inline String Contact::obtinePrenume(void) const
{
    return this->prenume;
}

inline String Contact::obtineAdresa(void) const
{
    return this->adresa;
}

inline String Contact::obtineTelDom(void) const
{
    return this->tel_dom;
}

inline String Contact::obtineTelMob(void) const
{
    return this->tel_mob;
}

inline String Contact::obtineEmail(void ) const
{
    return this->email;
}

inline String Contact::obtineZiDeNastere(void) const
{
    return this->ziDeNastere;
}

inline bool Contact::obtineTipContactPrieten(void) const
{
    return this->tipContact->obtineTipPrieten();
}

inline bool Contact::obtineTipContactServiciu(void) const
{
    return this->tipContact->obtineTipServiciu();
}

inline bool Contact::obtineTipContactFamilie(void) const
{
    return this->tipContact->obtineTipFamilie();
}

inline void Contact::modificaNume(String nume)
{
    this->nume=nume;
}

inline void Contact::modificaPrenume(String prenume)
{
    this->prenume=prenume;
}

inline void Contact::modificaAdresa(String adresa)
{
    this->adresa=adresa;
}

inline void Contact::modificaTelDom(String tel_dom)
{
    this->tel_dom=tel_dom;
}

inline void Contact::modificaTelMob(String tel_mob)
{
    this->tel_mob=tel_mob;
}

inline void Contact::modificaEmail(String email)
{
    this->email=email;
}

inline void Contact::modificaZiDeNastere(String ziDeNastere)
{
    this->ziDeNastere=ziDeNastere;
}


inline void Contact::modificaNumeChar(char* nume)
{
    this->nume = nume;
}

inline void Contact::modificaPrenumeChar(char* prenume)
{
    this->prenume = prenume;
}

inline void Contact::modificaAdresaChar(char* adresa)
{
    this->adresa = adresa;
}

inline void Contact::modificaTelDomChar(char* tel_dom)
{
    this->tel_dom = tel_dom;
}

inline void Contact::modificaTelMobChar(char* tel_mob)
{
    this->tel_mob = tel_mob;
}

inline void Contact::modificaEmailChar(char* email)
{
    this->email = email;
}

inline void Contact::modificaZiDeNastereChar(char* ziDeNastere)
{
    this->ziDeNastere = ziDeNastere;
}


inline void Contact::modificaTipContactPrieten(bool prieten)
{
    this->tipContact->modificaTipPrieten(prieten);
}

inline void Contact::modificaTipContactServiciu(bool serviciu)
{
    this->tipContact->modificaTipServiciu(serviciu);
}

inline void Contact::modificaTipContactFamilie(bool familie)
{
    this->tipContact->modificaTipFamilie(familie);
}

#endif // CONTACT_H
