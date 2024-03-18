#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_VIAJES "viajes.dat"
#define F_TARIFAS "tarifas.dat"
#define F_INTERNO "ArchivoInterno.dat"
 
struct viajes{
    int interno;
    int tarjeta;
    char tarifa[10];
    int dia;
    int hora;
};
struct tarifas{
    int mes;
    char tarifa[10];
    float precio;
};
struct internos{
    int cantidadViajes;
    float recaudacionTotal;
}

int CargaTarifa(struct tarifas[], int);
void OrdenarViajes();
void MostrarViaes();

int main(){
    FILE*archivoViajes, *archivoInterno;
    struct viajes interno;
    struct tarifas precios[8], aux;
    struct internos transporte;
    //variables a definir
    int cantidad;
    int i = 0, mes, iAnterior, viaje = 0, tarifa, pos, minimoInterno;
    char vAnterior[10];
    float recaudacion, montosXtarifa[8] = {0}, minimo, nombreArchivo[15];
    /*------------------------------------*/
    
    //abro archivos
    archivoViajes=fopen(F_VIAJES, "rb");
    archivoInterno = fopen(F_INTERNO, "wb");

    if(archivoViajes == NULL || archivoInterno == NULL){exit(1);}

    //pedir tarifas
    printf("\n\n-mes:");
    scanf("%d", &mes);

    cantidad = CargaTarifa(precios, 8);

    //funcion
    fread(&viajes, sizeof(viajes),1, archivoViajes);
    while (!feof(archivoViajes)){

        iAnterior = interno.interno;
        viaje = 0;
        tarifa = 0;
        recaudacion = 0;
        i=0;
        for(int i = 0; i<cantidad; i++)
            montosXtarifa[8] = 0;

        while (!feof(archivoViajes) && iAnterior == interno.interno){
            pos = -1;
            for(int i = 0; i<cantidad; i++){
                if(strcmpi(interno.tarifa, precios[i].tarifa) == 0)
                    pos = i;
            }

            recaudacion += precios[pos].precio;
            montosXtarifa[pos] += tarifa;
            viaje++;
            
            fread(&viajes, sizeof(viajes),1, archivoViajes);
        }

        transporte.cantidadViajes = viaje;
        transporte.recaudacionTotal = recaudacion;
        fwrite(&transporte, sizeof(transporte),1, archivoInterno);

        if(bandera == 0 || recaudacion < minimo){
            minimoInterno = interno.interno;
            minimo = recaudacion;
        }

    }

    //deberia hacer el (e) pero tu vieja va a hacer el (e)
    OrdenarViajes(montosXtarifa, cantidad);
    /*
        for
            for
                if(montotarifa < montotarifa+1)
                    aux=tarifa
                    tarifa=tarifa+1
                    tarifa+1=aux
    */
    MostrarViaes(iAnterior,montosXtarifa, cantidad);
    /*
        printf(interno tal)
        for(cantdad)
            printf(tarifa tal)
    */

    return 0;
}

int CargaTarifa(struct tarifas montos[], int maximo){
    FILE*archivoTarifas;
    struct tarifas aux;
    int i = 0;
    archivoTarifas=fopen(F_TARIFAS, "rb");
    fread(&aux, struct(aux),1,archivoTarifas);
    while(!feof(archivoTarifas)){
        if(aux.mes == mes){
            montos[i] = aux;
            i++;
            cantidad++;
        }
        fread(&aux, struct(aux),1,archivoTarifas);
    }

    return i;
}