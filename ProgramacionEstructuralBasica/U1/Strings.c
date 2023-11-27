#include<stdio.h>
#include<string.h>

int buscar(char[][100], char[], int);
void ordenar(char[][100], int[50], int);

int main(){
    //1.1.2
    /*
    char vector[200];
    char nombre[]="Sebas", apellido[]=" Martinez";
    
    printf("nombre:");
    fgets(nombre, 100, stdin);
    nombre[strlen(nombre)-1]='\0';
    printf("Apellido:");
    fgets(apellido, 100, stdin);

    strcpy(vector, nombre);
    strcat(vector, " , ");
    strcpy(vector, apellido);
    
    puts(vector);
    */

   //1.1.3

    char alumnosnombre[50][100], nombre[100];
    int alumnodni[50], i=0, cant, x;
    printf("nombre y apellido: ");
    fgets(nombre, 100, stdin);
    nombre[strlen(nombre)-1]='\0';
    while(strcmp(nombre, "FIN")!=0 && i<50){
        strcpy(alumnosnombre[i], nombre);
        printf("ingrese dni: ");
        scanf("%d", &alumnodni[i]);
        printf("nombre y apellido: ");
        fgets(nombre, 100, stdin);
        i++;
    }

    cant=i;
    printf("ingrese nombre a buscar: ");
    fgets(nombre, 100, stdin);
    nombre[strlen(nombre)-1]='\0';
    while(strcmp(nombre, "NOBUSCARMAS")!=0){
        x=buscar(alumnosnombre, nombre, cant);
        if(x!=-1)
            printf("el dni es %d", alumnodni);
        else
            printf("No existe.\n");
    }

    ordenar(alumnosnombre, alumnodni, cant);
    listar(alumnodni, alumnosnombre, cant); //hacer

    return 0;
}

int buscar(char M[][100], char v2[], int cantidad){
    int i=0, pos=-1;
    while((i<cantidad) && (pos=-1)){
        if(strcmp(M[i], v2[i])==0)
            pos=i;
        else
            i++;
    }
    return pos;
}
void ordenar(char M[][100], int dni[50], int cantidad){
    int aux;
    char auxnombre[100];
    for(int i=0; i<cantidad; i++){
        for(int j=0; j<cantidad-1-i; j++){
            if(strcmp(M[i][j], M[i][j+1])>=0){
                aux=dni[i];
                dni[i]=dni[i+1];
                dni[i+1]=aux;

                strcpy(auxnombre, M[i][j]);
                strcpy(M[i][j], M[i][j+1]);
                strcpy(M[i][j+1], auxnombre);
            }
        }
    }
}