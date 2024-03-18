#include<stdio.h>
#include<stdlib.h>

int CargaLibros(int[], int);
void Venta(int[][7], int, int[], int[]);
void Listados(int[][7], int, int[]);
int Busqueda(int[], int, int);
int Lee(int, int);
int Valida(int, int, int);
int ValidaSucursal(int, int, int, int, int, int, int);
void Ordena(int[], int, int[][7], int[]);


int main(){
    int ventas[100][7]={{0}}, libros[100], cantidad, ventaxsucursal[7]={0};
    
    //Carga de Libros
    cantidad = CargaLibros(libros, 100);
    printf("tamos\n");
    //Venta
    Venta(ventas, cantidad, libros, ventaxsucursal);
    printf("Tamos");
    //Listados (Outputs)
    Listados(ventas, cantidad, libros);
    //Outputs Secundarios
    Ordena(ventaxsucursal, cantidad, ventas, libros);
    return 0;
}
int CargaLibros(int libros[], int maximo){
    int codigo, pos=-1, i=0;

    printf("codigo: ");
    codigo = Valida(100, 999, 0);
    
    while(codigo!=0){
        libros[i] = codigo;
        if(codigo){printf("\n\tCarga Exitosa\n\n");}
        i++;
        do{
            printf("codigo: ");
            codigo = Valida(100, 999, 0);
            pos=Busqueda(libros, codigo, maximo);
            if(pos==-1){printf("Libros existente.\n");}
        }while(pos != -1 && codigo != 0);
    }
    return i;
}
int Valida(int limInferior, int limSuperior, int fin){
    int numero;
    do{scanf("%d", &numero);}while((numero < limInferior || numero > limSuperior) && numero != fin);
    return numero;
}
int Busqueda(int DB[], int x, int cantidad){
    int i=0, pos=-1;
    while(i<cantidad && pos==-1){
        if(DB[i]==x){
            pos = i;
        }else{i++;}
    }
    return pos;
}
void Venta(int venta[][7], int cantidad, int libros[], int ventaxsucursal[]){
    int codigos, cantidadVentas=0, sucursal, pos;
    
    printf("codigo: ");
    codigos=Valida(100, 999, 0);
    while(codigos!=0){
        pos=Busqueda(libros, codigos, cantidad);
        printf("Sucursal: ");
        sucursal=ValidaSucursal(10, 20, 30, 40, 50, 60, 70);
        sucursal=(sucursal/10)-1;
        printf("Cantidad: ");
        do{scanf("%d", &cantidadVentas);}while(cantidadVentas<=0);

        venta[pos][sucursal]+=cantidadVentas;
        ventaxsucursal[sucursal]+=cantidadVentas;

        printf("\n\tCarga Existosa\n\n");

        printf("codigo: ");
        codigos = Valida(100, 999, 0);
    }
}
int ValidaSucursal(int s1, int s2, int s3, int s4, int s5, int s6, int s7){
    int sucursal;
    do{scanf("%d", &sucursal);}while(sucursal!=s1&&sucursal!=s2&&sucursal!=s3&&sucursal!=s4&&sucursal!=s5&&sucursal!=s6&&sucursal!=s7);
    return sucursal;
}
void Listados(int ventas[][7], int maximo, int codigos[]){
    printf("Libro/sucursal\t");
    for(int i=1; i<=7; i++)
        printf("S%2d\t", i*10);
    printf("\n");
    for(int i=0; i<maximo; i++){
        printf("L%d\t\t\t", codigos[i]);
        for(int j=0; j<7;j++){printf("%2d\t", ventas[i][j]);}
        printf("\n");
    }
}
void Ordena(int sucursales[], int cantidad, int ventas[][7], int codigos[]){
    int max=0, sum;

    for(int i=0; i<7; i++){if(sucursales[i]>=max){max=sucursales[i];}}
    printf("\n\tMaximos Vendeores\n");
    for(int i=0; i<7; i++){if(max==sucursales[i]){printf("_S%d\t|%d|", (i+1)*10, sucursales[i]);}}
    printf("\n\tLibros que no se vendieron\n");
    for(int i=0; i<cantidad; i++){
        sum=0;
        for(int j=0; j<=cantidad; j++){sum+=ventas[i][j];}
        if(sum==0){printf("|%d| ", codigos[i]);}
    }
}