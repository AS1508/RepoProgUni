#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define F_PRODUCTO "producto.dat"
#define F_AREPONER "aReponer.dat"
 
typedef struct{
    int codigo;
    char descripcion[35];
    int puntoPedido;
    int stock;
    float precio;
}PRODUCTO;
typedef struct{
    int suma;
    float promedio;
}RECHAZADOS;
 
int Carga(PRODUCTO[]);
int Busqueda(PRODUCTO[], int, int);
int Validacion(int, int, int);
int Ingreso(int, int);
void Reponer(PRODUCTO[], int);
void InformeMensualCantidad(int[]);
void InformeMensualImportes(float[][30]);
void PromedioRechazos(RECHAZADOS, int);
 
int main(){
    PRODUCTO productos[3500];
    RECHAZADOS rechazos;
    int cantidadProductos, codigo, posicion, cantidad, cliente, dia; 
    int productoXdia[30] = {0};
    float ImportesClientes[350][30] = {{0}};

    cantidadProductos = Carga(PRODUCTO);

    printf(">>codigo\n"):
    codigo = Validacion(1000, 10000, 999);

    while (codigo != 999){
        posicion = Busqueda(productos, codigo, cantidadProductos);
        if(posicion != -1){
            printf(">>Cantidad\n");
            cantidad = Ingreso(0, 1000000);
            printf(">>Cliente\n");
            cliente = Ingreso(1, 350);
            printf(">>Dia\n");
            dia = Ingreso(1, 30);

            productos[posicion].stock -= cantidad;
            productoXdia[dia-1] += cantidad;
            ImportesClientes[cliente-1][dia-1] = cantidad * productos[posicion].precio;
        }else{
            printf(">>CODIGO NO ENCONTRADO>>\n");
            rechazos.suma++;
        }

        printf(">>codigo\n"):
        codigo = Validacion(1000, 10000, 999);
    }
    Reponer(productos, cantidadProductos);
    InformeMensual(productoXdia);
    InformeMensualImportes(ImportesClientes);
    PromedioRechazos(rechazos, cantidadProductos);

    return 0;
}

int Carga(PRODUCTO productos[]){
    FILE*archivo;
    PRODUCTO auxiliar;
    int i = 0;

    if((archivo = fopen(F_PRODUCTO, "rb");) == NULL){exit(1);}
    
    fread(&auxiliar, sizeof(PRODUCTO),1, archivo);
    while (!feof(archivo)){
        productos[i] = auxiliar;
        i++;
        fread(&auxiliar, sizeof(PRODUCTO),1, archivo);
    }
    fclose(archivo);

    return i;
}
int Busqueda(PRODUCTO produtos[], int codigo, int cantidad){
    int posicion = -1, i = 0;
    while (posicion == -1 && i<cantidad){

        if(produtos[i].codigo == codigo)
            posicion = i;
        else
            i++;

    }
    return posicion;
}
int Ingreso(int limInf, int LimSup){
    int numero;
    do{
        printf(">%d", &numero);
    }while(numero<limInf || numero>LimSup);
    return numero;
}
int Validacion(int limInf, int LimSup, int fin){
    int numero;
    do{
        printf(">%d", &numero);
    }while((numero<limInf || numero>LimSup) && numero != fin);
    return numero;
}
void Reponer(PRODUCTO productos[], int cantidad){
    FILE*archivo;
    
    if((archivo = fopen(F_AREPONER, "wb")) == NULL){exit(1);}

    for(int i = 0; i<cantidad; i++)
        if(productos[i].stock < productos[i].puntoPedido)
            fwrite(&productos[i], sizeof(PRODUCTO),1, archivo);

    printf("\n\n>>>ARCHIVO CON PRODUCTOS A REPONER -> CREADO CORRECTAMENTE>>>\n\n");
    fclose(archivo); 
}
void InformeMensualCantidad(int cantidad[]){
    printf(">>>Informe Mensual de Cantidades\n")
    for(int i = 0; i<30; i++){
        printf("D%d | %du \n", i+1, cantidad[i]);
    }
}
void InformeMensualImportes(float cliente[][30]){

    printf("Cliente / Dia: ");
    for(int i = 0; i<30, i++)
        printf("%d\t", i+1);

    for(int i = 0; i<350; i++){
        printf("C%d\t", i+1);
        for(int j = 0; j<30; j++){
            printf("%d\t", cliente[i][j]);
        }
        printf("\n");
    }
}
void PromedioRechazos(RECHAZADOS codigo, int cantidad){
    if(codigo.suma != 0){
        codigo.promedio = codigo.suma / cantidad;
        printf(">>>Promedios de codigos Rechazados\n>%.2f", codigo.promedio);
    }
}