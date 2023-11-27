//4.7
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#define F_BARRERA "barreras.dat"
#define F_RECAUDACIONES "RECAUDACION.dat"

struct BARRERA{
    int dia;
    int hora;
    int numeroBarrera;
};
struct RECAUDACIONES{
    int dia;
    float tarifaNormal;
    float tarifaPico;
    float monto;
};

void RECAUDAR(struct RECAUDACIONES, int, int, int);

int main(){
    FILE*archivoBarrera;
    struct BARRERA paso;
    struct RECAUDACIONES recaudacionDia;
    int cantidadHoraNormal, cantidadHoraPico, cantidadXdia, auxDia, auxHora;
    
    archivoBarrera = fopen(F_BARRERA, "rb");
    if(archivoBarrera == NULL){exit(1);}

    fread(&paso, sizeof(paso),1, archivoBarrera);
    while (!feof(archivoBarrera)){
        auxDia = paso.dia;
        cantidadXdia = 0;
        cantidadHoraNormal = 0;
        cantidadHoraPico = 0;
        while (!feof(archivoBarrera) && auxDia == paso.dia){
            auxHora = paso.hora;
            while (!feof(archivoBarrera) && auxHora == paso.hora){
                if(paso.hora >= 7 || paso.hora <= 11){
                    cantidadHoraNormal++;
                    cantidadXdia++;
                }else if(paso.hora >= 17 || paso.hora <= 19){
                    cantidadHoraPico++;
                    cantidadXdia++;
                }
                fread(&paso, sizeof(paso),1, archivoBarrera);
            }
            RECAUDAR(recaudacionDia, auxDia, cantidadHoraNormal, cantidadHoraPico);
            fread(&paso, sizeof(paso),1, archivoBarrera);
        }
    }

    fclose(archivoBarrera);
    return 0;
}

void RECAUDAR(struct RECAUDACIONES recaudacionXdia, int dia, int horaNormal, int horaPico){
    FILE*archivoRecaudacion = fopen(F_RECAUDACIONES, "wb");
    int i=0;

    recaudacionXdia.dia = dia;
    printf("\n\tTARIFAS DEL DIA\n\n-Tarifa normal :: ");
    scanf("%f", &recaudacionXdia.tarifaNormal);
    printf("\n-Tarifa hora pico :: ");
    scanf("%f", &recaudacionXdia.tarifaPico);
    recaudacionXdia.monto = (horaNormal * recaudacionXdia.tarifaNormal) + (horaPico * recaudacionXdia.tarifaPico);
    fwrite(&recaudacionXdia, sizeof(recaudacionXdia),1, archivoRecaudacion);
    
    system("cls");
    printf("\n\n\t\tRESUMEN\n");
    printf("-DIA: %d \n", dia);
    printf("-TARIFAS:\n\t*NORMAL:: %2.f \t*PICO:: %.2f \n", recaudacionXdia.tarifaNormal, recaudacionXdia.tarifaPico);
    printf("-VEHICULOS: %dun\n", (horaNormal+horaPico));
    printf("-RECAUDADO: %.2f\n", recaudacionXdia.monto);
    system("pause");
    
    fclose(archivoRecaudacion);

}