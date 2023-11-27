#include <stdio.h>

int Resto(int, int);
int EsPar(int);
int EsPrimo(int);
float Promedio(int, int);
int validacion(int);

int main(){
    int n, par=0, primo=0, sum=0, cont=0;
    float prom;
    do{
        printf("ingrese un valor: ");
        scanf("%d", &n);

    }while(validacion(n)!= 1);

    while(n != -10){

        if(EsPar(n)==1){
            par++;
        }else if(EsPar(n)==0){
            sum+=n;
            cont++;

            printf("%d\n",cont);
        }
        if(EsPrimo(n)==1){
            primo++;
        }

        printf("ingrese un valor: ");
        scanf("%d", &n);
    }

    prom = Promedio(sum, cont);
    printf("%f", prom);

    printf("-Cantidad de Primos: %d\n", primo);
    printf("-Cantidad de Pares: %d\n", par);
    printf("Promedio de Impares: %.2f\n", prom);
}

int validacion(int n){
    int v=0;
    if(n>=1 && n<=50){
        v = 1;
    }else{
        printf("Elija un numero del 1 al 50.\n");
        v = 0;
    }
    return v;
}
int Resto(int a, int b){
    int res=0;
    res = a%b;
    return res;
}
int EsPar(int x){
    int n;
    if(Resto(x,2)==0){
        n = 1;
    }else{
        n = 0;
    }
    return n;
}
int EsPrimo(int x){
    int n, i, a=0;
    for(i=1; i<=x; i++){
        if(x%i==0){
            a++;
        }
    }
    if(a==2){
        n = 1;
    }else{
        n = 0;
    }
    return n;
}
float Promedio (int suma, int cont){
    float x = 0;
    if(cont>0){
        x = suma/cont;
    }else{
        x = 0;
    }

    return x;
}
