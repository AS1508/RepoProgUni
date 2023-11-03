#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define F_AGENDA "Agenda.dat"
#define F_TEMPORAL "temporal.dat"
 
struct AGENDA
{
    char nombre[31];
    int numero;

};
struct AGENDA Busqueda(char[]);
int Menu();
int leeyvalida(int, int, int);
void eliminarRegistro(char[]);


//Ejercicio 5.5
 
int main(){
    FILE*archivo;
    struct AGENDA contacto;
    int op, cantidadRegistros;
    char nombre[30];

    op=Menu();
    while(op!=0){
        if(op==1){
            archivo=fopen(F_AGENDA, "r+b");
            if(archivo==NULL){printf("chau");exit(1);}
            fseek(archivo, 0, SEEK_END);
            cantidadRegistros=ftell(archivo) / sizeof(struct AGENDA);
            printf("La cantidad de Contactos son O%d\n\n", cantidadRegistros);
            fclose(archivo);
        }else if(op==2){
            archivo=fopen(F_AGENDA, "a+b");
            if(archivo==NULL){printf("chau");exit(1);}
            printf("Buscador: ");
            fflush(stdin);
            gets(nombre);
            contacto=Busqueda(nombre);
            if(contacto.nombre!=-1)
                printf("Contacto existente.\n\n");
            else{
                printf("nombre: ");
                scanf("%d", &contacto.nombre);
                printf("numero: ", &contacto.numero);
                strcpy(contacto.nombre, nombre);
                fseek(archivo, sizeof(struct AGENDA), SEEK_CUR);
                fwrite(&contacto, sizeof(struct AGENDA),1, archivo);
                printf("\n\tGUARDADO\n\n")
                fclose(archivo);
            }
        }else if(op==3){
            archivo=fopen(F_AGENDA, "a+b");
            if(archivo==NULL){printf("chau");exit(1);}
            printf("Buscador: ");
            fflush(stdin);
            gets(nombre);
            contacto=Busqueda(nombre);
            if(contacto.nombre==-1)
                printf("No se encontro.\n\n");
            else
                printf("numero: %d", contacto.numero);
            fclose(archivo);
        }else if(op==5){
            printf("Nombre: ");
            fflush(stdin);
            gets(nombre);
            eliminarRegistro(nombre);
        }
        op=Menu();
    }

    return 0;
}

void eliminarRegistro(char nombre[]){
    FILE*archivo, *temporal;
    struct AGENDA contacto;
    int i=0;
    archivo=freopen(F_AGENDA, "rb");
    temporal=fopen(F_TEMPORAL, "wb");
    if(archivo == NULL || temporal == NULL){printf("chau"); exit(1);}
    fread(&contacto, sizeof(struct AGENDA),1, archivo);
    while(!feof(archivo)){
        if(strcmp(contacto.nombre, nombre)!=0)
            fwrite(&contacto, sizeof(struct AGENDA),1, temporal);
        fread(&contacto, sizeof(struct AGENDA),1, archivo);
        fclose(archivo);
        fclose(temporal);
        remove(F_AGENDA);
        rename(F_TEMPORAL, F_AGENDA);
    }
}
int Menu(){
    int op;
    printf("\tMENU\n\n");
    printf("1)Cantidad de contactos\n2)Nuevo contacto\n3)Buscar contacto\n4)Modificar contacto\n5)Borrar contacto\n0)salir\n\n >");
    op=leeyvalida(1, 5, 0);
    return op;
}
struct AGENDA Busqueda(char nombre[]){
    FILE*archivo;
    struct AGENDA contacto;
    int encontrado=0;
    archivo=fopen(F_AGENDA, "rb");
    if(archivo==NULL){printf("mefui");exit(1);}
    fread(&contacto, sizeof(struct AGENDA),1,archivo);
    while(!feof(archivo) && encontrado==0){
        if(strcmpi(contacto.nombre, nombre)==0)
            encontrado=1;
        else
            fread(&contacto, sizeof(struct AGENDA),1,archivo);

        if(encontrado==0)
            encontrado=-1;
    }

        fclose(archivo);
        return contacto;
}
int leeyvalida(int li, int ls, int fin){
    int numero;
    do{
        scanf("%d", &numero);
    }while((numero<1 || numero>5) && numero!=0);
}

    /*
    _regresa al comienzo del archivo
    //rewind(FILE*f)
    _Conocer posicion actual del archivo y cantdad de registros
    //fseek(arhivo, 0, seek-end)
    //cantidad de registros=ftell(archivo) / sizeof(struct xxxx)
    _cambia el nombre de un archivo por otro
    //rename(nombre archivo actual, nombre archivo mundo)
    _elimina un archivo
    //remove(nombre archivo)
*/