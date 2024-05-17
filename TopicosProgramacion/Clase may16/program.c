#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//.h
 //Lista de enteros
typedef struct{
    int *vec;
    int size;
}t_listaEnteros;
 //Lista generica
typedef struct{
    int ce;
    void *vec;
    size_t tElementos;
}t_lista;
 //IMPORTANTE :: compare
typedef int (*Cmp)(const void *, const void *); //Prototipo de una funcion
void intercambiar(void *a, void *b, size_t size){
    char aux[size];
    memcpy(aux, a, size); //copiamos en aux lo que este en a en size tamaño
    memcpy(a, b, size);
    memcpy(b, aux, size);
}
///////////////////////////////////////////////////////////////////////////////////
//Ordenamiento
void ordenarBurbujeoint(int *vec, int ce){
    int *ultimo = vec + ce - 1;
    //Ordenamiento con punteros
    for(int i = 0; i < ce, i++)
        for(int *j = vec; j < ultimo-i; j++)
            if(*j< *(j+1))
                intercambiar(j, j+1);

}
void ordenarBurbujeoFloat(float *vec, int ce){
    float *ultimo = vec + ce - 1;
    //Ordenamiento con punteros
    for(int i = 0; i < ce, i++)
        for(float *j = vec; j < ultimo-i; j++)
            if(*j < *(j+1))
                intercambiar(j, j+1);
    
}
void ordenarBurbujeo(t_lista *pl, Cmp cmp){
    void *ultimo = pl->vec + (pl->ce - 1)*pl->tElementos;
    //Ordenamiento con punteros
    for(void *i = pl->vec; i < ultimo, pl->tElementos++)
        for(void *j = i; j < ultimo; j+=pl->tElementos)
            if/*(*j < *(j+1))*/(cmp(j, j+pl->tElementos)<0)
                intercambiar(j, j+pl->tElementos);
    
}
int main(){
    //ordenamiento
        
    return 0;
}

/*
//Algoritmos
    //Seleccion
        seleccionas al primero en posicion y mientras recorre, selecciona cual es el minimo, una vez encontrado 
        el minimo en todo el recorrido intercambia el posicion y el minimo.
    //Insercion
                               //ce// //tElementos///////////funcion para comprarar////////
    //qsort(void *base, size_t nItems, size_t size, int (*Cmp)(const void *, const void *)); //Tarea::checkear esto//
                                                    ///////////////////////////////////////
*/