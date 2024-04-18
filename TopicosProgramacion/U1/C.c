#include "C.h"
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

/*****/
int fInterna(){
    return 0;
}
