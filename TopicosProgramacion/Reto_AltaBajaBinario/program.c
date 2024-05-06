#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 

 
int main(){
    unsigned char a = 0x26;
    printf("%c\n", a);
    a<<=2;
    printf("%c", a);
    return 0;
}