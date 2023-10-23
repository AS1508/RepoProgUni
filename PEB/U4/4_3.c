#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define F_LLAMADAS "Llamadas.dat"
#define F_COSTOS "Costos.dat"
#define F_GASTOS "Gastos.dat"
#define F_SECTOR "Sector.dat"

struct Llamadas{
    char sector[35];
    int duracion;
    int tipo;
};
struct Costos{
    float local;
    float largaDistancia;
    float celular;
};
struct Gasto{
    int sector;
    float gastos;
};
struct Sector{
    int duracion;
    int tipo;
    float costo;
};

//void Listar();
 
int main(){
    FILE*archivoLlamada, *archivoGasto, *archivoCostos, *archivoSector;
    int duracionLlamada=0, contadorT1=0, contadorT2=0, contadorT3=0;
    struct Llamadas llamadas;
    struct Costos valor;
    char sectorAnterior[35];
    
    archivoLlamada=fopen(F_LLAMADAS, "rb");
    if(archivoLlamada==NULL){printf("Error");exit(1);}
    /*archivoCostos=fopen(F_COSTOS, "rb")
    if(archivoCostos==NULL){printf("Error");exit(1);}
    archivoGasto=fopen(F_GASTOS, "wb")
    if(archivoGasto==NULL){printf("Error");exit(1);}

    fread(&valor, sizeof(struct Costos),1, archivoCostos);*/
    printf("\n\tSector\t|\tTipo de llamada\t|\tDuracion");
    fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
    while(!feof(archivoLlamada)){
        duracionLlamada=0;
        contadorT1=0;
        contadorT2=0;
        contadorT3=0;
        strcpy(sectorAnterior, llamadas.sector);
        while(!feof(archivoLlamada) && strcmp(llamadas.sector,sectorAnterior)==0){
            if(llamadas.tipo==1)
                contadorT1++;
            if(llamadas.tipo==2)
                contadorT2++;
            if(llamadas.tipo==3)
                contadorT3++;
            duracionLlamada+=llamadas.duracion;
            printf("\n\t%s\t%d\t%d", llamadas.sector, llamadas.tipo, duracionLlamada);

            fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
        }
    }
    fclose(archivoLlamada);
    return 0;
}