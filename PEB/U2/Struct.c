#include<stdio.h>

struct producto
{
    int cod;
    char des[31];
    float precio;
};


int main(){
    int i, j;
    struct producto prod[5];

    //ingreso
    for(i=0; i<5; i++){
        printf("codigo: ");
        scanf("%d", &prod[i].cod);
        printf("Descripcion: ");
        gets(prod[i].des);
        fflush(stdin);
        printf("Precio: ");
        scanf("%d", &prod[i].precio);
    }

    //Muestra
    for(i=0; i<5; i++){
        printf("Codigo: %d \n Descripcion: %s \n precio: %d", prod[i].cod, prod[i].des, prod[i].precio);
    }

    return 0;
}