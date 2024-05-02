#include "Cadena.h"

char* normalizarCadena(char *dest, const char *orig)
{
    char* destInicial = dest;

    while(*orig)
    {
        //Eliminamos espacios en blanco
        while(esBlanco(*orig))  //no verifica el fin de cadena
            orig++;

        //Comenzamos con las palabras

        if(*orig)
        {
            *dest = toupper(*orig);
            dest++;
            orig++;

            while(!esBlanco(*orig) && *orig) //esto es equivalente a (cadena == \0)
            {
                *dest = tolower(*orig);
                dest++;
                orig++;

            }
            if(esBlanco(*orig))
            {
                *dest = ' ';
                dest++;
                orig++;
            }
        }
    }

    if(dest>destInicial && *(dest-1) == ' '){
        dest--;
    }
    *dest = '\0';

    return *dest;
}
