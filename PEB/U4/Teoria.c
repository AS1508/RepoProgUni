#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
 
struct PERSONA{
    int nLegajo;
    char ayp[26];
    int nanio;
    int nSecFab;
    float rSueldo;
};

int main(){
    FILE*archivo;
    struct PERSONA per;
    int antSecFab, contTotal=0, conSector=0;

    archivo=fopen("Empleados.dat", "rb");
    if(archivo==NULL){printf("mefui");exit(1);}

    contTotal=0;
    fread(&per, sizeof(struct PERSONA),1, archivo);
    while(!feof(archivo)){
        printf("Test");
        antSecFab=per.nSecFab;
        conSector=0;
        do{
            conSector++;
            fread(&per, sizeof(struct PERSONA),1, archivo);
        }while(!feof(archivo) && per.nSecFab == antSecFab);
        contTotal+=conSector;
        printf("La cantidad de empleados del sector %d es %d", antSecFab, conSector);

    }
    fclose(archivo);
    printf("\nLa cantidad de empleados que tiene la empresa es %d", contTotal);

    return 0;
}