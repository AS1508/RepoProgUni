#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct DATOS{
    int a;
    char b[26];
    int c;
    int d;
    float e;
};
 
int main(){
    FILE*archivo;
    int i=0;
    struct DATOS d;
    archivo=fopen("Empleados.dat", "rb");
    if(archivo==NULL){printf("chau");exit(1);}
    //fread(&d, sizeof(struct DATOS),1, archivo);
    //printf("%d | %s | %d | %d | %.2f ", d.nLegajo, d.ayp, d.nanio, d.nSecFa, d.rSueldo);
    while (!feof(archivo))
    {
        fread(&d, sizeof(struct DATOS),1, archivo);
        printf("%d | %s | %d | %d | %.2f \n", d.a, d.b, d.c, d.d, d.e);
        i++;
    }
    fclose(archivo);
    return 0;
}