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
void Actual(int, struct Producto[]);
void Actualizacion(int, float, struct Producto[]);

int main(){
    int i=0, cantidad;
    float actualizacion;
    cantidad=ArchivoPrueba();
    struct Producto precios[cantidad];

    Actual(cantidad, precios);
    for(i=0; i<30; i++)
        printf("_");
    Actualizacion(cantidad, actualizacion, precios);
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
void Actual(int cantidad, struct Producto precios[]){
    int i;
    FILE*archivo;
    
    archivo=fopen("precios.dat", "rb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }

    printf("\tPrecios actuales\n");

    while(i<cantidad){
        fread(&precios[i], sizeof(struct Producto),1, archivo);
        printf("%d | %.2f | %s\n", precios[i].codigo, precios[i].precio, precios[i].descripcion);
        i++;
    }
    fclose(archivo);
}
void Actualizacion(int cantidad, float actualizacion, struct Producto precios[]){
    int i=0;

    FILE*archivo;
    archivo=fopen("preciosActualizado.dat", "wb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    //for(i=0; i<cantidad; i++)
    
    printf("\n\nActualizacion (Porcentaje): ");
    scanf("%f", &actualizacion);
    actualizacion*=0.01;

    for(i=0; i<30; i++)
        printf("_");

    while(i<cantidad){
        fwrite(&precios[i], sizeof(struct Producto), 1, archivo);
        precios[i].precio*=actualizacion;
        i++;
    }
    while(i<cantidad){
        fread(&precios[i], sizeof(struct Producto), 1, archivo);
        printf("%d | %.2f | %s\n", precios[i].codigo, precios[i].precio, precios[i].descripcion);
        i++;
    }
    fclose(archivo);
}