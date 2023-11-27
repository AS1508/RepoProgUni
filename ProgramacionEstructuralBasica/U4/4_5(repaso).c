#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_EVENTO "EVENTOS.dat"
#define F_PROMEDIO "PROMEDIO.dat"

struct EVENTOS{
    char codigo[10];
    int puerta;
    int cantidad;
};
struct PUERTA{
    int puerta;
    float promedio;
};

int main(){
    FILE*archivo, *temporal;
    struct EVENTOS registro, rAnterior;
    struct PUERTA promedio;
    char cAnterior[10], eventoMenor[14];
    int b = 0, espectadores = 0, suma[14] = {0}, contador[14] = {0};
    float promedio[14] = {0};

    archivo = fopen(F_EVENTO, "rb");
    if(archivo == NULL){printf("cha");exit(1);}

    fread(&registro, sizeof(struct EVENTO),1,archivo);
    while (!feof(archivo)){
        //duplico estructura
        rAnterior = registro;
        espectadores = 0;
        while (!feof(archivo) && (strcmp(rAnterior.codigo, rAnterior.codigo)==0)){
            espectadores+=registro.cantidad;
            suma[registro.puerta-1]+=registro.cantidad;
            contador[registro.puerta-1]++;
            fread(&registro, sizeof(struct EVENTO),1, archivo);
        }

        //punto a
        printf("evento %s | %d espectadores\n", registro.codigo, espectadores);

        //punto b
        if(b == 0 || espectadores < minEspectadores){
            b = 1;
            minEspectadores = espectadores;
            strcpy(eventoMenor, rAnterior.codigo);
        }
    }
    fclose(archivo);
    printf("\nEvento con menor cantidad de espectadores :: E-%s | %desp", eventoMenor, minEspectadores);

    temporal = fopen(F_PROMEDIO, "wb");
    if(temporal == NULL){printf("error");exit(1);}

    for(int i=0; i<15; i++){
        if(contador!=0){
            promedio.puerta = i+1;
            promedio.promedio = suma[i]/contador[i];
        }else{
            promedio.puerta = i+1;
            promedio.promedio = 0;
        }
        fwrite(&promedio, sizeof(struct PUERTA),1, temporal);
    }
    fclose(temporal);
    return 0;
}