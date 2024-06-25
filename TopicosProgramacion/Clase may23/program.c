#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
#define SUMA 1
#define RESTA 2
#define cIncial 8
#define V_SM 4
#define TODO_OK 15

typedef int (*op)(int,int);
typedef struct{
    void* vec;
    size_t ce;
    size_t capacidad;
    size_t tamañoElemento;
}vectorD;
/*
int calcular(int a, int b, int op){
    int r;
    switch (op)
    {
    case SUMA:
        r = sumar(a,b);
        break;
    
    default:
        break;
    }
}
*/
int sumar(int a, int b){
    return a+b;
}
 int restar(int a, int b){
    return a-b;
}
int calcular(int a, int b, op oper){
    int r;

    r = op(a,b);

    return r;
}

void mostrar(const int *v, size_t ce){
    for(int i=0; i<ce; i++){
        printf("%d ",*v);
        v++;
    }
    printf("\n");
}
void cmpEnteros(const void *a, const void *b, ){
    const int pA = (const int*) a;
    const int pB = (const int*) b;

    return *pA - *pB;
}
 

bool crearVector(vectorD *v, size_t tElemento){

    v->vec = malloc(cInicial * v->tamañoElemento);

    if(!v->vec)
        return false;

    v->ce = 0;
    v->capacidad = cInicial;
    v->tamañoElemento = te;
    return true;
}
void mostrarVector(const vectorD *v){
    void *final = v->vec + v->ce * v->tamañoElemento;
    for(void *i = v->ce; *i < final + *i+=v->tamañoElemento){
        printf("% ", );
    }
}
bool ordenarVectorSeleccion(vectorD *v){
    void *final = v->vec + v->ce * v->tamañoElemento;
    void *ultimo = v->vec + (v->ce - 1) * v->tamañoElemento;
}
bool ampliarVector(vectorD *v){
    size_t cap = v->capacidad * 2;
    void *aux = realloc(v->vec, cap * v->tamañoElemento);

    if(!aux)
        return V_SM;

    v->vec = aux;
    v->capacidad = cap;

    return true;
}
int insertarFinalVector(vectorD *v, const void *element){
    //verificar espacio - Pararse en el final o ampliar - insertar - actualizar contadores
    if(v->ce == v->capacidad){
        if(!ampliarVector(vec))
            return V_SM;

    void *posIncercion = v->vec + c->ce * v->tamañoElemento;

    memcpy(posIncercion, element, v->tamañoElemento);

    v->ce++;

    return TODO_OK;

    }
}
void destruirVector(vectorD *v){
    free(v->vec);
    v->vec = NULL;
    v->ce = 0;
    v->capacidad = 0;
    v->tamañoElemento = 0;
}
int main(){
    /*puntero a funciones*/
    /*
    int r;
    r = calcular(10,20,sumar);  //Funciones CallBack::Vuelve a llamar a main
    printf("%d\n", r);
    return 0;
    */
   /*Ordenamiento*/
   /*
   int vec[] = {2,43,23,3,45,7};
   size_t cantidada = sizeof(vec) / sizeof(int);
   mostrar(vec,cantidada);
   qsort(vec, cantidada, sizeof(int), cmpEnteros)
    */
   /*Vector Dinamico*/

    vectorD v;

    crearVector(&v, sizeof(int)); //Fundamental para la generalidad
    int data = 5;
    insertarFinalVector(&v, &data);

}