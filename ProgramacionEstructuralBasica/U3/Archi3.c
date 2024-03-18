#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fecha{
    int dia;
    int mes;
};
struct personal{
    int legajo;
    float vHora;
    char nYa[50];
    float hrTrabajada;
    float sueldo;
    struct fecha proceso;
};

int leeyvalida(int, int, int);
void actualizar(struct personal[], int);
void personal2(struct personal[], int);
int buscar(struct personal[], int, int);

int main(){
    struct personal registro[500], aux;
    int i, cantidad, legajo, dia, mes, x, sec;
    float vHora, hTrabajada, hora, sueldo, seccion[50];
    FILE *archivo;
    archivo=fopen("personal.dat", "rb");
    if(archivo==NULL){
        printf("ERROR");
        exit(1);
    }

    fread(&aux, sizeof(struct personal), 1, archivo);
    while(!(feof(archivo))){
        registro[i]=aux;
        i++;
        fread(&aux, sizeof(struct personal), 1, archivo);        
    }
    fclose(archivo);
    cantidad=i;

    printf("Legajo: ");
    legajo=leeyvalida(100, 2500, 0);
    while(legajo!=0){
        x=buscar(registro, legajo, cantidad);
        if(x!=-1){
            printf("seccion: ");
            sec=leeyvalida(1, 50, 1);
            printf("horas trabajadas: ");
            scanf("%f", &hTrabajada);
            seccion[sec-1]+=hora;
            registro[x].sueldo+=registro[x].hrTrabajada * registro[x].vHora;
            registro[x].proceso.dia=16;
            registro[x].proceso.mes=9;

        }else{
            printf("no existe el legajo.\n");
        legajo=leeyvalida(100, 2500, 0);
    }
    actualizar(registro, cantidad);
    personal2(registro, cantidad);

    printf("Cantidad de horas trabajadas por seccion:\n");
    for(int j=0; j<cantidad; j++){
        printf("seccion:%d\thoras:%f", i+1, seccion[i]);
    }
    }
       return 0;
}

int leeyvalida (int ls, int li, int fin){
    int x;
    do{
        scanf("%d", &x);
    }while ((x<li || x>ls) && (x!=fin));
    return x;
}

void personal2(struct personal vector[], int cantidad){
    FILE *arch;
    arch=fopen("personal2.dat", "wb");
    if(arch==NULL){
        printf("Error");
        exit(1);
    }

    for(int i=0; i<cantidad; i++){
        if(vector[i].proceso.dia==16 && vector[i].proceso.mes==9){
            fwrite(&vector[i], sizeof(struct personal), 1, arch);
        }
    }
    fclose(arch);
}

