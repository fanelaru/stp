/* 
 * File:   String.h
 * Author: sboros
 *
 * Created on October 24, 2013, 9:28 AM
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>

#ifdef __linux__
#include "LinuxGetch.h"
#else
#include <conio.h>
#endif

//Model - Implementarea proprie a bibliotecii <string>
//cu toate functiile necesare pentru realizarea proiectului +
//citeva adaugatoare

using namespace std;

class String
{
public:
    char s[30];
    short error; //1 - e erroare, 0 - nu e erroare
    int l;
    int MaxSize;
public:
    String()
    {
        //s = new char[30];
        s[0] = 0;
        l = 0;
        error = 0;
        MaxSize = 31;
    }

    /*String(int nr)
    {
        s = new char[nr];
        s[0] = 0;
        l = 0;
        error = 0;
        MaxSize = nr + 1;
    }

    ~String()
    {
        delete s;
    }*/

    //operator +
    friend String operator+(String x, String y)
    {
        String z = x;

        for (register int i=0; i<y.l; i++)
            z.s[x.l+i] = y.s[i];

        z.s[x.l+y.l] = 0;
        z.l = x.l+y.l;
        return z;
    }

    friend String operator+(String x, char* y)
    {
        String z = x;
        register int l = 0;
        while(y[l++] != 0);

        for (register int i=0; i<l; i++)
            z.s[x.l+i] = y[i];

        z.s[x.l+l] = 0;
        z.l = x.l+l;
        return z;
    }

    //operator +=
    friend String operator+=(String &x, String y)
    {
        for (register int i=0; i<y.l; i++)
            x.s[x.l+i] = y.s[i];

        x.s[x.l+y.l] = 0;
        x.l = x.l+y.l;
        return x;
    }

    friend String operator+=(String &x,char y[30])
    {
        int l = 0;
        while(y[l++] != 0);

        for(register int i = 0; i < l; i++)
            x.s[x.l+i] = y[i];

        x.s[x.l+l] = 0;
        x.l = x.l+l;
        return x;
    }

    friend String operator+=(String &x, char y)
    {
        x.s[x.l] = y;
        x.l++;
        x.s[x.l] = 0;
        return x;
    }

    //operator - , == , > , <
    String operator-(int b)
    {
        this->l-=b;
        this->s[this->l] = 0;
        return *this;
    }
    friend int operator==(String,String);
    friend int operator>(String, String);
    friend int operator<(String, String);

    //operator =

    String &operator=(String sir)
    {
        for (register int i=0; i<31; i++) this->s[i] = sir.s[i];
        l = sir.l;
        error = sir.error;
        return *this;
    }

    String &operator=(char *sir)
    {
        register int lun=0;
        while(sir[lun++] != 0);

        for (register int i=0; i<31; i++) s[i] = sir[i];
        l = lun;
        error = 0;
        return *this;
    }

    //operator >> , <<

    friend istream & operator>>(istream &is,String &x);
    friend ostream & operator<<(ostream &os,const String &x)
    {
        os<<x.s;
        return os;
    }

    //Citire Filtrata

    void citLitere(); //citeste doar litere - Tre de modificat ==8 cout<<k;
    void citCifre(); //citeste doar cifre - Tre de modificat ==8 cout<<k;

    //Conversii - To DO

    friend char toChar(String);// to do
    char toChar();// to do
    friend char* toCharPointer(String);// to do
    char* toCharPointer(String);// to do
    friend short toShort(String);// to do
    short toShort();// to do
    friend int toInt(String);// to do
    int toInt();// to do
    friend long long int toLong(String);// to do
    long long int toLong();// to do
    friend float toFloat();// to do
    float toFloat();// to do
    friend double toDouble();// to do
    double toDouble();// to do

    //Text Propozitie

    friend void text_tip_prop(String &);
    friend String getText_tip_prop(String);
    void text_tip_prop();
    String getText_tip_prop();

    //Text Mic

    friend void text_tip_mic(String &);
    friend String getText_tip_mic(String);
    void text_tip_mic();
    String getText_tip_mic();

    //Text Mare

    friend void text_tip_mare(String &);
    friend String getText_tip_mare(String);
    void text_tip_mare();
    String getText_tip_mare();

    //Text Titlu

    friend void text_tip_titlu(String &);
    friend String getText_tip_titlu(String);
    void text_tip_titlu();
    String getText_tip_titlu();

    //Text Togle

    friend void text_tip_togle(String &);
    friend String getText_tip_togle(String);
    void text_tip_togle();
    String getText_tip_togle();

    //Replace - Bug - lungimea textului se modifica +
    // + Curatarea codului: Nu e necesara conversia, ex: String y=char* y1;
    //compararea ex: NU: x.s[i]!=y.s[i] dar DA: x.s[i]!=y1[i];

    friend void replace(String &, char *, char *);
    friend String getReplace(String , char* , char* );
    void replace(char* , char* );
    String getReplace(char* , char* );

    friend void replace(String &, String , String );
    friend String getReplace(String , String , String );
    void replace(String , String );
    String getReplace(String , String );

    friend void replace(String &, char * , String );
    friend String getReplace(String , char* , String );
    void replace(char* , String );
    String getReplace(char* , String );

    friend void replace(String &, String , char * );
    friend String getReplace(String , String , char* );
    void replace(String , char* );
    String getReplace(String, char* );

    //Delete Spatiu - Bug - lungimea textului se modifica

    friend void del_spatiu(String &);
    friend String getDel_spatiu(String);
    void del_spatiu();
    String getDel_spatiu();

    //Delete Cifre - Bug - lungimea textului se modifica

    friend void del_cifre(String &);
    friend String getDel_cifre(String);
    void del_cifre();
    String getDel_cifre();

    //Delete Litere - Bug - lungimea textului se modifica

    friend void del_litere(String &);
    friend String getDel_litere(String);
    void del_litere();
    String getDel_litere();

    //Cauta Cuvint

    friend int cauta_cuvint(String , char *);
    friend int cauta_cuvintNoCaseSensitive(String, char*);
    int cauta_cuvint(char *);
    int cauta_cuvintNoCaseSensitive(char*);

    friend int cauta_cuvint(String , String );
    friend int cauta_cuvintNoCaseSensitive(String, String );
    int cauta_cuvint(String);
    int cauta_cuvintNoCaseSensitive(String);

    //Other things

    void pauza(void); //implementare - _getch() in clasa
    char passReadWithOutput(void); //citeste cite un caracter insa nu il afiseaza si permite programului sa continue(curatarea ecranului e necesara)
    char passReadNoOutput(void); //citeste cite un caracter si il afiseaza si permite programului sa continue
    char passReadNoOutputCifre(void); //citeste cite o Cifra insa NU o afiseaza si permite programului sa continue
    char passReadNoOutputLitere(void); //citeste cite o Litera insa NU o afiseaza si permite programului sa continue
    inline int good(void) const; //controleaza daca NU a fost erroare la tapare
    inline int bad(void) const; //controleaza daca a fost erroare la tapare
    inline void clearError(void); //reseteaza controlul errorii(error=0)
    inline int lungime(void) const; //afiseaza lungimea sirului de caractere
    inline int getMaxSize(void) const;
    int aflaLungimeaTextului(void);
    int aflaSiSeteazaLungimea(void);
    void reinitializeaza(void);

    void egaleazaString(String);
};
//To Do - Dupa prezentarea proiectului Tre de trecut la _getch() de la _getche()

