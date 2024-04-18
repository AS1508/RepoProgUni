#include <stdio.h>
#include <stdlib.h>
#include "C.h"

int main()
{
    double f = Factorial(10);
    printf("1) %.3f\n", f);

    double comb = Combinatorio(10, 20);
    printf("2) %.3f\n", comb);

    double e = ex(2, 3);
    printf("3) \0.3f\n", ex);

    return 0;
}
