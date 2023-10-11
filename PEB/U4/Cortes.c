#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_EMPLEADOS "Empleados.dat"

struct Persona
{
    char nombre[35];
    int categoria;
};

int main(){
    int codigoAnterior, registro, cantidadDeEmpleados=0;
    struct Persona persona;

    archivo=fopen(F_EMPLEADOS, "rb");
    if(archivo==NULL){
        printf("Error.");
        exit(1);
    }
    fread(&persona, sizeof(struct Persona), 1, archivo);
    printf("\n\tEmpleado | Categoria");
    while(!feof(archivo)){
        codigoAnterior = persona.categoria;
        x=0;
        do{
            x++;
            fread(&persona, sizeof(struct Persona), 1, archivo);
        }while(!feof(archivo) && codigoAnterior==persona.categoria);
        cantidadDeEmpleados = x;
        printf("_%s | %d", persona.nombre, persona.categoria);
    }
    printf("\nSe encontraron %d empleados", cantidadDeEmpleados);
    return 0;
}

/*Se pide iun programa que dado un archivo llamao empleados de un registro
    char nombre;
    int cat;
Se pide imprimir un titulo por cada categoria y listar por categoria
los empleados.
finalmemte informar la canidad de empleados
*/  