//-------------------------------------------------------------------------------------------------
//*************************************** sfirsit de clasa ****************************************
//-------------------------------------------------------------------------------------------------

void String::reinitializeaza(void)
{
    this->s[0] = 0;
    this->l = 0;
    this->error = 0;
    this->MaxSize = 31;
}

void String::egaleazaString(String y)
{
    for (register int i=0; i<31; i++) this->s[i] = y.s[i];
    this->l = y.l;
    this->error = y.error;
}

int String::aflaSiSeteazaLungimea(void)
{
    int l = 0;
    while( this->s[l++] != 0 );
    this->l = l;
    return l;
}

int String::aflaLungimeaTextului(void)
{
    int l = 0;
    while( this->s[l++] != 0 );

    return l;
}

inline int String::lungime(void) const
{
    return this->l;
}

inline int String::getMaxSize(void) const
{
    return this->MaxSize;
}

char String::passReadNoOutputCifre(void)
{
    register char k=_getch();
    if((k>='0' && k<='9') || k==8)
    {
        this->s[this->l]=k; this->l++;
        if(k==8)
            this->l-=2;

        if(this->l<0) this->l=0;
        this->s[this->l]=0;
    }

    if(k==72 || k==80 || k==75 || k==77 || k==13 || k==27)
        this->error=1;
    return k;
}

