#include<stdio.h>

struct alumno
{
    int dni;
    char nombreapellido[80];
    int nota1;
    int nota2;
    float promedio;
};

int ingreso(struct alumno[], int);
void resultado(struct alumno[], int);
void promociones(struct alumno[], int);


int main(){
    int cant;

    struct alumno alumnos[80];
    cant = ingreso(alumnos, 80);
    resultado(alumnos, cant);
    promociones(alumnos, cant);
    return 0;
}
int ingreso(struct alumno vec[], int n){
    int i=0, dni;
    printf("dni: ");
    scanf("%d", &dni);
    while(dni!=0 && i<n){
        vec[i].dni=dni;
        fflush(stdin);
        printf("Nombre y Apellido: ");
        gets(vec[i].nombreapellido);
        printf("primer nota: ");
        scanf("%d", &vec[i].nota1);
        printf("segunda nota: ");
        scanf("%d", &vec[i].nota2);
        vec[i].promedio=(vec[i].nota1+vec[i].nota2)/2;
        i++;
        printf("dni: ");
        scanf("%d", &dni);
        
    }
    return i;
}
void resultado(struct alumno vec[], int n){
    int i, contadorA=0, contadorD=0;
        for(i=0; i<n; i++){
        if(vec[i].nota1>=4 && vec[i].nota2>=4){
            contadorA++;
        }else{
            contadorD++;
        }
    }
    printf("Alumnos Aprobados: %d", contadorA);
    printf("Alumnos desaprobados: %d", contadorD);
}
void promociones(struct alumno vec[], int n){
    int i;
    printf("Alumnos Promocionados: %d\n");
    for(i=0; i<n; i++){
        if(vec[i].nota1>=7 && vec[i].nota2>=7){
            printf("_%c \n_DNI: %d \n_promedio: %.2f ", vec[i].nombreapellido, vec[i].dni, vec[i].promedio);
        }
    }
}
