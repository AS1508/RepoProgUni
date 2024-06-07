#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Archivo.h"
 

 
int main(){
    if(crearArchivoBinario(A_BIN) == ERROR) return ERROR;

    FILE*pfOrigen = fopen(A_BIN,"rb");
    FILE*pfDestino = fopen(A_TXT, "wt");

    if(pfOrigen == NULL || pfDestino == NULL) {
        fclose(pfOrigen);
        fclose(pfDestino);
        return ERROR;
    }

    t_Persona p;
    const char *formato = "%10d%19s%19s%10.2f\n";
    fread(&p, sizeof(t_Persona), 1, pfOrigen);
    while(!feof(pfOrigen)){
                //Separador _ 
        //printf("leyendo: %d_%s_%s_%f\n", p.legajo, p.apellido, p.nombres, p.sueldo);
                //Separador caracter
        //fprintf(pfDestino, "%10d%19s%19s%10.2f\n", p.legajo, p.apellido, p.nombres, p.sueldo); //Ancho Fijo
        fprintf(pfDestino, formato, p.legajo, p.apellido, p.nombres, p.sueldo);

        fread(&p, sizeof(t_Persona), 1, pfOrigen);
    }

    fclose(pfOrigen);
    fclose(pfDestino);

    /*Hasta ahora creamos un bin de un txt de distintas formas Ancho fijo, y variable, con distintos delimitadores */
    /* ahora vamos a leer un txt y generar una estructura t_persona */

    pfOrigen = fopen(A_TXT, "rt");
    pfDestino = fopen(A_TXT, "rb");

    if(pfOrigen == NULL || pfDestino == NULL) {
        fclose(pfOrigen);
        fclose(pfDestino);
        return ERROR;
    }

//    p.legajo = -1;
//    p.sueldo = -2;
//    p.nombre[0] = '\0';
//    p.apellido[0] = '\0';

    char line[TAM_MAX_LINEA];
    while(fgets(line, TAM_MAX_LINEA, pfOrigen)){

        /*para asegurar que siempre inicialice y evitar errores*/
        p.legajo = -1;
        p.sueldo = -2;
        p.nombre[0] = '\0';
        p.apellido[0] = '\0';

        //sscanf(line,"%d;%[^;];%[^;];%f", &p.legajo, p.apellido, p.nombre, &p.sueldo); //Leo con delimitadores ; (soporta espacios)
        //sscanf(line,"%d%15[^\n]%19[^\n]%f", &p.legajo, p.apellido, p.nombre, &p.sueldo); //Leo con ancho Fijo sin delimitadores (soporta espacios)

        char aux[20];
        char *puntero = linea;
        //legajo
        strncpy(aux, puntero, 10);
        aux[10] = '\0';
        p.legajo = atoi(aux); //castea el vlaor del putnero a entero
        //apeelido
        puntero += 10;
        strncpy(aux, puntero, 19);
        aux[20] = '\0';
        strcpy(p.apellido, aux) //castea el vlaor del putnero a entero
        //nombre
        puntero += 19;
        strncpy(aux, puntero, 19);
        aux[20] = '\0';
        strcpy(p.nombre, aux);
        //sueldo
        puntero += 19;
        strncpy(aux, puntero, 10);
        aux[10] = '\0';
        p.sueldo = atof(aux);
    }


    fclose(pfOrigen);
    fclose(pfDestino);

    return OK;
}