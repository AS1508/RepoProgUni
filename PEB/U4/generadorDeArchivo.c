#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "Rating.dat" //*

struct generadorDeArchivo{
   //*
    int canal;
    char programa[35];
    float rating;
   //*
};

int main(){
    FILE*archivo;
    struct generadorDeArchivo aux[]={
    //*
        {10, "AAA", 5.5},
        {20, "BBBBB", 200.1},
        {30, "CC", 300.1},
    //*
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
/*
    archivo=fopen(ARCHIVO, "rb");
    if(archivo==NULL){exit(1);}
    i=0;
    while(i<cantidad){
        fread(&aux, sizeof(struct generadorDeArchivo),1, archivo);
        printf("%s\t|\t%d |\n", aux[i].dato1, aux[i].dato2);
        i++;
    }
    fclose(archivo);
*/
    return 0;
}