char String::passReadNoOutputLitere(void)
{
    register char k=_getch();
    if(((k>='a' && k<='z') || (k>='A' && k<='Z') || k==32) || k==8)
    {
        this->s[this->l]=k; this->l++;
        if(k==8)
            this->l-=2;

        if(this->l<0) this->l=0;
    }

    if(k==72 || k==80 || k==75 || k==77)
    {
        this->l--;
        this->error=1;
    }

    if(k==13 || k==27)
    {
        this->error=1;
    }
    this->s[this->l]=0;
    return k;
}

inline void String::clearError(void)
{
    this->error = 0;
}

inline int String::good(void) const
{
    if(!error)
        return 1;
    else
        return 0;
}

inline int String::bad(void) const
{
    if(error)
        return 1;
    else
        return 0;
}

char String::passReadNoOutput(void)
{
    register char k=_getch();
    this->s[this->l]=k; this->l++;
    if(k==8)
        this->l-=2;

    if(k==72 || k==80 || k==75 || k==77)
    {
        this->l-=2;
        this->error=1;
    }

    if(k==13 || k==27)
    {
        this->l--;
        this->error=1;
    }

    if(this->l<0) this->l=0;
    this->s[this->l]=0;
    return k;
}

char String::passReadWithOutput(void)
{
    cout<<this->s;

    register char k=_getche();
    this->s[this->l]=k; this->l++;
    if(k == 8 && this->l <= 1)
        cout<<char(32);
    if(k==8)
    {
        this->l-=2;
        cout<<char(32)<<char(8);
    }
    if(k==72 || k==80 || k==75 || k==77)
    {
        this->l-=2;
        cout<<char(8);
        this->error=1;
    }
    if(k==13 || k==27)
    {
        this->l--;
        this->error=1;
    }
    if(this->l<0) this->l=0;
    this->s[this->l]=0;
    cout<<endl;
    return k;
}


void String::pauza(void)
{
    _getch();
}

void String::citLitere()
{
    register char k;
    this->l=0;
    while ((k=_getch())!=13)
        if(((k>='A' && k<='Z') || (k>='a' && k<='z') || k==32) || k==8)
        {
            cout<<k;
            this->s[this->l]=k; this->l++;
            if(k == 8 && this->l <= 1)
                cout<<char(32);
            if(k==8){this->l-=2; cout<<char(32)<<char(8);} if(this->l<0) this->l=0;
        }
    this->s[this->l]=0;
    cout<<endl;
}

void String::citCifre()
{
    register char k;
    this->l=0;
    while ((k=_getch())!=13) if((k>='0' && k<='9') || k==8)
    {
        cout<<k;
        this->s[this->l]=k; this->l++;
        if(k == 8 && this->l <= 1)
            cout<<char(32);
        if(k==8){this->l-=2; cout<<char(32)<<char(8);} if(this->l<0) this->l=0;
    }
    this->s[this->l]=0;
    cout<<endl;
}

