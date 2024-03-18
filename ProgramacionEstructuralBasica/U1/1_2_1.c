#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
int main(){
    char texto[500];
    int cont=0, lim;
    fgets(texto, 500, stdin);
    lim=strlen(texto);
    printf("%d\n", lim);
    for(int i=0; i<=lim; i++){
        if(texto[i]==' ' || texto[i] == '\0'){
            cont++;
        }
    }
    printf("El texto tiene %d palabras", cont);
    return 0;
}