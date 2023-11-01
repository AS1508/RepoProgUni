#include <stdio.h>
#include <stdlib.h>

struct canales{int nrocanal;
               char programa[36];
               float rating;
};

struct promedio{int nrocanal;
                float promrating;};

int main()
{
    FILE * archivo;
    FILE * archi2;
    int cont;
    float total,max;
    struct canales c;
    int nrocanalanterior,maxcanal, b=0;
    struct promedio p;

    archivo=fopen("Rating.dat","rb");
    if (archivo==NULL)
    {
        printf("Error");
        exit(1);

    }
    archi2=fopen("Promedio.dat","wb");
    if (archi2==NULL)
    {
        printf("Error");
        exit(1);

    }

    fread(&c,sizeof(struct canales),1,archivo);

    while(!feof(archivo))
    {nrocanalanterior=c.nrocanal;

     total=0;cont=0;

    while((!feof(archivo))&& (nrocanalanterior==c.nrocanal))
    {total+=c.rating; cont++;
     printf("%d %f\n",c.nrocanal,c.rating);
     fread(&c,sizeof(struct canales),1,archivo);
    }

   if(total<15)
        printf("%d \t %f \n",nrocanalanterior,total);

    if (b==0 || max<total)
    {
        b=1;
            max=total;
            maxcanal=nrocanalanterior;
    }

   if (cont!=0)
    { p.promrating=total/cont;
    p.nrocanal=nrocanalanterior;
    fwrite(&p,sizeof(struct promedio),1,archi2);
    }

   }
    printf("El canal con mas rating es %d con %f",maxcanal,max);

    fclose(archivo);
    fclose(archi2);

return 0;
}