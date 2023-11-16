#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct{
    int a;
    int b;
    int c;
}e;
struct DATOS{
    int a;
    char b[10];
    char c[10];
    e e;
    int d;
};
 
int main(){
    FILE*archivo;
    int i=0;
    struct DATOS d;
    archivo=fopen("empleados.dat", "rb");
    if(archivo == NULL){printf("chau");exit(1);}

    fread(&d, sizeof(struct DATOS),1, archivo);
    while (!feof(archivo)){
        printf("%d | %s | %s | %d | %d | %d | %.2f \n", d.a, d.b, d.c, d.e.a, d.e.b, d.e.c, d.d);
        fread(&d, sizeof(struct DATOS),1, archivo);
    }
    fclose(archivo);
    return 0;
}