//5.2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_EMPLEADOS "empleados.dat"
typedef struct{
    int dia;
    int mes;
    int anio;
}INGRESO;
 
struct EMPLEADOS{
    int legajo;
    char apellido;
    char nombre;
    INGRESO ingreso;
    int categoria;
};
 
int CATEGORIA(int, int, int, int, int, int);
void OrdenAscendente();
void Muestra(struct EMPLEADOS);
int main(){
    FILE*archivoEmpleados;
    struct EMPLEADOS empleado;
    int anio, mes, dia;
    int categoria;

    archivoEmpleados = fopen(F_EMPLEADOS, "r+b");
    if(archivoEmpleados == NULL){exit(1);}

    printf("dia: ");
    scanf("%d", &dia);
    printf("mes: ");
    scanf("%d", &mes);
    printf("anio: ");
    scanf("%d", &anio);

    fread(&empleado, sizeof(struct EMPLEADOS),1, archivoEmpleados);
    while(!feof(archivoEmpleados)){
        empleado.categoria=CATEGORIA(empleado.ingreso.dia, empleado.ingreso.mes, empleado.ingreso.anio, dia, mes, anio);
        //empleado.categoria = categoria;
        fseek(archivoEmpleados, sizeof(struct EMPLEADOS)*-1, SEEK_CUR);
        fwrite(&empleado, sizeof(struct EMPLEADOS),1, archivoEmpleados);
        fflush(archivoEmpleados);
        fread(&empleado, sizeof(struct EMPLEADOS),1, archivoEmpleados);
    }
    fclose(archivoEmpleados);
    
    /*5.3*/
    OrdenAscendente();
    Muestra(empleado);

    return 0;
}
int CATEGORIA(int diaIngreso, int mesIngreso, int anioIngreso, int dia, int mes, int anio){
    int diaFinal, mesFinal, anioFinal, categoria;
    
    anioFinal=anio-anioIngreso;
    mesFinal=mes-mesIngreso;
    diaFinal=dia-diaIngreso;
    if(diaFinal<0){mesFinal--;}
    if(mesFinal<0){anioFinal--;}

    if(anioFinal>=0 || anioFinal<=2){
        categoria = 1;
        }else if(anioFinal>=3 || anioFinal<=5){
            categoria = 2;
            }else if(anioFinal>=6 || anioFinal<=10){
                categoria = 3;
                }else if(anioFinal>10){
                    categoria = 5;
                    }

    return categoria;
}
void OrdenAscendente(){
    FILE*archivo;
    struct EMPLEADOS empleados, auxiliar;
    int primerRecorrido = 1, ultimoIntercambio, contador, ordenado;
    
    if((archivo = fopen(F_EMPLEADOS, "r+b")) == NULL){exit(1);}

    do{
        ordenado = 1;
        fread(&auxiliar, sizeof(struct EMPLEADOS),1, archivo);
        contador = 1;
        while ((!feof(archivo) && primerRecorrido) || (!primerRecorrido && contador<=ultimoIntercambio)){
            fread(&empleados, sizeof(struct EMPLEADOS),1, archivo);
            contador++;
            if(!feof(archivo)){
                if(auxiliar.legajo<empleados.legajo){
                    fseek(archivo, sizeof(struct EMPLEADOS)*-2, SEEK_CUR);
                    fwrite(&empleados, sizeof(struct EMPLEADOS),1, archivo);
                    fwrite(&auxiliar, sizeof(struct EMPLEADOS),1, archivo);
                    fflush(archivo);
                    ultimoIntercambio = contador;
                    ordenado = 0;
                }else{
                    auxiliar = empleados;
                }
            }
        }
        primerRecorrido = 0;
        rewind(archivo);
    }while(!ordenado);
    fclose(archivo);

}

void Muestra(struct EMPLEADOS empleado){
    FILE* archivo;

    if ((archivo = fopen(F_EMPLEADOS, "rb")) == NULL) {
        printf("No se pudo abrir el archivo de empleados.\n");
        exit(1);
    }

    printf("\nContenido del archivo de empleados:\n");
    fread(&empleado, sizeof(struct EMPLEADOS), 1, archivo);
    while (!feof(archivo)){
        printf("Legajo: %d, Apellido: %c, Nombre: %c, Categoria: %d, Ingreso: %02d/%02d/%04d\n",empleado.legajo, empleado.apellido, empleado.nombre, empleado.categoria,empleado.ingreso.dia, empleado.ingreso.mes, empleado.ingreso.anio);
        fread(&empleado, sizeof(struct EMPLEADOS), 1, archivo);
    }

    fclose(archivo);
}