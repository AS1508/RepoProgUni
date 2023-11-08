#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct DATOS{
    char a[20];
    int b;
    int c;
};
 
int main(){
    FILE*archivo;
    int i=0;
    struct DATOS d;
    archivo=fopen("Llamadas.dat", "rb");
    if(archivo == NULL){printf("chau");exit(1);}

    fread(&d, sizeof(struct DATOS),1, archivo);
    while (!feof(archivo))
    {
        
        printf("%s | %d | %d \n", d.a, d.b, d.c);
        fread(&d, sizeof(struct DATOS),1, archivo);
    }
    fclose(archivo);
    return 0;
}