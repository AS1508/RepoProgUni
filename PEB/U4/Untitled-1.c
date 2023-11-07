#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct DATOS{
    int a;
    char b[20];
    float c;
};
 
int main(){
    FILE*archivo;
    int i=0;
    struct DATOS d;
    archivo=fopen("Rating.dat", "rb");
    if(archivo == NULL){printf("chau");exit(1);}

    fread(&d, sizeof(struct DATOS),1, archivo);
    while (!feof(archivo))
    {
        
        printf("%d | %s | %.2f \n", d.a, d.b, d.c);
        fread(&d, sizeof(struct DATOS),1, archivo);
    }
    fclose(archivo);
    return 0;
}