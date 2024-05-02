#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#define esBlanco(X) ((X) == ' ' || (X)=='\t' || (X)=='\n') //Funcion en MACRO funcion(remplazo)

#include <ctype.h>

char* normalizarCadena(char *dest, const char *orig);

#endif // CADENA_H_INCLUDED
