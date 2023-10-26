#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_PRECIOS "Precios.dat"

struct Producto{
    int codigo;
    char descripcion[15];
    float precio;
};

int main(){
    struct Producto productos;
    FILE*archivo;
    int codigo, bandera=0;
    char rta;

    if(fopen(FILE_PRECIOS, "r+b")==NULL){printf("mefui");exit(1);}

    printf("Codigo: ");
    scanf("%d", %codigo);
    while (codigo!=0){
        fread(&productos, sizeof(struct Producto),1, archivo);
        while (!feof(archivo)){
            if(productos.codigo==codigo){
                bandera=1;
                printf("desea modificar descripcion?(S/N)\n\t");
                scanf("%c", &rta);
                if(rta=='S'){
                    fflush(stdin);
                    gets(productos.descripcion);
                }
                printf("desea modificar PRECIO? (S/N)\n\t");
                scanf("%c", &rta);
                if(rta=='S'){
                    fflush(stdin);
                    scanf("%f", productos.precio);
                }
                fseek(archivo, sizeof(struct Producto)*-1, SEEK_CUR);
                fwrite(&productos, sizeof(struct Producto),1, archivo);
                fflush(archivo);
            }else{fread(&productos, sizeof(struct Producto),1, archivo);}
        }
        if(bandera==0){printf("codigo inexistente");}

        printf("codigo: ");
        scanf("%d", &codigo);
        fseek(archivo, 0, SEEK_SET);
    }
    fclose(archivo)
    return 0;
}