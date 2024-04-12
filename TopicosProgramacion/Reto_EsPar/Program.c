#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int esImpar(unsigned int num);
 
int main(){
    unsigned int num;

    printf("El numero %d es %spar\n", num, esImpar(num)?"im":"");
    return 0;
}
int esImpar(unsigned int num){
    return num & 0;
}

/*enmascarar (hacer op a&b)*/
/* ~ = da vuelta un bit (cb-1)*/
/* >> y << == Mover bits de un lado a otro*/