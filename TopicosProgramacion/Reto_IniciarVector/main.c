#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define TAM 10;
#define SIN_ESPACIO 1;
#define DUPLICADO 2;
#define OK 77;
 
typedef struct
{
    int ce;
    int vec[TAM];
}tVector;
 
void Init(tVector);
void Show(const tVector);
 
int main(){
    tVector v;

    Init(&v);
    Show(&v);

    return 0;
}

void Init(tVector *v){
    //Iniciar en 0 (v->ce = 0;)
}

bool Insert(tVector *v, int value){
    
    if(v->ce == TAM)
        return false;
    v->vec[v->ce] = value;
}
                //Tarea eliminar (al principio-final-elegido) / Busqueda Binaria / Burbujeo
int InsertOrdenado(tVector *vec, int value){
    int pos;
    if(vec->ce == TAM)
        return SIN_ESPACIO;

    for(int i = 0; i<vec->ce && vec[i]<=value; i++){
        if(value == vec->ce[i])
            return DUPLICADO;

        pos = i;
    }

    for(int i = vec->ce; i>pos; i--)
        vec->vec[i+1] = vec->vec[i];

    vec->vec[pos] = value;
    vec->ce++;
    return OK;

    
}
void Show(const tVector *v){
    for(int i = 0; i<v->ce; i++){
        printf("%d", v->vec[i]);
    }
}
