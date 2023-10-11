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
    int canalAnterior, masVisto, menosR, maximoR;

    archivo=fopen(RATING, "rb");
    archi2=fopen(PROMEDIO, "wb");

    if(archivo==NULL || archi2==NULL){exit(1);}

    fread(&ratings, sizeof(struct Datos),1, archivo);
    while(!feof(archivo)){
        canalAnterior=ratings.canal;
        while(!feof(archivo) && canalAnterior==ratings.canal){
            if(ratings.rating<15){menosR=ratings.rating;}
            if()
        }

    }
    return 0;
}