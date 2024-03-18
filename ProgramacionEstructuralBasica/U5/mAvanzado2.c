#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_PRODUCTO "Productos.dat"
struct Productos
{
    int codigo;
    char descripcion[15];
    float precio;
};
struct Productos buscar(int);

int main(){
    struct Productos producto;
    int aBuscar;

    printf("Codigo a buscar: ");
    scanf("%d", &aBuscar);

    while(aBuscar!=0){
        producto=buscar(aBuscar);
        if(producto.codigo!=-1){printf("producto ....");}else{printf("Inexistente");}
        printf("Codigo a buscar: ");
        scanf("%d", &aBuscar);
    }

    return 0;
}
struct Productos buscar(int aBuscar){
    FILE*archivo;
    struct Productos producto;
    int bandera=0;

    if(archivo = fopen(F_PRODUCTO, "rb")==NULL){printf("mefui");exit(1);}

    fread(&Producto, sizeof(struct Producto),1, archivo);
    while(!feof(archivo) && bandera==0){
        if(producto.codigo==aBuscar){bandera=1;}else{fread(&producto, sizeof(struct Producto),1, archivo);}
    }
    if(bandera==0){
        producto.codigo=-1;
        fclose(archivo);
        return producto;
    }
}