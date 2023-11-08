#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Costos.dat" //*

struct generadorDeArchivo{
   //*
    float a;
    float b;
    float c;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[] = {
    //* 
        {10.5, 20.5, 15.5},
    //*
    }, aux2;
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 1;   //*
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
        printf("%.2f | %.2f | %.2f \n", aux2.a, aux2.b, aux2.c);
        i++;
    }
    fclose(archivo);

    return 0;
}