//End of NEW implementations

//sterge cifrele din sir
void del_cifre(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if( x.s[i]>='0' && x.s[i]<='9' )
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
}

void String::del_cifre()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if( this->s[i]>='0' && this->s[i]<='9' )
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1] = this->s[p1+1];
            i--;
        }
}

String getDel_cifre(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if( x.s[i]>='0' && x.s[i]<='9' )
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
    return x;
}

String String::getDel_cifre()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if( temporary.s[i]>='0' && temporary.s[i]<='9' )
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1] = temporary.s[p1+1];
            i--;
        }
    return temporary;
}

//sterge literele din sir
void del_litere(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if (((x.s[i] >= 'A') && (x.s[i] <= 'Z')) || ((x.s[i] >= 'a') && (x.s[i] <= 'z')))
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
}

void String::del_litere()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if (((this->s[i] >= 'A') && (this->s[i] <= 'Z')) || ((this->s[i] >= 'a') && (this->s[i] <= 'z')))
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1] = this->s[p1+1];
            i--;
        }
}

String getDel_litere(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if (((x.s[i] >= 'A') && (x.s[i] <= 'Z')) || ((x.s[i] >= 'a') && (x.s[i] <= 'z')))
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
    return x;
}

String String::getDel_litere()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if (((temporary.s[i] >= 'A') && (temporary.s[i] <= 'Z')) || ((temporary.s[i] >= 'a') && (temporary.s[i] <= 'z')))
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1] = temporary.s[p1+1];
            i--;
        }
    return temporary;
}

//sterge spatiile libere din text
void del_spatiu(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] == ' ')
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
}

void String::del_spatiu()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if(this->s[i] == ' ')
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1] = this->s[p1+1];
            i--;
        }
}

String getDel_spatiu(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] == ' ')
        {
            for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1] = x.s[p1+1];
            i--;
        }
    return x;
}

String String::getDel_spatiu()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if(temporary.s[i] == ' ')
        {
            for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1] = temporary.s[p1+1];
            i--;
        }
    return temporary;
}

//cauta daca exista un cuvint
int cauta_cuvint(String x, char *y1)
{
    String y;
    int c1=0,j1=0;
    register int i;
    for (i=0; i<y.getMaxSize(); i++) y.s[i] = y1[i];
    while (y.s[j1++]!=0);
    j1--;
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i] == y.s[0])
        {
            for (register int i2 = 0; i2 < j1; i2++)
                if(x.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int cauta_cuvintNoCaseSensitive(String x, char *y1)
{
    String y;
    int c1=0,j1=0;
    register int i;
    for (i=0; i<y.getMaxSize(); i++) y.s[i] = y1[i];
    while (y.s[j1++]!=0);
    j1--;
    y.text_tip_mic();
    x.text_tip_mic();
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i] == y.s[0])
        {
            for (register int i2 = 0; i2 < j1; i2++)
                if(x.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}


int String::cauta_cuvint(char *y1)
{
    String y;
    int c1=0,j1=0;
    register int i;
    for (i=0; i<y.getMaxSize(); i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    j1--;
    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i] == y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int String::cauta_cuvintNoCaseSensitive(char *y1)
{
    String y, temporary = *this;
    int c1=0,j1=0;
    register int i;
    for (i=0; i<y.getMaxSize(); i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    j1--;
    y.text_tip_mic();
    temporary.text_tip_mic();
    for (i=0; i<temporary.getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i] == y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int cauta_cuvint(String x, String y)
{
    int c1=0,j1=0;
    register int i;

    while (y.s[j1++]!=0);
    j1--;
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int cauta_cuvintNoCaseSensitive(String x, String y)
{
    int c1=0,j1=0;
    register int i;

    while (y.s[j1++]!=0);
    j1--;
    y.text_tip_mic();
    x.text_tip_mic();
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int String::cauta_cuvint(String y)
{
    int c1=0,j1=0;
    register int i;

    while (y.s[j1++]!=0);
    j1--;
    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

int String::cauta_cuvintNoCaseSensitive(String y)
{
    String temporary = *this;
    int c1=0,j1=0;
    register int i;

    while (y.s[j1++]!=0);
    j1--;
    y.text_tip_mic();
    temporary.text_tip_mic();
    for (i=0; i<temporary.getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2] == y.s[i2]) c1++;
        }

        if(c1 == j1)
        {
            return 1;
        }
        else
            continue;
    }
    return 0;
}

//Inlocuieste intr-un sir de caractere un cuvint cautat cu un cuvint indicat
void replace(String &x, char *y1 , String z)
{
    String y,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

void String::replace(char *y1, String z)
{
    String y,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1]=this->s[p1+j1];

                this->s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=this->s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) this->s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) this->s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

String getReplace(String x, char *y1, String z)
{
    String y,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return x;
}

String String::getReplace(char *y1, String z)
{
    String y,pastr, temporary = *this;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1]=temporary.s[p1+j1];

                temporary.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=temporary.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) temporary.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) temporary.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return temporary;
}

//Inlocuieste intr-un sir de caractere un cuvint cautat cu un cuvint indicat
void replace(String &x, String y , char *z1)
{
    String z,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

void String::replace(String y, char *z1)
{
    String z,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1]=this->s[p1+j1];

                this->s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=this->s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) this->s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) this->s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

