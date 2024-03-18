#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_CANTIDAD 11

void IngresoA(int[], int);
int SumaC(int[], int[], int, int);
int BusquedaF(int[], int, int);
void MuestraH(int[], int[], int[], int[], int[], int, int);


int main(){
    int va[MAX_CANTIDAD]={0},vb[MAX_CANTIDAD]={0},vc[MAX_CANTIDAD]={0},vd[MAX_CANTIDAD]={0}, ve[MAX_CANTIDAD];
    int aux=0, max=0, pos=0, posVC=0, x=0, cantidadVE=0, i=0; 

    /*(a)*/
    IngresoA(va, 10);

    /*(b)*/
    for(int i=0; i<10; i++)
        vb[i]=sqrt(va[i]); 

    /*(c)*/
    for(int i=0; i<10; i++)
        vc[i]=SumaC(va, vb, 10, i);

    /*(d)*/
    for(int i=10; i>=0; i--){
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
    if(posVC!=-1){
        printf("posicion: %d", posVC);
    }else{
        printf("No se encuentra.\n");
    }

    /*(g)*/
    while(i<10){
        if(va[i]<0){
            ve[cantidadVE]=va[i];
            cantidadVE++;
        }
        i++;
    }

    /*(h)*/
    MuestraH(va, vb, vc, vd, ve, 10, cantidadVE);

    return 0;
}

void IngresoA(int vector[], int cantidad){
    int num, i=0;
    do{
        printf("Numero: ");
        scanf("%d", &num);
        vector[i]=num;
        i++;
    }while(i<cantidad);
}
int SumaC(int vectorA[], int  vectorB[], int cantidad, int i){
    int numero;
    numero = vectorA[i]+vectorB[i];
    return numero;
}
int BusquedaF(int DB[], int x, int cantidad){
    int pos=-1, i=0;
    while(i<cantidad && pos==-1){
        if(x==DB[i]){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
void MuestraH(int vectorA[], int vectorB[], int vectorC[], int vectorD[], int vectorE[], int cantidad, int cantidadVE){
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
    for(int i=0; i<cantidadVE; i++)
        printf(" [%d] ", vectorE[i]);
}