#include<stdio.h>
#include<stdlib.h>

int main(){
    int matriz [5][4] = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}};
    int sumaFila[5]={0}, sumaColumna[4]={0}, c, f;

    for(f=0; f<5; f++)
        for(c=0; c<4; c++)
            sumaFila[f]+=matriz[f][c];

    for(c=0; c<4; c++)
        for(f=0; f<5; f++)
            sumaColumna[c]+=matriz[f][c];

    printf("SumaFila: ");
    for(int i=0; i<5; i++)
        printf(" | %d | ", sumaFila[i]);
    printf("\nSumaColumna: ");
    for(int i=0; i<4; i++) 
        printf(" | %d | ", sumaColumna[i]);

    return 0;
}