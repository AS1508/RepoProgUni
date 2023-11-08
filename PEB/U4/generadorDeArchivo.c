#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Llamadas.dat" //*

struct generadorDeArchivo{
   //*
    char a[20];
    int b;
    int c;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[] = {
    //* 
        {"aa", 10, 1},
        {"aa", 20, 3},
        {"bb", 16, 1},
        {"cc", 80, 2},
        {"dd", 50, 2},
    //*
    }, aux2;
    int cantidad, i=0;

    archivo=fopen(ARCHIVO, "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    cantidad = 5;   //*
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
        printf("%s | %d | %d \n", aux2.a, aux2.b, aux2.c);
        i++;
    }
    fclose(archivo);

    return 0;
}