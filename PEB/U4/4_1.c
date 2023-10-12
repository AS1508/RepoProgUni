#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define RATING "Rating.dat"
#define PROMEDIO "Promedio.dat"
 
struct Datos{
    int canal;
    char programa[35];
    float rating;
};
struct Promedio
{
    int canal;
    float promedio;
};
 
int main(){
    struct Datos ratings;
    struct Promedio promedio;
    FILE*archivo;
    FILE*archi2;
    int contador, canalAnterior, masVisto, menosR, maximoR, maximoC;
    float total=0;

    archivo=fopen(RATING, "rb");
    archi2=fopen(PROMEDIO, "wb");

    if(archivo==NULL || archi2==NULL){exit(1);}

    fread(&ratings, sizeof(struct Datos),1, archivo);
    while(!feof(archivo)){
        contador=0;
        canalAnterior=ratings.canal;
        while(!feof(archivo) && canalAnterior==ratings.canal){
            total+=ratings.rating;
            contador++;
            }
            if(ratings.rating<15){printf("nro canal y total")} //completar
            if(b=0 || maximoR>ratings.rating){
                b=1;
                maximoC=ratings.canal;
                maximoR=total;
                }
            if(contador!=0){
                promedio.promedio=total/contador;
                promedio.canal=canalAnterior;
                fwrite(&promedio, sizeof(struct Promedio),1, archi2)
            }
        }
    printf("menos rating es");  //completar

    fclose(archivo);
    fclose(archi2);

    return 0;
}