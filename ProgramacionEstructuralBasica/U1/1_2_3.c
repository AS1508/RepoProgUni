#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int Busqueda(char[][50], char[], int);
 
int main(){
    char alumnos[50][50], alumno[50];
    int dni[50], i=0, cant, pos;

    printf("Nombre de alumno: ");
    fgets(alumno, 50, stdin);
    alumno[strlen(alumno)-1]='\0';
    while((strcmp(alumno, "fin")!=0 ) && (i<50)){
        strcpy(alumnos[i], alumno); 
        printf("\nDNI: ");
        scanf("%d", &dni[i]);
        i++;
        
        printf("Nombre: ");
        getchar();
        gets(alumno);
    }

    cant=i;
    system("cls");
    
    printf("\tBuscador\n\nAlumno: ");
    fgets(alumno, 50, stdin);
    alumno[strlen(alumno)-1]='\0';
    while(strcmp(alumno, "f")!=0){
        pos=Busqueda(alumnos, alumno, cant);
        if(pos!=-1){
            printf("DNI: %d", dni[pos]);
        }else{
            printf("\nNo se encuentra Registrado.");
        }
        
        printf("\n\nAlumno: ");
        fgets(alumno, 50, stdin);
        alumno[strlen(alumno)-1]='\0';
    
    }
    printf("Proceso Finalizado");

    Listado(); //hacer
    return 0;
}


int Busqueda(char DB[][50], char x[], int cantidad){
    int pos=-1, i=0;
    
    while(i<cantidad && pos==-1){
        if(strcmp(DB[i], x)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}