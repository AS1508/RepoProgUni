#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define F_PRODUCTOS "Productos.dat"

struct PRECIOS{
    int codigo;
    char descripcion;
    float precio;
};

void Muestra();

int main(){
    FILE*archivo;
    struct PRECIOS producto;
    int codigo, bandera = 0;
    char op;

    archivo = fopen(F_PRODUCTOS, "r+b");
    if(archivo == NULL){printf("chao");exit(1);}

    Muestra();

    printf("\n\nCodigo: ");
    scanf("%d", &codigo);
    while (codigo != 0){
        fread(&producto, sizeof(struct PRECIOS),1, archivo);
        while (!feof(archivo)){
            if(codigo == producto.codigo){
                bandera = 1;
                printf("Modificar descripcion? (Y/N) :: ");
                scanf("%c", &op);
                op = toupper(op);
                switch (op){
                case 'Y':
                    gets(producto.descripcion);
                    break;
                default:
                    printf("Modificacion cancelada\n");
                    break;
                }
                printf("Modificar precio? (Y/N):: ");
                scanf("%c", &op);
                switch (op)
                {
                case 'Y':
                    scanf("%f", &producto.precio);
                    break;
                
                default:
                    printf("Modificacion cancelada.\n");
                    break;
                }
                fseek(archivo, sizeof(struct PRECIOS)*-1, SEEK_CUR);
                fwrite(&producto, sizeof(struct PRECIOS),1, archivo);
                fflush(archivo);
            }else{fread(&producto, sizeof(struct PRECIOS),1, archivo);}
            
            if(bandera == 0){printf("\n\tCodigo Inexistente\n");}
        }

        Muestra();
        
        printf("codigo: ");
        scanf("%d", &codigo);
        fseek(archivo, 0, SEEK_SET);
    }
    fclose(archivo);
    return 0;
}