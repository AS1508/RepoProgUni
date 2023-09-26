#include<stdio.h>

struct medicamento
{
    int codigo;
    float precio;
    int stock;
};

void ingreso(struct medicamento[], int);
int Busqueda(struct medicamento[], int, int);
void informe(struct medicamento[], int);

int main(){
    int codigo, x;
    struct medicamento vec[50];
    
    ingreso(vec, 50);
    printf("Codigo a buscar: ");
    scanf("%d", &codigo);
    x=busqueda(vec, codigo, 50);
    if(x!=-1){
        printf("El precio del codigo %d es %f", vec[x].codigo, vec[x].precio);
    }else{
        printf("No existe");
    }
    informe(vec, 50);
}

void ingreso(struct medicamento vec[], int n){
    int i=0;
    
    for(i=0; i<n; i++){
        printf("Codigo: ");
        scanf("%d", &vec[i].codigo);
        printf("Precio: ");
        scanf("%d", &vec[i].precio);
        printf("stock: ");
        scanf("%d", &vec[i].stock);
    }
}
int busqueda(struct medicamento vec[], int x, int limite){
    int i=0, pos=-1;
    while(i<limite && pos==-1){
        if(vec[i].codigo==x){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
void informe(struct medicamentos vec[], int n){
    int i;
    for(i=0; i<n; i++){
        if(vec[i].stock<10){
            printf("%d", vec[i].codigo);
        }
    }
}