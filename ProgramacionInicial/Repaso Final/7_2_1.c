#include<stdio.h>
#include<stdlib.h>
#define N 10

int main(){
    int matriz[3][3]={{1, 3, 4},{3, 4, 1},{4, 1, 3}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            printf("\t|%d|", matriz[i][j]);
        printf("\n");
    }

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            matriz[i][j]*=N;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            printf("\t|%d|", matriz[i][j]);
        printf("\n");
    }

    return 0;
}