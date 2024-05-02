#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

int main()
{
    /*1*/
    double f = Factorial(10);
    printf("1) %.3f\n", f);
    /*2*/
    double comb = Combinatorio(10, 20);
    printf("2) %.3f\n", comb);
    /*3*/
    double e = ex(2, 3);
    printf("3) %.3f\n", e);
    /*5*/
    double fib = 4;
    if(Fibonacci(fib))
        printf("5) Pertenece a Fibonacci.");
    else
        printf("5) No pertenece a fibonacci.");
    /*6*/
    float sen = seno(3, 3);
    printf("6) %.3f", sen);

    return 0;
}
