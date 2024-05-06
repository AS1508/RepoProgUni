#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 10
 
void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
}
void swap2(int **pa, int **pb) {
    int *z = *pa;
    *pa = *pb;
    *pb = z;
}
void matrizCrear(size_t TAM, unsigned int f, unsigned int co);
int main(){

    //REPASO DE PUNTERO - PUNTERO A PUNTERO
/*
    int a = 7;
    int b = 5;

    printf("%d - %d\n",a, b);

    //aca necesito los punteros
    swap(&a,&b);
    
    printf("%d - %d\n",a, b);

    int *pa = &a;
    int *pb = &b;

    printf("%d - %d\n",*pa, *pb);

    //aca ya tenemos los punteros
    swap2(pa,pb);
    
    printf("%d - %d\n",*pa, *pb);
*/
    //MEMORIA ESTATICA
/*
    int vec[TAM]; // memoria estatica
    int *p, *paux;

    //IMPORTANTE :: toda memoria pedida debe ser inicializada

        //Malloc
    p = (int*)malloc(sizeof(int)*TAM) //memory allocation :: cantidad de bytes que le pido al SO.
    //recomendable no mover el puntero de inicio de P (desaprobado)
        //Realloc
    paux = (int*)realloc(p, sizeof(int)*100);   
    if(paux)
        p = paux;   //para cambiar la direccion de memoria para reubicar el puntero y liberar ese espacio cambiado
    
        //Calloc
    //void *calloc(size_t, seize_t)     //


    free(p); //Libera memoria pedida en malloc
    
    p = NULL; //recomendable
*/

                                        //APRENDER TDA Y PUNTEROS BIEN

        //Matrices

    int mat[2][4] = {{1,2,3,4},{5,6,7,8}};
    
    return 0;
}

int void** matrizCrear(size_t TAM, unsigned int f, unsigned int c){
    //va a devolver un putero de punteros
    int void **m = (int void**)malloc(sizeof(int void*)*f);

    if(!m)
        return NULL;

    int int ** f += m;
    for(int i = 0; i < f; i++){
        *i = (int*)malloc(sizeof(int)*co);
        if(*i == NULL)
    }
}