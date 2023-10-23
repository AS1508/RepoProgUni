#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Llamadas.dat" //*

struct generadorDeArchivo{
   //*
    char sector[35];
    int duracion;
    int tipo;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[]={
    //*
        {"a", 300, 2},
        {"aa", 30, 1},
        {"b",20, 2},
        {"c", 11, 3},
        {"ccc", 10, 1},
    //*
    };
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo=NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 5;   //*
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
        printf("%s\t|\t%d |\t%d |\n", aux[i].sector, aux[i].duracion, aux[i].tipo);
        i++;
    }
    fclose(archivo);

    return 0;
}