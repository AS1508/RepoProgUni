#include<stdio.h>
#include<ctype.h>
#include<string.h>
int valida(int, int, int);
int leeyvalida(int,int);

int main(){
    int cp, i=0, cv, mes, cant, j, precio;
    int vP[30];
    float m[30][12]={{0}};
    char rta;

    cp=valida(1000, 9999, 0);
    while(cp!=0 && i<30){
    
    vP[i]=cp;
    printf("ingrese mes:");
    mes=leeyvalida(1, 12);
    do{
        printf("cantidad:");
        scanf("%d", &cv);

    }while(cv<=0);

    printf("precio:");
    scanf("%f", &precio);

    if(m[i][mes-1]==0){
        m[i][mes-1]=cv*precio;
    }else{
        printf("reemplazar?\n");
        gets(rta);
        rta=tupper(rta);
        if(rta='s'){
            m[i][mes-1]=cv*precio;
        }
    }
    
    printf("Producto:");
    cp=valida(1000, 9999, 0);

    }

    cant=i;
    
    printf("mes\n");
    printf("prod\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12");

    for(i=0; i<cant;i++){
        printf("%d", vP[i]);
        for(j=0;j<12; j++){
            printf("&.2f", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
int valida(int li, int ls, int fin){
    int x;
    do{
        scanf("%d", &x);

    }while((x<li || x>ls) && (x!=fin));
    return x;
}
int leeyvalida(int li,int ls){
    int x;
    do{
        scanf("%d", &x);

    }while(x<li || x>ls);
    return(x);
}

//int valida(int , int)

/*

    Vars: Cod prod (5 cifras) / mes (1 a 12) / cant ventas / precio (float)
    prod(vec), ventas(matriz)
*/

    //cp= valida(1000, 9999, 0);
    /*
    while(cp!=0 && i<30){
        vprod[i] = cp
        mes=leeyvalida(1, 12)
        do{
            scanf(cv)

        }while(cv<=0)
        scanf(precio)

        if(m[i][mes-1]==0){
            m[i][mes]=cv*precio
        }else{
            print(reemplazar?)
            gets(rta)
            if(rta='s'){
                mes[i][mes-1]=cv*precio
            }
            cp=valida(1000, 9999, 0)
        }

        for(i=0;i<cant;i++){
            vprod[i]
            for(j=0;j<12, j++){
                print(m[i][j]\n)
            }
        }
        

    }
    
    
    */