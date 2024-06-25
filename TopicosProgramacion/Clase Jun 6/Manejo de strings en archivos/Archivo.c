#include "Archivo.h"
int crearArchivoBinario(const char *ruta){
    FILE*fp = fopen(ruta, "wb");
    if(!fp) return ERROR;

    t_Persona seruGiran[4] = {
                                {10, "Pedro", "Aznar", 10.1},
                                {20, "Oscar", "Moro", 25.3},
                                {30, "David", "Lebon", 50.7},
                                {40, "Charly", "Garcia", 100.1}
                             };

    for(int i = 0; i<4; i++){
        fwrite(&seruGiran[i], sizeof(t_Persona), 1, fp);
    }

    fclose(fp);
    return OK;
}