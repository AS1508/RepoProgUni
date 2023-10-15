#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define F_RATING "Rating.dat"
#define F_PROMEDIO "Promedio.dat"

struct Canales{
    int canal;
    float rating;
    char programa[35];
};
struct Promedio{
    int canal;
    float promedio;
};
 
int main(){
    FILE *archivo, *archi2;
    struct Canales rating;
    struct Promedio promedio;
    int cAnterior, contador=0, maxCanal;
    float totalRating=0, maxRating=0;

    archivo=fopen(F_RATING, "rb");
    archi2=fopen(F_PROMEDIO, "wb");

    if(archi2==NULL || archivo==NULL){printf("mefui");exit(1);}

    fread(&rating, sizeof(struct Canales),1, archivo);
    while(!feof(archivo)){
        contador=0;
        totalRating=0;
        cAnterior=rating.canal;
        while(!feof(archivo) && cAnterior==rating.canal){
            contador++;
            totalRating+=rating.rating;
            fread(&rating, sizeof(struct Canales),1, archivo);
        }
        if(totalRating<15){printf("Ratings menores a 15p\n C%d | %.2fp", cAnterior, totalRating);}
        if(totalRating>=maxRating){
            maxCanal=cAnterior;
            maxRating=totalRating;
        }
        if(contador!=0){
            promedio.canal=cAnterior;
            promedio.promedio=totalRating/contador;
            fwrite(&promedio, sizeof(struct Promedio),1, archi2);
        }
    }
    printf("Canal Mas visto:\n\tC%d | %.2fp", maxCanal, maxRating);

    fclose(archivo);
    fclose(archi2);
    return 0;
}