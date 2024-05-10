#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TODO_OK 0
#define SIN_MEM 1
#define TAM 10
#define NUEVO_TAM 20
#define TAM_M 4
 
void iniciarVector(int *p, size_t ce){
    int *q = p + ce;
    while(q >= p){
        *q = q-p;
        q--;
    }
}
 
void mostrarVector(const int *p, size_t ce){
    for(int i = 0; i < ce; i++){
        printf("%d", *p);
        p++;
    }
}
 
void initParteVector(int *p, size_t ce, size_t posicion){
    int *q = p + inicio;
    while(q < p + ce){
        *q = q-p;
        q++;
    }
}
 

 //la matrices estaticas son arrays a las que le digo que tengo que tener mas de una posicion
void mostrarMatriz(const int *mat, int orden, /*const int m[orden][orden+1]*/){ //recorda que las funciones de muestra se mandan con const
    for(int i = 0; i < orden; i++){
        for(int j = 0; j < orden; j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
}
int calcularDiagonal(int ** m, int orden, /*int m[][orden]*/){
    int suma = 0;
    for(int i = 0; i < orden; i++){
            suma += m[i][i];
    }
    return suma;
}
int calcularDiagonalSecundaria(int orden, int m[][orden]){
    int suma = 0;
    for(int i = 0; i < orden; i++){
            suma += m[i][orden-1-i];
    }
    return suma;
}
//elementos que estan por encima de la diagonal superior o inferior
int sumaTriangularSuperiorDiagSec(int orden, int m[]){
    int suma = 0;
    for(int i = 0; i < orden-1; i++){
        for(int j = 0, j < orden-1-i; j++){
            suma += m[i][j];
        }
    }
    return suma;
}
 

 
void**crearMatriz(size_t tamElem, size_t filas, size_t columnas){
    void **mat = malloc(sizeof(void*)*filas);
    if(!mat)
        return NULL;
    
    void **ultimo = mat + filas - 1;
    void **fin = mat + filas;

    for(void **i = mat; i<ultimo; i++){
        *i = malloc(tamElem*columnas);
        if(!*i){
            while(*i >= mat){
                free(*i);
                i--;
            }
            free(mat);

            return NULL;
        }
    }
    return mat;
}
void iniciarMatriz(int**mat, int orden){
    for(int i = 0; i < orden; i++){
        for(int j = 0; j < orden; j++){
            mat[i][j] = i + orden*j;
        }
    }
}
void**destruirMatriz(void**mat, size_t filas){
    void **fin = mat+filas;
    for(void**i = mat; i<fin; i++){
        free(*i);
    }
    return mat;
}
int main(){
    /* //Memoria Dinamica//
    int *p = (int*),malloc(sizeof(int)*TAM);
    
    int *auxP = (int*)realloc(p, sizeof(int)*NUEVO_TAM);
    if(!auxP){
        free(p);
        return SIN_MEM;
    }
    
    free(p);

    p = auxP;
 
     iniciarVector(p, TAM);
    // mostrarVector(p, TAM);
    initParteVector(auxP, TAM, NUEVO_TAM);
    mostrarVector(auxP, NUEVO_TAM);
 
    free(p);
    */
        //Matriz estatica y dinamica//

   int matriz[][] = //mEstatica
   {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
   };
   
   //mostrarMatriz(TAM_M, matriz);
   //calcularDiagonal(TAM_M, matriz);
   //diagSec
   //triango

    //forma correcta de declarar -> int (*m)[TAM];
   //int mDinamica = (int*)malloc(sizeof(int)*TAM_M*TAM_M);
    int **matriz = (int**)crearMatriz(sizeof(int), TAM_M, TAM_M);
    if(!matriz){
        return SIN_MEM;
    }
    iniciarMatriz(matriz, TAM_M);

    //mostrarMatriz(TAM_M, matriz);
    //calcularDiagonal(TAM_M, matriz);
   //diagSec
   //triango

    destruirMatriz(matriz, TAM_M);
    return TODO_OK;
}