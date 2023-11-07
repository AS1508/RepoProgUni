#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Rating.dat" //*

struct generadorDeArchivo{
   //*
    int a;
    char b[20];
    float c;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[] = {
    //* 
        {123, "aa", 123.12},
        {123, "AA", 223.12},
        {234, "bb", 4.12},
        {435, "cc", 2323.12},
    //*
    }, aux2;
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 4;   //*
    while(i < cantidad){
        fwrite(&aux[i], sizeof(struct generadorDeArchivo),1, archivo); //Faltaba el [i]
        i++;
    }
    printf("\t\nArchivo Creado.\n\n");

    fclose(archivo);

    //Testing

    archivo=fopen(ARCHIVO, "rb");
    if(archivo == NULL){exit(1);}
    i=0;
    while(i<cantidad){
        fread(&aux2, sizeof(struct generadorDeArchivo),1, archivo);
        printf("%d | %s | %.2f \n", aux2.a, aux2.b, aux2.c);
        i++;
    }
    fclose(archivo);

    return 0;
}