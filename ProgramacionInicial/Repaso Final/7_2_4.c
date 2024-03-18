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
    printf("\tSistema de reserva\n\n");
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
            printf("ASIENTO OCUPADO\n\n");
            asientosOcupados++;
            system("pause");
        }else{
            Actualizar(butacas, fila, columna);
            asientosDisponibles++;
            printf("\tRESERVA COMPLETADA\n\nPresiona cualquier tecla para continuar...");
            system("pause");
        }

        system("cls");
        printf("\tSistema de reserva\n\n");
        Reservas(butacas);
        do{
            printf("\nReserva\n-Fila: ");
            scanf("%d", &fila);
            if(fila>12){printf("\n\nFila Inexistente.\n");}
        }while(fila>12);

    }
    printf("hasta ahora funko");
    exit(1);
    //FinalPrograma(butacas, asientosOcupados, asienstosDisponibles); //terminar
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
        if(i<4){
            aux=8;
            printf("\t C%d", aux-(2*i));
        }else if(i==4){
            printf("\t C1");
        }else{
            aux=1;
            printf("\t  C%d", aux+(2*(i-4)));
        }
    }
    for(int f=0; f<F; f++){
        printf("\nF%d", f+1);
        for(int c=0; c<C; c++){
            printf("\t%c", butacas[f][c]);
        }
        printf("\n");
    }
}
int Busqueda(char Butaca[][C], int filaBuscada, int columnaBuscada){
    int estado=0;
    if(Butaca[filaBuscada-1][columnaBuscada-1] == 'R'){
        printf("Entro");
        estado=1;
    }
    return estado;
}
void Actualizar(char butacas[][C], int fila, int columna){
    if(columna==1){
        butacas[fila-1][4]='R';
    }else if(columna==2){
        butacas[fila-1][3]='R';
    }else if(columna==3){
        butacas[fila-1][5]='R';
    }else if(columna==4){                                           
        butacas[fila-1][2]='R';
    }else if(columna==5){
        butacas[fila-1][6]='R';
    }else if(columna==6){
        butacas[fila-1][1]='R';
    }else if(columna==7){
        butacas[fila-1][7]='R';
    }else if(columna==8){
        butacas[fila-1][0]='R';
    }else if(columna==9){
        butacas[fila-1][8]='R';
    }   
}
