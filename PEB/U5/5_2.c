#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_EMPLEADOS "Empleados.dat"

int calcularCategoria(int, int ,int ,int ,int ,int);
 
struct Empleado{
    int legajo;
    char apellido[15];
    char nombre[15];
    int dia, mes, año;
    int categoria;
}
 
int main(){
    FILE*archivo;
    struct Empleado empleados;
    int bandera=0, dia, mes, año, categoria;

    if(freopen(F_EMPLEADOS, "r+b")==NULL){printf("mefui");exit(1);}

    printf("Ingrese la fecha de hoy:\n-dia:");
    scanf("%d", &dia);
    printf("\n-fecha:");
    scanf("%d", &mes);
    printf("\n-año: ");
    scanf("%d", &año);

    fread(&empleados, sizeof(struct Empleado),1, archivo);

    while (!feof(archivo) && bandera==0){
        categoria=calcularCategoria(empleados.dia, empleados.mes, empleados.año, dia, mes, año);
        empleados.categoria=categoria;
        fseek(archivo, sizeof(strcut empleados)*-1, SEEK_CUR);
        fwrite(&empleados, sizeof(struct Empleados),1,archivo);
        fflush(archivo);
        fread(&empleados, sizeof(strcut empleados),1, archivo);
    }
    fclose(archivo);

    return 0;
}
int calcularCategoria(int diaIngreso, int mesIngreso, int añoIngreso, int diaActual, int mesActual, int añoActual){
    int diaFinal, mesFinal, añoFinal, categoria;
    
    añoFinal=añoActual-añoIngreso;
    mesFinal=mesActual-mesIngreso;
    diaFinal=diaActual-diaIngreso;
    if(diaFinal<0){mesFinal--;}
    if(mesFinal<0){añoFinal--;}

    if(año>=0 && año<2){categoria=1;}else if(años>=2 && años<=5){categoria=2;}else if(años>=6 && años<10){categoria=3;}else if(años>=10){categoria=4;}

    return categoria;
}