#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Empleados.dat" //*

struct generadorDeArchivo
{   //*
    char dato1[50];
    int dato2;
    //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[]={   //*
        {"Sebastian", 1},
        {"Ivan", 1},
        {"Magali", 3},
    };
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo=NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 3;   //*
    while(i<cantidad){
        fwrite(&aux, sizeof(struct generadorDeArchivo),1, archivo);
        i++;
    }
    printf("\t\nArchivo Creado.\n\n");

    fclose(archivo);

    //Testing

    archivo=fopen(ARCHIVO, "rb");
    if(archivo==NULL){exit(1);}
    i=0;
    while(i<cantidad){
        fread(&aux, sizeof(struct generadorDeArchivo),1, archivo);
        printf("%s\t|\t%d |\n", aux[i].dato1, aux[i].dato2);
        i++;
    }
    fclose(archivo);

    return 0;
}