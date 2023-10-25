#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_CANTIDAD 11

void IngresoA(int[], int);
int SumaC(int[], int[], int);
int BusquedaF(int[], int, int);
void MuestraH(int[], int[], int[], int[], int[], int);


int main(){
    int va[MAX_CANTIDAD]={0},vb[MAX_CANTIDAD]={0},vc[MAX_CANTIDAD]={0},vd[MAX_CANTIDAD]={0}, ve[MAX_CANTIDAD]={0};
    int aux=0, max=0, pos=0, posVC=0, x=0; 

    /*(a)*/
    IngresoA(va, 10);

    /*(b)*/
    for(int i=0; i<10; i++)
        vb[i]=sqrt(va[i]); 

    MuestraH(va, vb, vc, vd, ve, 10);
    exit(1);

    /*(c)*/
    for(int i=0; i<10; i++)
        vc[i]=SumaC(va, vb, 10);

    /*(d)*/
    for(int i=10; i>0; i--){
        vd[i]=vc[aux];
        aux++;
    }

    /*(e)*/
    for(int i=0; i<10; i++){
        if(va[i]>max){
            pos=i;
            max=va[i];
        }
    }
    printf("\tMAXIMO\nPosicion: %d\ncantidad: %d\n\n", pos, max);

    /*(f)*/
    printf("\tBUSQUEDA\nValor a buscar: ");
    scanf("%d", &x);
    posVC=BusquedaF(vc, x, 10);
    if(pos!=-1){
        printf("posicion: %d", posVC);
    }else{
        printf("No se encuentra.\n\n");
    }

    /*(g)*/
    for(int i=0; i<10; i++){
        if(va[i]<0)
            ve[i]=va[i];
    }

    /*(h)*/
    MuestraH(va, vb, vc, vd, ve, 10);

    return 0;
}

void IngresoA(int vector[], int cantidad){
    int num, i=0;
    do{
        printf("Numero: ");
        scanf("%d", &num);
        vector[i]=num;
        i++;
    }while(i<10);
}
int SumaC(int vectorA[], int  VectorB[], int cantidad){
    //hacer
}
void MuestraH(int vectorA[], int vectorB[], int vectorC[], int vectorD[], int vectorE[], int cantidad){
    printf("\n\nA: ");
    for(int i=0; i<cantidad; i++)
        printf(" [%d] ", vectorA[i]);
    printf("\nB: ");
    for(int i=0; i<cantidad; i++)
        printf(" [%d] ", vectorB[i]);
    printf("\nC: ");
    for(int i=0; i<cantidad; i++)
        printf(" [%d] ", vectorC[i]);
    printf("\nD: ");
    for(int i=0; i<cantidad; i++)
        printf(" [%d] ", vectorD[i]);
    printf("\nE: ");
    for(int i=0; i<cantidad; i++)
        printf(" [%d] ", vectorE[i]);
}