#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define F_LLAMADAS "LLAMADAS.dat"
#define F_COSTOS "COSTOS.dat"
#define F_GASTOS "Gastos.dat"
#define DAT ".dat"

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
    float gastosTipo1;
    float gastosTipo2;
    float gastosTipo3;
};
struct Sector{
    int duracion;
    int tipo;
    float costo;
};

void Listar(struct Gastos);

int main(){
    FILE *archivoLlamada, *archivoCostos, *archivoGastos, *archivoSector;
    struct Llamadas llamadas;
    struct Costos costo;
    struct Gastos resumen;
    struct Sector sector;
    char sAnterior[15], maximaSector[15], archivo[15];
    int ban = 0, contador = 0, contadorLlamada1 = 0, contadorLlamada2 = 0, contadorLlamada3 = 0;
    int contadorDuracion1 = 0, contadorDuracion2 = 0, contadorDuracion3 = 0, duracionSector, maximaDuracion;

    archivoLlamada = fopen(F_LLAMADAS, "rb");
    archivoCostos = fopen(F_COSTOS, "rb");
    archivoGastos = fopen(F_GASTOS, "wb");

    if(archivoLlamada == NULL || archivoCostos == NULL || archivoGastos == NULL){
        printf("chao");
        exit(1);
    }

    fread(&costo, sizeof(struct Costos),1, archivoCostos);
    fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
    while (!feof(archivoLlamada)){
        contador = 0;
        strcpy(sAnterior, llamadas.sector);
        strcpy(archivo, llamadas.sector);
        strcat(archivo, DAT);
        archivoGastos = fopen(archivo, "wb");
        if(archivoGastos == NULL){printf("No se pudo crear el archivo del sector.\n");exit(1);}
        contadorLlamada1 = 0;
        contadorLlamada2 = 0;
        contadorLlamada3 = 0;
        contadorDuracion1 = 0;
        contadorDuracion2 = 0;
        contadorDuracion3 = 0;  

        while((!feof(archivoLlamada)) && (strcmp(sAnterior, llamadas.sector)==0)){
            contador++;
            if(llamadas.tipo == 1){
                contadorLlamada1++;
                contadorDuracion1+=llamadas.duracion;

                if(contadorLlamada1>0){
                    sector.tipo = llamadas.tipo;
                    sector.duracion = llamadas.duracion;
                    sector.costo = llamadas.duracion * costo.local;
                }
            }
            if(llamadas.tipo == 2){
                contadorLlamada2++;
                contadorDuracion2+=llamadas.duracion;

                if(contadorDuracion2>0){
                    sector.tipo = llamadas.tipo;
                    sector.duracion = llamadas.duracion;
                    sector.costo = llamadas.duracion * costo.largaDistancia;
                }
            }
            if(llamadas.tipo == 3){
                contadorLlamada3++;
                contadorDuracion3+=llamadas.duracion;

                if(contadorDuracion3>0){
                    sector.tipo = llamadas.tipo;
                    sector.duracion = llamadas.duracion;
                    sector.costo = llamadas.duracion * costo.celular;
                }
            }

            fwrite(&sector, sizeof(struct Gastos),1, archivoGastos);
            fread(&llamadas, sizeof(struct Llamadas),1, archivoLlamada);
        }

            //Tiempo por Sector
        duracionSector = contadorDuracion1 + contadorDuracion2 + contadorDuracion3;
        printf("-Sector %s \n.tipo 1: %d llamadas\n.tipo 2: %d llamadas\n.tipo 3: %d llamadas\n", sAnterior, contadorLlamada1, contadorLlamada2, contadorLlamada3);

            //Busqueda Maximo
        if(ban == 0 || duracionSector > maximaDuracion){
            ban = 1;
            strcpy(maximaSector, sAnterior);
            maximaDuracion = duracionSector;
            printf("Nuevo maximo: S_%s | D:%dsg \n", maximaSector, maximaDuracion);
        }

            //Guardado de gastos
        strcpy(resumen.sector, sAnterior);
        resumen.gastosTipo1 = contadorDuracion1*costo.local;
        resumen.gastosTipo2 = contadorDuracion2*costo.largaDistancia;
        resumen.gastosTipo3 = contadorDuracion3*costo.celular;
        fwrite(&resumen, sizeof(struct Gastos),1, archivoGastos);

        Listar(resumen);
    }

    fclose(archivoLlamada);
    fclose(archivoCostos);
    fclose(archivoGastos);
    fclose(archivoLlamada);


    return 0;
}


            //Hacerlo en una funcion, volver a abrirlos y contar desde ahi(creo)
/*
            if(contadorDuracion1>0){
                sector.tipo = llamadas.tipo;
                sector.duracion = llamadas.duracion;
                sector.costo = llamadas.duracion * costo.local
            }else if(contadorDuracion2>0){
                sector.tipo = llamadas.tipo;
                sector.duracion
            }
*/