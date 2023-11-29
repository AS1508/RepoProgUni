#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define F_ARTICULOS "stocka.dat"
#define F_REPONER "stockact.dat"
 
typedef struct{
    int codigo;
    int stock;
    float precio;
}ARTICULO;
 
int IngresoValidado(int, int, int);
int Ingreso(int, int);
int Busqueda(ARTICULO[], int, int);
int Carga(ARTICULO[]);
void InformeMensual(float[][12]);
void aReponer(ARTICULO[], int);
void Actualizar(ARTICULO[], int);
 
int main(){
    ARTICULO articulos[1500];
    int cliente, mes, codigo, cantidad, cantidadArticulos, posicion;
    float importeMensual[100][12];

    cantidadArticulos = Carga(articulos);

    printf(">>Cliente\n");
    cliente = IngresoValidado(1, 99, 0);

    while (cliente != 0){
        printf(">>Articulo\n");
        scanf(">%d", &codigo);

        posicion = Busqueda(articulos, codigo, cantidadArticulos);
        if(posicion != -1){
            printf(">>Mes\n");
            mes = Ingreso(1, 12);

            printf(">>Cantidad\n");
            cantidad = Ingreso(1, 1000000);

            articulos[posicion].stock -= cantidad;
            importeMensual[cliente-1][mes-1] = articulos[posicion].precio * cantidad;
        }else{
            printf(">>>CODIGO NO ENCONTRADO>>>\n");
        }

        printf(">>Cliente\n");
        cliente = IngresoValidado(1, 99, 0);
    }
    InformeMensual(importeMensual);
    aReponer(articulos, cantidadArticulos);
    Actualizar(articulos, cantidadArticulos);

    return 0;
}

int Carga(ARTICULO articulos[]){
    FILE*archivo;
    ARTICULO auxiliar;
    int i = 0;

    if((archivo = fopen(F_ARTICULOS, "rb")) == NULL){exit(1);}

    fread(&auxiliar, sizeof(ARTICULO),1, archivo);
    while (!feof(archivo)){
        articulos[i] = auxiliar;
        i++;
        fread(&auxiliar, sizeof(ARTICULO),1, archivo);
    }
    return i;
}
int IngresoValidado(int limInf, int limSup, int fin){
    int numero;
    do{
        scanf(">%d", &numero);
    }while((numero < limInf || numero > limSup) && numero != fin);
    return numero;
}
int Ingreso(int limInf, int limSup){
    int numero;
    do{
        scanf(">%d", &numero);
    }while(numero < limInf || numero > limSup);
    return numero;
}
void InformeMensual(float importes[][12]){
    printf("Cliente / Mes\t");
    for(int i = 0; i < 12, i++)
        printf("%d", i+1);
    
    for(int i = 0; i<100; i++){
        printf("\nC_%d\t\t", i+1);
        for(int j = 0; j<12; j++)
            printf("%.2f\t", importes[i][j]);
    }
}
void aReponer(ARTICULO articulo[], int cantidad){
    printf(">>>A reponer\n");
    for(int i = 0; i<cantidad; i++)
        if(articulo[i].stock <= 0){printf("-C_%d\n", articulo[i].codigo);}
}
void Actualizar(ARTICULO articulos[], int cantidad){
    FILE*archivo;

    if((archivo = fopen(F_REPONER, "wb")) == NULL){exit(1);}

    for(int i = 0; i<cantidad; i++){
        fwrite(&articulos[i], sizeof(ARTICULO),1, archivo);
    }
    printf("\n\n>>>ARCHIVO ACTUALIZADO CREADO>>>\n")
    fclose(archivo);
}
void 