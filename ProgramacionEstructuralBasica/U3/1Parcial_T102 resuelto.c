#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define botellas 100
#define colores 5

typedef struct
{
    char  codEnv [10];
    int   color;
    float total;
}Nuevo;

typedef struct
{
    char  codEnv [10];
    int   codMat;
    char  descri [26];
    float precio;
}envases;

typedef struct
{
    char codEnv [10];
    int  color;
    int  cantVend;
}vidrio;

int  cargarinventario (envases []);
int  busqueda         (vidrio,envases [],int);
void mostrarinforme   (float[][colores], envases[], int);
void creararchivo     (float[][colores], envases[], int);

int main ()
{
    int cant=0,posicion;
    float matriz [botellas][colores];
    envases env[botellas];
    vidrio vid;

    cant=cargarinventario(env);

    FILE*vd;
    vd=fopen("VentasEnvases_Vidrio.dat","rb");
    fread(&vid,sizeof(vid),1,vd);
    while(!feof(vd))
    {
        posicion=busqueda(vid,env,cant);
        if (posicion!=-1)
        {
            matriz[posicion][vid.color]+=(env[posicion].precio*vid.cantVend);
        }
        else
        {
            printf ("Codigo de envase %s inexistente",vid.codEnv);
        }
    fread(&vid,sizeof(vid),1,vd);
    }
    mostrarinforme (matriz,env,cant);
    creararchivo   (matriz,env,cant);
    return 0;
}

int cargarinventario (envases env [])
{
    int cant=0;
    envases aux;
    FILE*ev;
    ev=fopen ("Envases.dat","rb");
    if (ev==NULL)
    {
        printf ("ERROR AL ABRIR EL ARCHIVO");
        exit (1);
    }
    fread(&aux,sizeof(aux),1,ev);
    while(!feof(ev) || cant==botellas)
    {
      env [cant]=aux;
      cant++;
      fread(&aux,sizeof(aux),1,ev);
    }
    fclose(ev);
    return (cant);
}

int busqueda (vidrio vid, envases env [],int cant)
{
    int pos=-1,ciclos=0;
    while (pos!=-1 || ciclos<=cant)
    {
        if (strcmpi(env[ciclos].codEnv,vid.codEnv)==0)
        {
            pos=ciclos;
        }
        else
        {
            ciclos ++;
        }

    }
    return (pos);
}

void mostrarinforme (float matriz [][colores],envases env [], int cant)
{
    int i=0, b=0, band=0;
    printf ("%7s","Cod.Env");
    for (i=0;i<colores;i++)
    {
        printf ("%5d",i);
    }
    for (i=0;i<cant;i++)
    {
        for (b=0;b<colores;b++)
        {
            if (band==0)
               printf ("\n%7s",env[i].codEnv);
            else
            {
               printf ("%5d",matriz[i][b]);
               band=1;
            }
        }
        band=0;
    }
}

void creararchivo (float matriz [][colores],envases env [], int cant )
{
     int i=0,b=0;
     Nuevo EnvVid [cant];

     for (i=0;i<cant;i+5)
     {
         for(b=0;b<colores;b++)
         {
             strcpy(EnvVid[i+b].codEnv,env[i].codEnv);
             EnvVid[i+b].color=b;
             EnvVid[i+b].total=matriz[i][b];
         }
     }

     i=0;
     FILE*nv;
     nv=fopen("Envases_Vidrio.dat","wb");
     if (nv==NULL)
     {
         printf ("ERROR AL ABRIR EL ARCHIVO");
         exit (1);
     }
     while (i!=cant)
     {
        fwrite(&EnvVid[i],sizeof(EnvVid),1,nv);
        i++;
     }
     fclose(nv);
}
