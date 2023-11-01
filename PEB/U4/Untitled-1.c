#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct DATOS{
    int nLegajo;
    char ayp[26];
    int nanio;
    int nSecFa;
    float rSueldo;
};
 
int main(){
    FILE*archivo;
    int i=0;
    struct DATOS d;
    archivo=fopen("Empleados.dat", "rb");
    if(archivo==NULL){printf("chau");exit(1);}
    fread(&d, sizeof(struct DATOS),1, archivo);
    printf("%d | %s | %d | %d | %.2f ", d.nLegajo, d.ayp, d.nanio, d.nSecFa, d.rSueldo);
    while (i<5)
    {
        i++;
        printf("%d | %s | %d | %d | %.2f ", d.nLegajo, d.ayp, d.nanio, d.nSecFa, d.rSueldo);
        fread(&d, sizeof(struct DATOS),1, archivo);
    }
    fclose(archivo);
    return 0;
}