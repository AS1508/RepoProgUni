#include<stdio.h>

int Busqueda(struct datos[], int, int);
void NuevoArchivo(struct datos[], int);
struct datos{
    int cod;
    float precio;
    char desc[51];
};

int main(){
    struct datos vec[100], aux;
    FILE*arch;
    int i=0, codigo, cant, x;
    float precio;
    arch=fopen("productos.dat", "rb");
    if(arch==NULL){
        printf("Error");
        exit(1);
    }

    //Carga
    fread(&aux, sizeof(aux), 1, arch);
    while(!feof(arch)){
        vec[i]=aux;
        i++;
    fread(&aux, sizeof(aux), 1, arch);
        
    }
    fclose(arch);
    cant = i;

    //Actualizacion
    printf("codigo: ");
    scanf("%d", &codigo);
    while(codigo!=0){
        x=Busqueda(vec, codigo, cant);
        if(x!=-1){
            printf("Precio: ");
            scanf("%f", &precio);
            vec[x].precio=precio;

        }else
            printf("Error.");
        printf("Codigo: ");
        scanf("%d", &codigo);
    }
    NuevoArchivo(vec, cant);
}
int busqueda(struct datos v[], int x, int cant){
    int i=0, pos=-1;
    while(i<cant && pos==-1){
        if(v[i].cod==x)
            pos=i;
        else
            i++;
    }
    return pos;

}
void Nuevoarchivo(struct datos v[], int cant){
    int i;
    FILE*arch;
    arch=fopen("productos.dat", "wb");
    if(arch==NULL){
        printf("Error");
        exit(1);
    }
    for(i=0; i<cant; i++){
        printf("Producto\t|\tPrecio");
        fwrite(&v[i], sizeof(struct datos), 1, arch);
    }
    fclose(arch);
}