String getReplace(String x, String y, char* z1)
{
    String z,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return x;
}

String String::getReplace(String y, char *z1)
{
    String z,pastr, temporary = *this;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1]=temporary.s[p1+j1];

                temporary.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=temporary.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) temporary.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) temporary.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return temporary;
}

//Inlocuieste intr-un sir de caractere un cuvint cautat cu un cuvint indicat
void replace(String &x, char *y1 , char *z1)
{
    String y,z,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;

            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

void String::replace(char* y1, char* z1)
{
    String y, z, pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2]==y.s[i2]) c1++;

            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1]=this->s[p1+j1];

                this->s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=this->s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) this->s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) this->s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

String getReplace(String x, char *y1, char *z1)
{
    String y,z,pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0;i<y.getMaxSize();i++) y.s[i]=y1[i];
    for (i=0;i<z.getMaxSize();i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;

            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return x;
}

String String::getReplace(char* y1, char* z1)
{
    String temporary = *this, y, z, pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    for (i=0; i<y.getMaxSize(); i++) y.s[i]=y1[i];
    for (i=0; i<z.getMaxSize(); i++) z.s[i]=z1[i];
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);

    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2]==y.s[i2]) c1++;

            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1]=temporary.s[p1+j1];

                temporary.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=temporary.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) temporary.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) temporary.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return temporary;
}


//Inlocuieste intr-un sir de caractere un cuvint cautat cu un cuvint indicat
void replace(String &x, String y , String z)
{
    String pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

void String::replace(String y, String z)
{
    String pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);
    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(this->s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(this->s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) this->s[p1]=this->s[p1+j1];

                this->s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=this->s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) this->s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) this->s[k2]=pastr.s[k2-j2];
            }
        }
    }
}

String getReplace(String x, String y, String z)
{
    String pastr;
    int j1=0,j2=0,c1=0;
    register int i;
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);
    for (i=0; i<x.getMaxSize(); i++)
    {
        c1=0;
        if(x.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(x.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<x.getMaxSize(); p1++) x.s[p1]=x.s[p1+j1];

                x.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=x.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) x.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<x.getMaxSize(); k2++) x.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return x;
}

