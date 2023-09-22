//Ej explicado por el profe
#include<stdio.h>

void IngresoProd(int[], int);
void Venta(int[], int[], int[], int);

int main(){
    int vArt[14], vCant[]={0}, vVend[4];
    
    IngresoProd(vArt, 14);
    Venta(vArt, vCant, vVend, 14);
    //Listado();


    return 0;
}

void IngresoProd(int vp[], int n){
    int i, prod;
    for(i=0; i<n; i++){
        do{
            printf("Prod:");
            scanf("%d", &prod);
        }while(prod<100 || prod>999);
        vp[i]=prod;
    }
}
void Venta(int vp[], int vc[],int vV[], int n){
    int cv, x, cArt, cant, min, max, i;

    cv=leeyvalida(1001, 1005, 0);

    while(cv!=0){
        printf("Cod Art\n");
        x=busqueda(vp, cArt, 14);

        if(x!=-1){
            do{
                printf("cantidad\n");
                scanf("%d", &cant);
            }while(cant<=0);
            vc[x]+=cant;
            vV[cv-1001]++;
        }else{
            printf("Articulo Inexistente");

        }
        cv=leeyvalida(1001, 1005, 0);
    }
    Ordenar(vc, vp, 14);
    min=vV[0];
    max=vV[0];
    for(i=0; i<5; i++){
        if(i==0 && vV[i]<min){
            min=vV[i];
        }
    }
    for(i=0; i<5; i++){
        if(vV[i]==min){
            printf("%d", i+1001);
        }
    }
    printf("Cantidad de un.");
    for(i=0; i<15; i++){
        printf("%d \t %d", vc[i], vp[i]);
    }
}





/*
    _Primero se ingresan los codigos para los productos
    _Luego ingresar ventas
    _venta: codVen, codProd, cant
    _CodVen (1001 al 1005)
    _si codVen==0 : finaliza
    
    _Outputs
        -Listado Ordenado de cantidades vendidas
        -vendedores que menos cantidades vendieron
    


*/