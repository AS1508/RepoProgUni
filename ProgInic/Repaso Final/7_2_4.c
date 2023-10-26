#include<stdio.h>
#include<stdlib.h>
#define F 12
#define C 9

void Carga(char[][C]);
void Reservas(char[][C]);
int Busqueda(char[][C], int, int);
void Actualizar(char[][C], int, int);
//void FinalPrograma(char[][C], int, int);
//faltan los que use para finalprograma

int main(){
    char butacas[F][C];
    int fila, columna, asientosDisponibles, asientosOcupados, estado;

    Carga(butacas);
    printf("\tSistema de reserva\n");
    Reservas(butacas);
    do{
        printf("\nReserva\n-Fila: ");
        scanf("%d", &fila);
        if(fila>12){printf("\n\nFila Inexistente.\n");}
    }while(fila>12);
    while(fila>0){
        printf("-Columna: ");
        scanf("%d", &columna);
        estado=Busqueda(butacas, fila, columna);
        if(estado == 1){
            printf("asiento ocupado");
            asientosOcupados++;
        }else{
            Actualizar(butacas, fila, columna);
            asientosDisponibles++;
            printf("\tRESERVA COMPLETADA\n\n");
        }

        system("cls");
        printf("\tSistema de reserva\n");
        Reservas(butacas);
        do{
            printf("\nReserva\n-Fila: ");
            scanf("%d", &fila);
            if(fila>12){printf("\n\nFila Inexistente.\n");}
        }while(fila>12);

    }
    printf("hasta ahora funko");
    exit(1);
    //FinalPrograma(butacas, asientosOcupados, asienstosDisponibles);
    return 0;
}

void Carga(char butacas[][C]){
    for(int i=0; i<F; i++)
        for(int j=0; j<C; j++)
            butacas[i][j]= 'D';
}
void Reservas(char butacas[][C]){
    int aux;
    for(int i=0; i<C; i++){
        if(i<5){
            aux=8;
            printf("\t C%d", aux-(2*i));
        }else{
            aux=1;
            printf("\t  C%d", aux+(2*(i-5)));
        }
    }
    for(int f=0; f<F; f++){
        //printf("F%1") (Seguir)
        for(int c=0; c<C; c++){
            printf("\t%c", f+1, butacas[f][c]);
        }
        printf("\n");
    }
}
int Busqueda(char Butaca[][C], int filaBuscada, int columnaBuscada){
    int estado=0;
    if(Butaca[filaBuscada][columnaBuscada] == 'R'){estado=1;}

    return estado;
}
void Actualizar(char butacas[][C], int fila, int columna){butacas[fila][columna]=='R';}
