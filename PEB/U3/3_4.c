#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ARCHIVO "precios.dat"

struct Producto
{
    int codigo;
    float precio;
    char descripcion[100];
};

int ArchivoPrueba();

int main(){
    int i=0, cantidad;
    cantidad=ArchivoPrueba();
    struct Producto precios[cantidad];
    FILE*archivo;
    
    archivo=fopen("precios.dat", "rb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    while(i<cantidad){
        fread(&precios[i], sizeof(struct Producto),1, archivo);
        printf("%d | %.2f | %s\n", precios[i].codigo, precios[i].precio, precios[i].descripcion);
        i++;
    }
    fclose(archivo);
return 0;
}

int ArchivoPrueba(){
    FILE*archivo;
    
    struct Producto precios[]={
        {123, 10.30, "Coca"},
        {234, 10.30, "pepsi"},
        {345, 10.30, "redbull"}
    };

    int i, cant;
    archivo=fopen(ARCHIVO, "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    cant = sizeof(precios) / sizeof(struct Producto);
  
    printf("\n%d\n", cant); 
  
    for(i=0; i<cant; i++)
        fwrite(&precios[i], sizeof(struct Producto), 1, archivo);
    fclose(archivo);

    return cant;
}