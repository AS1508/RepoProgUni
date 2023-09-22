#include<stdio.h>

int CargaLibros(int[], int);
int validacion(int, int, int);
int busqueda(int[], int, int);
void Ventas(int[], int, int[][7]);
void Listado(int[][7], int, int[]);

int main(){
    int libros[100], l=0, venta[100][7]={{0}};
    
    l=CargaLibros(libros, 100);
    Ventas(libros, l, venta);
    Listado(venta, l, libros);
    //MayoresVentas() //comparacion como en el 1.1.3 (hacer)
    //NoVentas() //recorrer por fila la matriz y sumar las cantidades (hacer)
}
int CargaLibros(int vL[], int nL){
    int codlib, i=0, x;
        codlib=validacion(1000, 9999, 0);   //hacer
    while(codlib!=0 && i<100){
        x=busqueda(vL, codlib, i);  //hacer
        if(x==-1){
            vL[i]=codlib;
            i++;
        }else{
            printf("libro duplicado");
        }
        codlib=validacion(1000, 9999, 0);
    }
    return i;
}
void Ventas(int vL[], int cL, int vV[][7]){
    int libro, lpos, suc, cant=0;
    printf("codigo de libro:");
    scanf("%d", &libro); 
    //pedido de datos
    while(libro!=0){
        lpos=busqueda(vL, libro, cL);    
        if(lpos!=-1){
            do{
            printf("sucursal: ");
            scanf("%d", &suc);
            suc=(suc/10)-1;  
            }while(suc<0 || suc>6);
            printf("cantidad:");
            do{
                scanf("%d", &cant); 
            }while(cant<=0);
            vV[lpos][suc]=cant;
        }else
            printf("codigo erroneo");

        scanf("%d", &libro);
    }
}
void Listado(int vV[][7], int l, int vL[]){
    printf("libro/Sucursal\t10\t20");
    //muestra de codigos de libros
    for(int i=0; i<l;i++){
        printf("&d", vL[i]);
        //muestra de matriz
        for(int j=0; j<7; j++){
            printf("%d\t", vV[i][j]);
        }
        printf("\n");
    }
}
/*
//suma por columna
for(j){
    for(i){
        vsuc[j]=m[i][j]
    }
}
//busqueda de maximo
for(i){
    if(i==0 || vsuc[i]){
        max=vsuc[]
    }
    printf(suc con mayores);
}
//muestra de maximo 
for(i){
    if(max==vsuc[i]){
        printf(%d, (i+1)*10)
    }
}
//sumador
for(i){
    sum=0
    for(j){
        sum+=m[i][j]
    }
    if(sum==0){ //para encontrar las sucursales que no venideron nada
        printf(%d\n, vL[i])
    }
}
*/