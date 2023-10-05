#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_ENVASE "Envase.dat"
#define FILE_ENVASE_VIDRIO "Envase_Vidrio.dat"
#define FILE_ENVASE_VIDRIO_VENTA "VentaEnvase_Vidrio.dat"
#define FILE_INVETARIO "Inventario.dat"

struct Envase{
    char codEnv[9];
    int codMat;
    char descri[25];
    float precio;
};
struct Venta{
    char codEnv[10];
    int color;
    int cantVend;
};

int Busqueda(struct Envase[], char[], int);
void LeeYValidaCodigo(char[], int, char);
int Lee(int, int);
int CargarInventario(struct Envase []);
int VentaEnvases(struct Venta[], struct Envase[], int);
//void MostrarInforme();

int main(){
    FILE*archivo;
    int cantidadEnvases, cantidadVentas;
    struct Envase envases[100];
    struct Venta ventas[100], aux;

    //Carga de Inventario
    cantidadEnvases = CargarInventario(envases);
    archivo = fopen(FILE_ENVASE, "wb");
    if(archivo == NULL){
        printf("Error.");
        exit(1);
    }

    for(int i=0; i<cantidadEnvases;i++){
        fwrite(&envases[i], sizeof(struct Envase), 1, archivo);
    }
    fclose(archivo);

    //Test

    archivo=fopen(FILE_ENVASE, "rb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    for(int i=0; i<cantidadEnvases; i++){
        fread(&envases[i], sizeof(struct Envase), 1, archivo);
        printf("\n\t|%s|\t|%d|\t|%.2f $|\n_%s\n", envases[i].codEnv, envases[i].codMat, envases[i].precio, envases[i].descri);
        for(int j=0; j<30; j++)
            printf("__");
    }
    fclose(archivo);

    //Ventas
    
    cantidadVentas = VentaEnvases(ventas, envases, cantidadEnvases);
    archivo=fopen(FILE_ENVASE_VIDRIO_VENTA, "wb");
    if(archivo==NULL){
        printf("Error");
        exit(1);
    }
    for(int i=0; i<cantidadVentas;i++){
        fwrite(&ventas[i], sizeof(struct Venta), 1, archivo);
    }
    fclose(archivo);

    return 0;
}

int CargarInventario(struct Envase envases[]){
    char codEnv[9], descrip[25], cantidad=0;
    int codMat;
    float precio;
        //inputs
    printf("Codigo de envase (0 para salir): ");
    LeeYValidaCodigo(codEnv, 9, '0');

    while(strlen(codEnv)<=9 && codEnv[0]!='0'){
        printf("Codigo de material: ");
        codMat=Lee(1, 4);
        printf("Descripcion: ");
        fflush(stdin);
        gets(descrip);
        do{
            printf("Precio: ");
            scanf("%f", &precio);
        }while(envases[cantidad].precio<0);

        strcpy(envases[cantidad].codEnv, codEnv);
        envases[cantidad].codMat=codMat;
        strcpy(envases[cantidad].descri, descrip);
        envases[cantidad].precio=precio;
        cantidad++;

        printf("Codigo de envase (0 para salir): ");
        LeeYValidaCodigo(codEnv, 9, '0');
    }
    return cantidad;
}

int VentaEnvases(struct Venta ventas[], struct Envase envsases[], int cantidadEnvases){
    char codEnv[10];
    int color, cantidad=0, i=0, pos;
   /* FILE*archivo;
    archivo=fopen(FILE_ENVASE, "wb");
    if(archivo == NULL){
        printf("Error");
        exit(1);
    }*/

    printf("Codigo de envase(0 para salir): ");
    do{
        LeeYValidaCodigo(codEnv, 9, '0');
        pos=Busqueda(envsases, codEnv, cantidadEnvases);
    }while(pos!=-1);

    while(pos!=-1 && codEnv[0]!='0'){
        printf("Color: ");
        color=Lee(1, 5);
        
        printf("Cantidad: ");
        do{
            scanf("%d", &cantidad);
        }while(cantidad<=0);

        strcpy(ventas[i].codEnv, codEnv);
        ventas[i].color=color;
        ventas[i].cantVend = cantidad;

        i++;
        printf("Codigo de envase(0 para salir): ");
        LeeYValidaCodigo(codEnv, 9, '0');
        pos=Busqueda(envsases, codEnv, cantidadEnvases);
    }

    return i;
}
void LeeYValidaCodigo(char codEnv[], int max, char fin){
    do{
        fflush(stdin);
        gets(codEnv);
    }while (strlen(codEnv)>=max && codEnv[0]!='0');
}
int Lee(int li, int ls){
    int numero;
    do{
        scanf("%d", &numero);
    }while(numero<li || numero>ls);
    return numero;
}
int Busqueda(struct Envase DB[], char x[], int cantidad){
    int i=0, pos=-1;
    while (i<cantidad && pos==-1){
        if(strcmp(DB[i].codEnv, x)==0){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}