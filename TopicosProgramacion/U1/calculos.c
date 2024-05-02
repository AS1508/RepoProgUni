#include "Calculos.h"
#include <math.h>

int fInterna();

/**Funciones**/

/*1*/
double Factorial(int num){
    double fact = 1;
    if(num == 0)
        return 1;
    else{
        for(int i=1; i<=num; i++){
            fact *=i;
        }
    }

    return fact;
}
/*2*/
double Combinatorio(int n, int m){
    if(n<=m && n>=0)
        return Factorial(m)/(Factorial(n)*(Factorial(m-n)));
}
/*3*/
double ex(int num, int tol){
    double e = 1;
    for(int i = 1; i<=tol; i++){
        e+= pow(num,i)/Factorial(i);
    }
    return e;
}
/*5*/
/*Para validar si pertenece a la secuencia de fibonacci, se busca que sea un cuadrado perfecto
de 5 veces el numero +/- 4 */

int cuadradoPerfecto(int num){
    int raiz = sqrt(num);
    return raiz*raiz == num;
}
int Fibonacci(double num){
    return cuadradoPerfecto(5*num*num + 4) || cuadradoPerfecto(5*num*num - 4);
}
/*6*/
float seno(int num, int tol){
    float seno = 0;
    for(int i = 1; i <= tol; i+2)
        seno += pow(num, i)/Factorial(num);

    return seno;
}

/*****/
int fInterna(){
    return 0;
}

