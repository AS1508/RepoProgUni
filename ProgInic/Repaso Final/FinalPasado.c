#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#define MES 12
#define SUCURSALES 10
#define TRIMESTRE 3

int Carga(int[][MES], int, int, int, char, int[]);
int Busqueda(int[], int, int);
int LeeYValida(int, int, int);
int Ingreso(int, int);
void Resumen(int[][MES]);
void Objetivo(int[]);
void VentaTrimestral(int[][MES]);

int main(){
    int venta[SUCURSALES][MES], sucursal, mes, cantidad=0, cantidadVentas=0, objetivoMesual[MES]={0};
    char objetivo;

    cantidadVentas = Carga(venta, sucursal, mes, cantidad, objetivo, objetivoMesual);

    Resumen(venta);
    Objetivo(objetivoMesual);
    VentaTrimestral(venta);

    return 0; 
}

int Carga(int ventas[][MES], int sucursal, int mes, int cantidad, char objetivo, int objetivoMensual[]){
    int cantidadFinal=0;

    printf("-Sucursal: ");
    sucursal=LeeYValida(1000, 1010, 0);
    while(sucursal!=0){
        do{    
            printf("-Mes: ");
            mes=Ingreso(1, MES);
            if(ventas[sucursal-1000][mes-1]!=0)
                printf("Dato ya registrado.\n");
        }while(ventas[sucursal][mes]!=0);
        printf("-Cantidad: ");
        cantidad=Ingreso(1, 100000);
        printf("Cumple con el Objetivo?(S/N)\n");
        scanf("%c", &objetivo);
        objetivo=toupper(objetivo);
        if(objetivo=='S')
            objetivoMensual[mes-1]++;
        
        ventas[sucursal-1000][mes-1]=cantidad;
        cantidadFinal++;

        printf("-Sucursal: ");
        sucursal=LeeYValida(1000, 1010, 0);
    }
    return cantidadFinal;
}
int LeeYValida(int limInf, int limSup, int fin){
    int numero;
    do{
        scanf("%d", numero);
    }while((numero<limInf || numero>limSup) || numero!=0);
    return numero;
}
int Ingreso(int limInf, int limSup){
    int numero;
    do{
        scanf("%d", numero);
    }while(numero<limInf || numero>limSup);
    return numero;
}
void Resumen(int ventas[][MES], int cantidad){
    for(int i=0; i<MES; i++)
        printf("Sucursal\tMes%d\t", i+1);

    for(int i=0; i<SUCURSALES; i++){
        printf("%d", i+1000);
        for(int j=0; j<MES; j++)
            printf("\t\t\t|%d|\t", ventas[i][j]);
        printf("\n");
    }
}
void Objetivo(int objetivos[]){
    printf("\n\tObjetivos\n");
    for(int i=0; i<MES; i++)
        if(objetivos[i]<0)
            printf("mes %d | sucursales: %d \n", i+1, objetivos[i]);
}
void VentaTrimestral(int ventas[][MES]){
    int suma=0;
    for(int i=0; i<SUCURSALES; i++)
        for(int j=0; j<TRIMESTRE; j++)
            suma+=ventas[i][j];
    
    printf("\nPrimer Trimestre: %d ventas", suma);
}