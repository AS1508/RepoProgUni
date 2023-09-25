#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int Carga(int[], int, char[]);
void Facturacion(int[], int, int[][12], int[]); 
int LeeYValida(int, int, int);
int Busqueda(int[], int, int);
char CargaServicio(char, char ,char);
void MatrizEnergetica(int[][12], int, int[]);
void Mayorfacturacion(int[], int);
void ImporteServicio(int[][12], char[], int[], int, int[]);
void ListaImporteServicio(int, int, int);

int main(){
    int codigo[10], mEnergetica[5][12]={{0}}, trimestre[4]={0}, cant, cantidadventas[10];
    char servicio[10];

    cant=Carga(codigo, 10, servicio);
    Facturacion(codigo, cant, mEnergetica, trimestre);
    
    MatrizEnergetica(mEnergetica, cant, codigo);
    Mayorfacturacion(trimestre, 4);
    ImporteServicio(mEnergetica, servicio, codigo, cant, cantidadventas);
    
    return 0;
}

int Carga(int vC[], int n, char vS[]){
    int x, i=0, pos=-1;
    char tipo;
    printf("Empresa: ");
    x=LeeYValida(1000, 5000, 0);

    while(x!=0 && i<n){

        vC[i]=x;

        tipo=CargaServicio('A','G','L');
        
        vS[i]=tipo;
        i+=1;

        printf("\nEmpresa: ");
        do{    
            x=LeeYValida(1000, 5000, 0);
            pos=Busqueda(vC, x, i);
        }while(pos!=-1);
    }

    printf("listado\n");
    for(int j=0; j<i; j++)
        printf("%d / %c |\n", vC[j], vS[j]);
    
    return i;
}
int LeeYValida(int li, int ls, int fin){
    int x;
    do{
        scanf("%d", &x);
        if((x<li || x>ls) && (x!=fin))
            printf("No valido.\n");
    }while((x<li || x>ls) && (x!=fin));

    return x;
}
char CargaServicio(char requisito1, char requisito2 ,char requisito3){
    char aux;

    do{
        printf("Servicio: ");
        scanf(" %c", &aux);
        getchar();
        printf("|%c|", aux);
        aux=toupper(aux);
        printf("|%c|", aux);
        if((aux!=requisito1) && (aux!=requisito2) && (aux!=requisito3))
            printf("Codigo Erroneo\n");
    }while(aux!=requisito1 && aux!=requisito2 && aux!=requisito3);
    return aux;
}
int Busqueda(int v[], int x, int lim ){
    int pos=-1, i=0;
    while(i<lim && pos==-1){
        if(x==v[i])
            pos=i;
        else
            i++;
    }
    return pos;
}
void Facturacion(int vC[], int limite, int M[][12], int tri[]){
    int cod, mes, imp, pos, i=0;

    for(i=0; i<20; i++)
        printf("_");
        
    printf("\n\nmes: ");
    mes=LeeYValida(1, 12, -1);

    while(mes!=-1){
        do{    
            printf("Empresa: ");
            scanf("%d", &cod);
            pos=Busqueda(vC, cod, limite);
            if(pos==-1)
                printf("Empresa no encontrada.\n");
        }while(pos==-1);
        do{
            printf("Importe: ");
            scanf("%d", &imp);

        }while(imp<0);
        
        M[pos][mes-1]=imp;

        switch (mes){
        case 1:
        case 2:
        case 3:
             tri[0]+=imp;
            break;
        case 4:
        case 5:
        case 6:
             tri[1]+=imp;
            break;
        case 7:
        case 8:
        case 9:
             tri[2]+=imp;
            break;
        case 10:
        case 11:
        case 12:
             tri[3]+=imp;
            break;
        }


        i++;
        printf("mes: ");
        mes=LeeYValida(1, 12, -1);
    }
}
void MatrizEnergetica(int matriz[][12], int limite, int vC[]){
    system("cls");
    printf("empresa\t| ");
    for(int i=0; i<12; i++)
        printf("mes %d ", i+1);
    
    for(int i=0; i<limite; i++){
        printf("|\n%d    |", vC[i]);
        for (int j = 0; j < 12; j++){
            printf("%6d", matriz[i][j]);
        }
    }
}
void Mayorfacturacion(int trimestre[], int n){ 
    int i, max=0, pos;
    printf("\nTrimestres de Mayor Facturacion\n\n");
    for(i=0; i<n; i++){
        if(trimestre[i]>=max){
            pos=i;
            max=trimestre[i];
        }
    }
    printf("\t|%d - $%d|\n", pos+1, max);
}
void ImporteServicio(int matriz[][12], char servicio[], int codigos[], int cantidad, int cantven[]){
    int pos, aux, importeServicioAgua=0, importeServicioGas=0, importeServicioLuz=0;
    for(int i=0; i<20; i++)
        printf("_");
    printf("\n\nImporte por Servicio\n");
    for(int i=0; i<cantidad; i++){
        aux=codigos[i];
        pos=Busqueda(codigos, aux, cantidad);
        if(servicio[pos]=='A'){
            for(int j=0; j<12; j++){
                importeServicioAgua+=matriz[pos][j];
            }
        }else if(servicio[pos]=='G'){
            for(int j=0; j<12; j++){
                importeServicioGas+=matriz[pos][j];
            }
        }else{
            for(int j=0; j<12; j++){
                importeServicioLuz+=matriz[pos][j];
            }
        }
    }
    ListaImporteServicio(importeServicioAgua, importeServicioGas, importeServicioLuz);
    
    for(int i=0; i<cantidad; i++){
        for(int j=0; j<12; j++){
            if(matriz[i][j]==0){
                cantven[i]++;
            }
        }
    }
    printf("\n\nEmpresas que no facturaron en dos o mas meses\n");
    for(int i=0; i<cantidad; i++)
        if(cantven[i]>=2)
            printf("| %d | ", codigos[i]);
}

void ListaImporteServicio(int agua, int gas, int luz){
    if((agua>gas) && (agua>luz)){
        printf("\n\n_Agua: $%d", agua);
        if(gas>luz){
            printf("\n_Gas: $%d \n_Luz: $%d", gas, luz);
        }else{
            printf("\n_Luz: $%d \n_Gas: $%d", luz, gas);
        }
    }else if((gas>agua) && (gas>luz)){
        printf("\n\n_Gas: $%d", gas);
            if(gas>luz){
                printf("\n_Agua: $%d \n_Luz: $%d", agua, luz);
            }else{
                printf("\n_Luz: $%d \n_Agua: $%d", luz, agua);
            }
    }else{
        printf("\n\n_Luz: $%d", luz);
            if(gas>luz){
                printf("\n_Gas: $%d \n_Agua: $%d", gas, agua);
            }else{
                printf("\n_Agua: $%d \n_Gas: $%d", agua, gas);
            }
    }
}


/*

    mEnergetica(guarda importes)/codigos(para busqueda)


*/
