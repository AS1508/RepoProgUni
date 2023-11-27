#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_PRECIOS "Productos.dat"

struct Producto{
    int codigo;
    char descripcion[31];
    float precio;
    char tipo;
};

int main(){
    struct Producto productos;
    FILE*archivo;

    if(fopen(FILE_PRECIOS, "r+b")==NULL){printf("Error");exit(1);}
    
    fread(&productos, sizeof(struct Productos),1, archivo);
    while(!feof(archivo)){
        if(productos.tipo=='I'){
            productos.precio+=(productos.precio*20)/100;
            fseek(archivo, sizeof(struct Producto)*-1, SEEK_CUR);
            fwrite(&productos, sizeof(struct Producto),1, archivo);
            fseek(archivo, sizeof(struct Producto)*0, SEEK_CUR);
        }
        fread(&productos, sizeof(struct Producto),1, archivo);
    }
    fclose(archivo);

    return 0;
}