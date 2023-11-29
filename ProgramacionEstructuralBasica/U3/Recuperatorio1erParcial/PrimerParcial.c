#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define F_DOCENTES "docentes.dat"
 
typedef struct{
    int legajo;
    char nombreAPellido;
    float valorHora;
    float horasTrabajadas;
    float sueldo;
}DOCENTE;
typedef struct{
    int sumaEncontrados;
    int sumaNoEncontrados;
    float promedioEncontrados;
    float promedioNoEncontrados;
}PROMEDIO;

void Carga(DOCENTE[]);
void Actualizar(DOCENTE[], int);
int Busqueda(DOCENTE[], int, int);
 
int main(){
    FILE*archivo;
    DOCENTE docentes[3500];
    PROMEDIO promedio;
    int i = 0, cantidad, legajo, departamento, horas, posicion, horas_depto[10] = {0}, b=0, mHoras;

    cantidad = Carga(docentes);
        

    printf(">>Legajo\n");
    scanf(">%d", &legajo);

    while (legajo != 0){
        posicion = Busqueda(docentes, legajo, cantidad);

        if(posicion != -1){
            do{
                printf(">>Departamento\n");
                scanf(">%d", &departamento);
            }while(departamento<1 || departamento>10);

            do{
                printf(">>Horas Trabajadas\n");
                scanf(">%d", &horas);
            }while(horas<=0);

            promedio.sumaEncontrados++;
            horas_depto[posicion] += horas;
            docentes[posicion].legajo = legajo;
            docentes[posicion].horasTrabajadas += horas;
            docentes[posicion].sueldo = docentes[posicion].horasTrabajadas * docentes[posicion].valorHora;
            system("cls");
            printf("\n\n\tLEGAJO ACTUALIZADO\n\n");
        }else{
            promedio.sumaNoEncontrados++;
            system("cls");
            printf("\n\n\tLEGAJO NO ENCONTRADO\n\n");
        }

        for(int i = 0; i<10; i++)
            if(b == 0 || horas_depto[i] >= mHoras)
                mHoras = horas_depto[i];

        printf(">>Legajo\n");
        scanf(">%d", &legajo);
    }
    Actualizar(docentes, cantidad);

    printf("\n>>>Departamento con mayores horas trabajadas\n");
    for(int i = 0; i<10; i++)
        if(mHoras == horas_depto[i])
            printf("_Departamento-%d | %dhs\n", i+1, horas_depto[i]);

    promedio.promedioEncontrados = promedio.sumaEncontrados/cantidad;
    promedio.promedioNoEncontrados = promedio.sumaNoEncontrados/cantidad;

    printf("\n\n>>>Promedio\n");
    printf("_Legajos Encontrados: %d\n", promedio.promedioEncontrados);
    printf("_Legajos No Encontrados: %d\n", promedio.promedioNoEncontrados);
    return 0;
}
int Carga(DOCENTE docentes[]){
    FILE*archivo;
    DOCENTE aux;
    int i = 0;

    archivo = fopen(F_DOCENTES, "rb");
    fread(&aux, sizeof(DOCENTE),1,archivo);
    while (!feof(archivo)){
        docentes[i] = aux;
        i++;
        fread(&aux, sizeof(DOCENTE),1,archivo);
    }
    fclose(archivo);

    return i;
}
int Busqueda(DOCENTE docentes[], int x, int cantidad){
    int pos = -1, i = 0;

    while (pos == -1 && i<cantidad){
        if(docentes[i] == x){
            pos = i;
        }else{
            i++;
        }
    }
    return pos;
}
void Actualizar(DOCENTE docentes[], int cantidad){
    FILE*archivo;

    archivo = fopen(F_DOCENTES, "wb");
    for(int i = 0; i<cantidad; i++)
        fwrite(&docentes[i], sizeof(DOCENTE),1, archivo);
    fclose(archivo);
}
