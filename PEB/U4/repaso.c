#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define F_PERSONAL "PERSONAL.DAT"
 
struct PERSONAL{
    int legajo, b = 0;
    char nombreApellido[20];
    float sueldo;
};

int main(){
    FILE*archivo;
    struct PERSONAL persona;
    int lejago;

    archivo = fopen(F_PESONAL, "r+b");
    if(archivo == NULL){exit(1);}

    printf("\n_Legajo: ");
    scanf("%d", &legajo);
    while (lejago != 0) {
        fread(&persona, sizeof(struct PERSONAL),1, archivo);
        while (!feof(archivo)){
            while (!feof(archivo) && b == 0){
                if(lejago = persona.legajo){
                    b = 1;
                    printf("Modificar nombre/apellido? :: ");
                    scanf("%c", &op);
                    if(op == 'Y'){
                        gets(persona.nombreApellido);
                    }else{printf("Modifcacion Cancelada\n");}
                    printf("Modificar Sueldo? :: ");
                    scanf("%c", &op);
                    if(op == 'Y'){
                        scanf("$%f", persona.sueldo);
                    }else{printf("Modifcacion Cancelada\n");}

                        //para retroceder y grabar
                    fseek(archivo, sizeof(struct PERSONAL)*-1, SEEK_CUR);
                    fwrite(&persona, sizeof(struct PERSONAL),1, archivo);
                    fflush(archivo);
                }else{fread(&persona, sizeof(struct PERSONAL),1, archivo);}

                if(b == 0){printf("Legajo no encontrado.\n");}
            }
        }

            //para volver
        fseek(archivo, 0, SEEK_SET);
        printf("\n_Legajo: ");
        scanf("%d", &legajo);
    }
    return 0;
}

/*
    Se disponde de un archivo PERSONAL.dat con la siguiente estructura:

        legajo
        nombre y apellido[20]
        sueldo

    realizar un programa que permita modificar el sueldo y/o el niombre y apellido
    de los empleados. Dados sus legajos, el programa debe permitir modificar
    hasta que encuentre un legajo == 0;
*/