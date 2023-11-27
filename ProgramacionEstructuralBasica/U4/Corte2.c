//punto 4_2

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_VENTAS "ventas.dat"
#define F_PRODUCTO "productos.dat"
#define F_PEDIDOS "pedidos.dat"

struct Sucursal{
    char sucursal[15];
    int codigoSucursal;
    int cantidad;
};
struct Producto
{
    int codigoProducto;
    char descripcion[20];
    float precio;
    int stock;
    int puntoPedido;
    int cantidadPedido;
};

 
int main(){
    FILE*archivoVenta,*archivoProducto,*archivoPedido;
    struct Sucursal ventas;
    struct Producto productos[200];
    int contador=0, ventasTotal=0, sucursalMayor, cantidadMaxima;
    float importeVentas;

    

    return 0;
}