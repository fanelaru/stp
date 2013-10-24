/* 
 * File:   LinuxGetch.h
 * Author: sboros
 *
 * Created on October 24, 2013, 9:25 AM
 */

#ifndef LINUXGETCH_H
#define LINUXGETCH_H

#include <termios.h>
#include <stdio.h>

//Unica functie de care depinde programul si Sistemul de Operare Linux
//nu o are implementata in biblioteci...

//_getch() - Implementarea proprie in Linux pentru ca programul sa lucreze in ambele SO.
//Si a nu avea necesitatea de a modifica Codul Sursa pe Linux
int _getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

#endif // LINUXGETCH_H