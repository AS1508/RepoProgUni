#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Empleados.dat" //*

struct generadorDeArchivo{
   //*
    int a;
    char b[26];
    int c;
    int d;
    float e;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[]={
    //* 
        {123, "asd", 2021, 5000, 123.12},
        {135, "qwe", 2022, 5000, 123.12},
        {332, "xcv", 2011, 6000, 674.45},
        {567, "asd", 2020, 7000, 123.12},
        {345, "asd", 2014, 7000, 657.23},
    //*
    };
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 5;   //*
    while(i<cantidad){
        fwrite(&aux[i], sizeof(struct generadorDeArchivo),1, archivo); //Faltaba el [i]
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
        printf("%d | %s | %d | %d | %.2f \n", aux[i].a, aux[i].b, aux[i].c, aux[i].d, aux[i].e);
        i++;
    }
    fclose(archivo);

    return 0;
}