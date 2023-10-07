#include<stdio.h>
#include<stdlib.h>

int CargaLibros(int[] int);
void Venta();
void Listados();
int Busqueda(int[], int, int);
int Lee(int, int);
int Valida(int, int, int);
void Ordena();


int main(){
    int ventas[100][7], libros[100], cantidad;
    
    //Carga de Libros
    cantidad = CargaLibros(libros, 100);
    printf("tamos");
    exit(1);
    //Venta
    Venta(ventas, cantidad, libros);
    //Listados (Outputs)
    Listados(ventas, cantidad);
    return 0;
}
int CargaLibros(int libro[], int maximo){
    int codigo, pos, i;

    printf("codigo: ");
    codigos=Valida(100, 999);
    
    while(codigo!=0){
        libro[i] = codigo;
        if(codigo){printf("\n\tCarga Exitosa\n");}
        i++;
        do{
            printf("codigo: ");
            codigos =Valida(100, 999);
            pos=Busqueda(libros, pos, maximo);
            if(pos==-1){printf("Libros existente.\n")}
        }while(pos!=-1)
    }
    return i;
}
int Valida(int limInferior, int limSuperior){
    int numero;
    do{scanf("%d", &numero);}while(numero<limInferior || numero>limSuperior);
    return numero;
}
int Buqueda(int DB[], int x, int cantidad){
    int i=0, pos=-1;
    while(i<cantidad && pos==-1){
        if(DB[i]==x)
            pos = i;
        else
            i++;
    }
    return pos;
}/*
void Venta(int venta[][7], int cantidad, int libros[]){
    int codigos, cantidad, sucursal;
    
    printf("codigo: ");
    codigos=Valida(100, 999);
    while(codigos!=0){
        printf("Sucursal: ");
        sucursal=ValidaSucursal(10, 20, 30, 40, 50, 60, 70);
        printf("Cantidad: ");
        do{scanf("%d", &cantidad);}while(cantidad<0);
        
        Venta[codigos][sucursal] += cantidad;

    }
}*/