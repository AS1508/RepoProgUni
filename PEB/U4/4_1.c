#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define F_RATING "Rating.dat"
#define F_PROMEDIO "Promedio.dat"

struct canales{
    int canal;
    char programa[20];
    float rating;
};
struct promedio{
    int canal;
    float promedio;
};
 
int main(){
    FILE *archivo, *archi2;
    struct canales canal;
    struct promedio promedio;
    int contador=0, cAnterior, canalMasVisto, ban=0;
    float contadorRating=0, ratingMaximo;

    archivo=fopen(F_RATING, "rb");
    archi2=fopen(F_PROMEDIO, "wb");

    if(archivo == NULL || archi2 == NULL){printf("chau\n");exit(1);}
    
    fread(&canal, sizeof(struct canales),1, archivo);
    while (!feof(archivo)){
        contador = 0;
        contadorRating = 0;
        cAnterior=canal.canal;
        while(!feof(archivo) && cAnterior == canal.canal){
            contador++;
            contadorRating+=canal.rating;
            fread(&canal, sizeof(struct canales),1, archivo);
        }

        if(contadorRating<15){
            printf("Canales con menos de 15p de rating\n");
            printf("C%d cuenta con R: %.2fp\n", cAnterior, contadorRating);
        }

        if(ban == 0 || (ratingMaximo < contadorRating)){
            ban = 1;
            canalMasVisto = canal.canal;
            ratingMaximo = contadorRating;
        }

        if(contadorRating > 0){
            promedio.canal = cAnterior;
            promedio.promedio = contadorRating/contador;
            printf("\n\n%d %.3f\n\n", promedio.canal, promedio.promedio);

            fwrite(&promedio, sizeof(struct promedio),1,archi2);
        }

    }
    printf("Canal mas visto: C%d | P:%.2fp", canalMasVisto, ratingMaximo);
    fclose(archivo);
    fclose(archi2);

    return 0;
}