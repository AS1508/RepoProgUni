#include<stdio.h>
#include<stdlib.h>

struct datos{
    int dni;
    char nombreap[80];
    int n1;
    int n2;
    float prom;
};
void Lectura();
//volver a repasar esto (importante)

int main(){
    struct datos aux;
    int i;
    FILE * arch;
    //apertura de archivo
    arch=fopen("alumnos.dat", "wb");

    if(arch==NULL){
        printf("Error");
        exit(1);
    }
    //Entrada de datos
    printf("DNI: ");
    scanf("%d", &aux.dni);
    while(aux.dni!=0){
        printf("nombre: ");
        fflush(stdin);
        gets(aux.nombreap);
        printf("1°Nota : ");
        scanf("%d", &aux.n1);
        printf("2°Notas : ");
        scanf("%d", &aux.n2);
        aux.prom=(aux.n1 + aux.n2)/2;
        fwrite(&aux, sizeof(aux), 1, arch);
        
        printf("DNI: ");
        scanf("%d", &aux.dni);
    }
    //Cierre de archivo
    fclose(arch);
    Lectura();
    return 0;
}
void Lectura(){
    struct datos aux;
   FILE * arch;
    arch=fopen("alumnos.dat", "rb");
    if(arch==NULL){
        printf("Error");
        exit(1);
    }
    printf("dni\t|\tnombre\t|\tPrimer nota\t|\tSegunda Nota\t|\tPromedio\n");
    while(!feof(arch)){
        fread(&aux, sizeof(aux),1,arch);
        printf("%d\t|\t%s\t|\t%d\t\t|\t%d\t\t|\t%.2f\n", aux.dni,aux.nombreap,aux.n1,aux.n2,aux.prom);
        
    }
    fclose(arch);
}