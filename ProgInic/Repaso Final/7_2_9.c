#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SEMANA 7
#define VENDEDORES 5

int Carga(int[][SEMANA], int, int, int, int[]);
int Ingreso(int, int);
int LeeYValida(int, int, int);
void Resumen(int[][SEMANA]);
void VentaFinde(int[][SEMANA]);

int main(){
    int semana[VENDEDORES][SEMANA]={{0}}, vendedor, dia, cantidad=0, ventaFinde[SEMANA]={0}, cantidadVentas=0;

    cantidadVentas = Carga(semana, vendedor, dia, cantidad, ventaFinde);

    Resumen(semana);
    printf("\nObjetivos\n")
    for(int i=0; i<VENDEDORES; i++)
        for(int j=0; j<SEMANA; j++)
            if(semana[i][j]<15)
                printf("dia %d | vendedores: %d\n", j+1, semana[i][j]);
    VentaFinde(semana);

    return 0;
}

int Carga(int venta[][SEMANA], int vendedor, int dia, int cantidad, int ventaFinde[]){
    int cantidadVentas=0;

    printf(\tVenta\n\n-vendedor: );
    vendedor=LeeYValida(99, 500, 0);
    while(vendedor!=0){
        printf("\n-dia: ");
        dia=Ingreso(0, SEMANA);
        printf("\n-cantidad: ");
        do{scanf("%d", &cantidad);}while(cantidad<0);
        if(dia == 6 || dia == 7)
            ventaFinde[dia-1]+=cantidad;
        venta[vendedor/100][dia-1] += cantidad;
        cantidadVentas++;
        printf("\n\tVENTA COMPLETADA\n\n");
        system("pause");
        printf(\tVenta\n\n-vendedor: );
        vendedor=LeeYValida(99, 500, 0);
    }
    return cantidadVentas;
}
int LeeYValida(int limInferior, int limSuperior, int fin){
    int numero;
    do{scanf("%d", &numero);}while((numero<limInferior || numero>limSuperior) && numero!=fin);
    return numero;
}
int Ingreso(int limInferior, int limSuperior){
    int numero;
    do{scanf("%d", &numero);}while(numero<limInferior || numero>limSuperior);
    return numero;
}
void Resumen(int ventas[][SEMANA]){
    printf("Vendedor\n");
    for(int i=0; i<SEMANA; i++)
        printf("\tdia%d ", i+1);
    
    for(int i=0; i<VENDEDORES; i++){
        printf("V%d", i*100);
        for(int j=0; j<SEMANA; j++)
            printf("\t%d", ventas[i][j]);
        printf("\n");
    }
}
void VentaFinde(int ventas[][SEMANA]){
    int suma=0;
    for(int i=0; i<VENDEDORES; i++)
        for(int j=5; j<SEMANA; j++)
            suma+=ventas[i][j];
    printf("\nFin de Semana: %d ventas", suma);
}