#include<stdio.h>

void IngresarCodigos(int[], int);
void Registro(int[], int[], int);
int Maximo(int[], int);
int Minimo(int[], int);
void Listado(int[], int[], int, int, int);
int Busqueda(int[], int, int);

int main(){

    int codigos[10], cantidades[]={0}, pedidos, pedMax, pedMin;

    IngresarCodigos(codigos, 10);
    Registro(codigos, cantidades, 10);
    pedMax = Maximo(cantidades, 10);
    pedMin = Minimo(cantidades, 10);

    Listado(codigos, cantidades, pedMax, pedMin, 10); 
    

    return 0;
}
void IngresarCodigos(int v[], int n){
    int i;
    printf("Codigos:\n");
    for(i=0; i<n; i++){
        do{
            scanf("%d", &v[i]);
            if(v[i]>999 && v[i]<9999){
                printf("entra");
            }else{
                printf("no entra");
            }
        }while(v[i]<999 && v[i]>9999);
    }
}
void Registro(int cp[], int cnt[], int n){
    int x, c, cn, pos=0;

    do{
        printf("AAACodigo: ");
        scanf("%d", &c);
    }while (c!=0 || (c>999 && c<9999));

    while(c!=0){
        
        pos = Busqueda(cp, c, n);

        if(pos!=-1){
            printf("cant: ");
            scanf("%d", &cn);
            cnt[pos]=cn;
        }
        do{
            printf("Codigo: ");
            scanf("%d", &c);
        }while (c!=0 || c>9999 && c<999);

    }
}
int Busqueda(int v[], int numPed, int n){
    int pos, i=0;
    while(pos==-1 && i<n){
        if(v[i]==numPed){
            pos=i;
        }else{
            i++;
        }
    }
    return pos;
}
int Maximo(int v[], int n){
    int i=0, max=v[i];
    for(i=1; i<n; i++){
        if(v[i]>max){
            max = v[i];
        }
    }

    return max;
}
int Minimo(int v[], int n){
    int i=0, min=v[i];
    for(i=1; i<n; i++){
        if(v[i]<min){
            min = v[i];
        }
    }

    return min;
}
void Listado(int cp[], int cnt[], int max, int min, int n){
    int i;
    printf("Listado de pedidos\n");
    for(i=0; i<n; i++){
        printf("Codigo: %d | Cantidades: %d", cp[i], cnt[i]);
        printf("\n");
    }
    printf("Productos mas solicitados:\n");
    for(i=0; i<n; i++){
        if(cnt[i]==max){
            printf("P%d", cp[i]);
        }
    }
    printf("Productos menos solicitado:\n");
    for(i=0; i<n; i++){
        if(cnt[i]==min){
            printf("P%d", cp[i]);
        }
    }
}


/*
    hay que registrar los pedidos de cada uno de los 10 productos
    cada producto tiene un codigo de 4 cifras
    estos se ingresan  al inicio del programa (xFuncion)

    para los pedidos se toma codigo y cantidad 
    se termina cuando se ingresa un codigo == 0

    tiene que emitir un listado con codigo y cantidades (osea hay que hacer una matriz de pedidos)
    tiene que mostrar el producto que mas se solicito
    tiene que mostrar el producto que menos se solicito
*/