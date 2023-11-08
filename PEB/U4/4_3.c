#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define F_LLAMADAS "Llamadas.dat"
#define F_COSTOS "Costos.dat"
#define F_GASTOS "Gastos.dat"
#define F_SECTOR "Sector.dat"

struct Llamadas{
    char sector[15];
    int duracion;
    int tipo;
};
struct Costos{
    float local;
    float largaDistancia;
    float celular;
};
struct Gastos{
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
    FILE *archivoLlamada, *archivoCostos, *archivoGastos, *archivoSector;
    struct Llamadas llamadas;
    struct Costos costo;
    struct Gastos resumen;
    char sAnterior[15], maximaSector[15];
    int ban = 0, contadorLlamada1 = 0, contadorLlamada2 = 0, contadorLlamada3 = 0;
    int contadorDuracion1 = 0, contadorDuracion2 = 0, contadorDuracion3 = 0, duracionSector, maximaDuracion;

    archivoLlamada = fopen(F_LLAMADAS, "rb");
    archivoCostos = fopen(F_COSTOS, "rb");
    archivoGastos = fopen(F_GASTOS, "wb");
    //archivoSector = fopen(F_SECTOR, "wb");

    if(archivoLlamada == NULL || archivoCostos == NULL || archivoGastos == NULL /*|| archivoSector == NULL*/){
        printf("chao");
        exit(1);
    }

    fread(&costo, sizeof(struct Costos),1, archivoCostos);
    fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
    while (!feof(archivoLlamada)){
        strcpy(sAnterior, llamadas.sector);
        contadorLlamada1 = 0;
        contadorLlamada2 = 0;
        contadorLlamada3 = 0;
        contadorDuracion1 = 0;
        contadorDuracion2 = 0;
        contadorDuracion3 = 0;
        while((!feof(archivoLlamada)) && (strcmp(sAnterior, llamadas.sector)==0)){
            if(llamadas.tipo == 1){contadorLlamada1++; contadorDuracion1+=llamadas.duracion;}
            if(llamadas.tipo == 2){contadorLlamada2++; contadorDuracion2+=llamadas.duracion;}
            if(llamadas.tipo == 3){contadorLlamada3++; contadorDuracion3+=llamadas.duracion;}
            fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
        }

        duracionSector = contadorDuracion1 + contadorDuracion2 + contadorDuracion3;
        printf("-Sector %s \n.tipo 1: %d llamadas\n.tipo 2: %d llamadas\n.tipo 3: %d llamadas\n", sAnterior, contadorLlamada1, contadorLlamada2, contadorLlamada3);

        if(ban == 0 || maximaDuracion < duracionSector){
            ban = 1;
            strcpy(maximaSector, sAnterior);
            maximaDuracion = duracionSector;
            printf("Nuevo maximo: S_%s | D:%dsg \n", maximaSector, maximaDuracion);
        }
    }

    fclose(archivoLlamada);
    fclose(archivoCostos);
    fclose(archivoGastos);
    //fclose(archivoLlamada);


    return 0;
}