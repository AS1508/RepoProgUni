#include<stdio.h>

struct datos{
    int codigo;
    char descripcion[51];
    int stock;
};

struct f{
    int codigo;
    int stock;
};

int main(){
    int i, x, cantidad, codigo, diferencia;
    struct datos articulos[10], aux;
    struct f aux2;
    int i;
    FILE * arch;
    FILE * arch2;
    arch=fopen("stock.dat", "wb");
    arch2=fopen("faltantes.dat", "wb");

    if(arch=="NULL"){
        printf("Error");
        exit(1);
    }
    
    if(arch2=="NULL"){
        printf("Error");
        exit(1);
    }

    //Carga de Productos en Estructura de edicion
    fread(&aux, sizeof(aux), 1, arch);
    while(!feof(arch)){
        articulos[i]=aux;
        i++;
        fread(&aux, sizeof(aux), 1, arch);
    }
    fclose(arch);

    //Ventas
    printf("Articulo: ");
    scanf("%d", &codigo);
    while(codigo!=0){
        x=Busqueda(articulos, codigo, i);
        if(x!=-1){
            printf("cantidad: ");
            scanf("%d", &cantidad);
            diferencia=articulos[x].stock-cantidad;
            if(diferencia<0){
                articulos[x].stock=0;
                aux2.codigo=codigo;
                aux2.stock=-(diferencia);
                fwrite(&aux2, sizeof(aux2), 1, arch2);
            }else
                articulos[x].stock=diferencia;
            printf("codigo: ");
            scanf("%d", codigo);
            
        }
    }
    fclose(arch2);
}