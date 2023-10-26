#include<stdio.h>
#include<stdlib.h>
#define EMPLEADOS 100

int Carga(int[], int[], int[], int);
int CuentaPorSector(int[], int);
void PagosTotales(int[], int[], int);
int Busqueda(int[], int, int);

int main(){
    int dni[EMPLEADOS], codigoSector[EMPLEADOS], sueldo[EMPLEADOS];
    int cantidadEmpleados, contador=0;

    cantidadEmpleados=Carga(dni, codigoSector, sueldo, EMPLEADOS);

    for(int i=0; i<5; i++){
        contador=0;
        contador=CuentaPorSector(codigoSector, cantidadEmpleados);
        printf("\n_Sector %d: %d empleados.\n", i+1, contador);
    }

    PagosTotales(codigoSector, sueldo, cantidadEmpleados);

    return 0;
}

int Carga(int dni[], int codigo[], int sueldo[], int cantidad){
    int i=0, emp, cod, sue, pos;

    printf("\n-Empleado: ");
    scanf("%d", &emp);
    while(emp!=99){
        printf("\n-codigo: ");
        scanf("%d", &cod);
        printf("\n-Sueldo: ");
        scanf("%d", &sue);

        dni[i]=emp;
        codigo[i]=cod;
        sueldo[i]=sue;
        i++;

        do{
            printf("\n-Empleado: ");
            scanf("%d", &emp);
            pos=Busqueda(dni, emp, i);
            if(pos!=-1){printf("Ususario Existent.\n");}
        }while(pos!=-1);
    }
    printf("\n\n\tCarga Completada.\n");
    return i;
}
int Busqueda(int list[], int x, int cantidad){
    int pos=-1, i=0;

    while(i<cantidad && pos==-1){
        if(list[i]==x){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
int CuentaPorSector(int codigo[], int cantidad){
    int num, i, contador=0, indice=1;

    contador=0;
    for(i=0; i<cantidad; i++){
        if(codigo[i]==indice){contador++;}
    }
    indice++;

    return contador;
}
void PagosTotales(int codigo[], int sueldo[], int cantidadEmpleados){
    int sector=0;
    float CantidadC1=0, CantidadC2=0, CantidadC3=0, CantidadC4=0,CantidadC5=0;

    for(int i=0; i<cantidadEmpleados; i++){
        if(codigo[i]==1){CantidadC1+=sueldo[i];}
        if(codigo[i]==2){CantidadC2+=sueldo[i];}
        if(codigo[i]==3){CantidadC3+=sueldo[i];}
        if(codigo[i]==4){CantidadC4+=sueldo[i];}
        if(codigo[i]==5){CantidadC5+=sueldo[i];}
    }
    printf("\n\n-Sueldo Categoria 1: $%.2f\n-Sueldo Categoria 2: $%.2f\n-Sueldo Categoria 3: $%.2f\n-Sueldo Categoria 4: $%.2f\n-Sueldo Categoria 5: $%.2f\n", CantidadC1, CantidadC2, CantidadC3, CantidadC4, CantidadC5);
}
