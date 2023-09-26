#include<stdio.h>

void Productos(int[], int);
void Ventas(int[], int, int[], int, int[]);
void Listado(int[], int, int[], int[], int, int);
int bMinimo(int[], int);
void Ordenar(int[], int, int[]);
int Busqueda(int[], int, int);
int LeeyValida(int, int, int);


int main(){
    int vProd[15], vVend[5]={0}, vCant[15]={0}, min=0;
    Productos(vProd,15); 
    Ventas(vVend, 5, vProd, 15, vCant);
    min=bMinimo(vVend, 5); 
    Ordenar(vProd, 15, vCant);
    Listado(vProd, 15, vCant, vVend, 5, min);

    return 0; 
}
int Busqueda(int v[], int x, int Cant){
    int i=0, pos=-1;
    while(i<Cant && pos==-1){
        if(v[i]==x){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
void Productos(int vP[], int n){
    int i, x, pos; 
    for(i=0; i<n; i++){
        do{
            printf("codigo: ");
            scanf("%d", &x);
            pos=Busqueda(vP, x, n);
            if(pos!=-1){
                printf("Dato duplicado.\n");
            }
            if(x<100 || x>999){
                printf("no entra en rango.\n");
            }
        }while((x<100 || x>999) || pos!=-1);
        vP[i]=x;
    }
    for(i=0; i<n; i++){
        printf("%d ", vP[i]);
    }
}
void Ventas(int vV[], int nv, int vP[], int np, int vC[]){
    int vend=0, cant=0, prod=0, pos;
    
    vend=LeeyValida(1001, 1005, 0);

    while(vend!=0){
        do{
            printf("Art:");
            scanf("%d", &prod);
            pos = Busqueda(vP, prod, np);
        }while(pos==-1);
        do{
            printf("Cantidad:");
            scanf("%d", &cant);
        }while(cant<0);

        vV[vend-1001]+=1;
        vC[pos]+=cant;

        vend=LeeyValida(1001, 1005, 0);
    }

}
void Listado(int vP[], int nP, int vC[], int vV[], int nV, int min){
    int i, j;

    printf("Ventas\nCantidades\t\tCodigos\n");
    for(i=0;i<nP; i++){
        printf("%d \t\t\t %d\n", vC[i], vP[i]);
    }
    printf("\n-Vendedores que realizaron la menor cantidad de ventas\n ");
    for(i=0; i<nV; i++){
        if(min==vV[i]){
            printf("| V%d |", i+1001);
        }
    }

}
int bMinimo(int vV[], int nv){
    int i, min=vV[0];
    for(i=1; i<nv; i++){
        if(vV[i]<=min){
            min=vV[i];
        }
    }
    return min;
}
void Ordenar(int vP[], int n, int vC[]){
    int aux, i, j;

    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(vC[j]<vC[j+1]){
                aux=vP[j];
                vP[j]=vP[j+1];
                vP[j+1]=aux;

                aux=vC[j];
                vC[j]=vC[j+1];
                vC[j+1]=aux;
            }
        }
    }
}
int LeeyValida(int li, int ls, int fin){
    int x;
    do{
        printf("Cod. Vendedor: ");
        scanf("%d", &x);
        if((x<li || x>ls) && x!=fin){
            printf("Codigo incorrecto.\n");
        }
    }while((x<li || x>ls) && x!=0);  
    return x;
}