String String::getReplace(String y, String z)
{
    String pastr, temporary = *this;
    int j1=0,j2=0,c1=0;
    register int i;
    while (y.s[j1++]!=0);
    while (z.s[j2++]!=0);
    for (i=0; i<this->getMaxSize(); i++)
    {
        c1=0;
        if(temporary.s[i]==y.s[0])
        {
            for (register int i2=0; i2<j1; i2++)
                if(temporary.s[i+i2]==y.s[i2]) c1++;
            if(c1==j1)
            {
                for (register int p1=i; p1<this->getMaxSize(); p1++) temporary.s[p1]=temporary.s[p1+j1];

                temporary.s[254-j1]=0; i--;
                for (register int k=i; k<pastr.getMaxSize(); k++) pastr.s[k]=temporary.s[k];

                for (register int p2=0,p4=i; p2<j2,p4<=i+j2; p2++,p4++) temporary.s[p4+1]=z.s[p2];

                for (register int k2=i+j2+1; k2<this->getMaxSize(); k2++) temporary.s[k2]=pastr.s[k2-j2];
            }
        }
    }
    return temporary;
}

//transforma literele mici in mari, si mari in mici
void text_tip_togle(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
    {
        if(x.s[i] >= 'A' && x.s[i] <= 'Z')
        {
            x.s[i] = x.s[i]+32;
        }
        else
            if(x.s[i] >= 'a' && x.s[i] <= 'z')
            {
                x.s[i] = x.s[i]-32;
            }
    }
}

void String::text_tip_togle()
{
    for (register int i=0; i<this->getMaxSize(); i++)
    {
        if(this->s[i] >= 'A' && this->s[i] <= 'Z')
        {
            this->s[i] = this->s[i]+32;
        }
        else
            if(this->s[i] >= 'a' && this->s[i] <= 'z')
            {
                this->s[i] = this->s[i]-32;
            }
    }
}

String getText_tip_togle(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
    {
        if(x.s[i] >= 'A' && x.s[i] <= 'Z')
        {
            x.s[i] = x.s[i]+32;
        }
        else
            if(x.s[i] >= 'a' && x.s[i] <= 'z')
            {
                x.s[i] = x.s[i]-32;
            }
    }
    return x;
}

String String::getText_tip_togle()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
    {
        if(temporary.s[i] >= 'A' && temporary.s[i] <= 'Z')
        {
            temporary.s[i] = temporary.s[i]+32;
        }
        else
            if(temporary.s[i] >= 'a' && temporary.s[i] <= 'z')
            {
                temporary.s[i] = temporary.s[i]-32;
            }
    }
    return temporary;
}

//transforma primul caracter al sirului in litera mare
void text_tip_titlu(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i]>='a' && x.s[i]<='z')
        {
            x.s[i] = x.s[i]-32;
            break;
        }
}

void String::text_tip_titlu()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if(this->s[i]>='a' && this->s[i]<='z')
        {
            this->s[i] = this->s[i]-32;
            break;
        }
}

String getText_tip_titlu(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i]>='a' && x.s[i]<='z')
        {
            x.s[i] = x.s[i]-32;
            break;
        }
    return x;
}

String String::getText_tip_titlu()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if(temporary.s[i]>='a' && temporary.s[i]<='z')
        {
            temporary.s[i] = temporary.s[i]-32;
            break;
        }
    return temporary;
}

//transforma literele mari in litere mici
void text_tip_mic(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] >= 'A' && x.s[i] <= 'Z')
        {
            x.s[i] = x.s[i]+32;
        }
}

void String::text_tip_mic()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if(this->s[i]>='A' && this->s[i]<='Z')
        {
            this->s[i] = this->s[i]+32;
        }
}

String getText_tip_mic(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i]>='A' && x.s[i]<='Z')
        {
            x.s[i] = x.s[i]+32;
        }
    return x;
}

String String::getText_tip_mic()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if(temporary.s[i]>='A' && temporary.s[i]<='Z')
        {
            temporary.s[i] = temporary.s[i]+32;
        }
    return temporary;
}

//transforma literele mici in litere mari
void text_tip_mare(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] >= 'a' && x.s[i] <= 'z')
        {
            x.s[i] = x.s[i]-32;
        }
}

