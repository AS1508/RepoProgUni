#include <stdlib.h>
#define F_BIN ".//Archivo/Origen.bin"
#define F_TXT ".//Archivo/destino.txt"

#define ERROR 1
#define OK 0

typedef struct {
    int legajo;
    char nombre[50];
    char apellido[50];
    float sueldo;
}t_Persona;

int crearArchivoBinario(const char *ruta);