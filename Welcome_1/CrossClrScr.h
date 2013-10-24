/* 
 * File:   CrossClrScr.h
 * Author: sboros
 *
 * Created on October 23, 2013, 5:24 PM
 */

#ifndef CROSSCLRSCR_H
#define CROSSCLRSCR_H

#include <cstdlib>

using namespace std;

//Aceasta clasa defineste functia clrscr() - pentru curatarea ecranului
//Pentru a nu avea necesitatea de a modifica codul pe Linux

#ifdef _linux_
#define clrscr() system("clear")
#else
#define clrscr() system("cls")
#endif

#endif // CROSSCLRSCR_H