void String::text_tip_mare()
{
    for(register int i=0; i<this->getMaxSize(); i++)
        if(this->s[i] >= 'a' && this->s[i] <= 'z')
        {
            this->s[i] = this->s[i]-32;
        }
}

String getText_tip_mare(String x)
{
    for(register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] >= 'a' && x.s[i] <= 'z')
        {
            x.s[i] = x.s[i]-32;
        }
    return x;
}

String String::getText_tip_mare()
{
    String temporary = *this;

    for(register int i=0; i<this->getMaxSize(); i++)
        if(temporary.s[i] >= 'a' && temporary.s[i] <= 'z')
        {
            temporary.s[i] = temporary.s[i]-32;
        }
    return temporary;
}

//transforma fiecare litera mica in litera mare care se afla dupa punct
void text_tip_prop(String &x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] == '.')
        {
            while(x.s[i+1]==' ') i++;
            if(x.s[i+1] >= 'a' && x.s[i+1] <= 'z')
            {
                x.s[i+1] = x.s[i+1]-32;
            }
        }
}

void String::text_tip_prop()
{
    for (register int i=0; i<this->getMaxSize(); i++)
        if(this->s[i] == '.')
        {
            while(this->s[i+1]==' ') i++;
            if(this->s[i+1] >= 'a' && this->s[i+1] <= 'z')
            {
                this->s[i+1] = this->s[i+1]-32;
            }
        }
}

String getText_tip_prop(String x)
{
    for (register int i=0; i<x.getMaxSize(); i++)
        if(x.s[i] == '.')
        {
            while(x.s[i+1]==' ') i++;
            if(x.s[i+1] >= 'a' && x.s[i+1] <= 'z')
            {
                x.s[i+1] = x.s[i+1]-32;
            }
        }
    return x;
}

String String::getText_tip_prop()
{
    String temporary = *this;

    for (register int i=0; i<this->getMaxSize(); i++)
        if(temporary.s[i] == '.')
        {
            while(temporary.s[i+1]==' ') i++;
            if(temporary.s[i+1] >= 'a' && temporary.s[i+1] <= 'z')
            {
                temporary.s[i+1] = temporary.s[i+1]-32;
            }
        }
    return temporary;
}

//----------------------------------------------------------------------------------------
//**************************************  Operatori  *************************************
//----------------------------------------------------------------------------------------

//operator "==", return False or True
int operator==(String x,String y)
{
    register int k=0;
    if (x.l==y.l)
    {
        for (register int i=0; i<x.l; i++)
            if (x.s[i] == y.s[i]) k++;
            else
                break;
    }
    else
        return 0;

    if (k==x.l)
        return 1;
    else
        return 0;
}

//operator ">", return False or True
int operator>(String x,String y)
{
    for (register int i=0; i<x.l; i++)
        if (x.s[i] == y.s[i]) continue;
        else
            if (x.s[i] > y.s[i])
                return 1;
            else
                return 0;
    return 0;
}

//operator "<", return False or True
int operator<(String x,String y)
{
    for (register int i=0; i<x.l; i++)
        if (x.s[i] == y.s[i]) continue;
        else
            if (x.s[i] < y.s[i])
                return 1;
            else
                return 0;
    return 0;
}

//operator >>
istream & operator>>(istream &is,String &x)
{
    register char k;
    x.l=0;
    while ((k=_getche())!=13)
    {
        x.s[x.l]=k;
        x.l++;
        if(k == 8 && x.l <= 1)
            cout<<char(32);
        if(k==8 && x.l>0)
        {
            x.l-=2;
            cout<<char(32)<<char(8);
            if(x.l < 0) x.l=0;
        }
    }
    if(x.l > x.getMaxSize() - 1)
        x.l = x.getMaxSize() - 1;
    x.s[x.l]=0;
    cout<<endl;
    return is;
}

#endif // STRING_H