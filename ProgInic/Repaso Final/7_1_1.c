#include<stdio.h>
#include<stdlib.h>

int main(){
    int vector1[5]={10, 9, 8, 7, 6}, vector2[5]={5, 4, 3, 2, 1}, vectorFinal[10]={0}, i=0;

    while(i<10){
        if(i<5)
            vectorFinal[i]=vector1[i];
        if(i>=5)
            vectorFinal[i]=vector2[i-5];

        i++;
    }

    for(i=0; i<10; i++)
        printf(" | %d |", vectorFinal[i]);

    return 0;
}