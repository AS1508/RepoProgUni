#include "Merge.h"
#include <stdlib.h>


void fusionarArchivo(const char *pathA, const char *pathB, const char *pathS){
    FILE*fpA; 
    FILE*fpB; 
    FILE*fpS;

    fpA = fopen(pathA, "rb");
    if(!fpA) return -1;
    fpB = fopen(pathB, "rb");
    if(!fpB){
        fclose(fpA);
        return -1;
    }
    fpS = fopen(pathS, "wb");
    if(!fpS){
        fclose(fpA);
        fclose(fpB);
        return -1;
    }
    int ret = combinarArchivos(fpA, fpB, fpS);
    fclose(fpA);
    fclose(fpB);
    fclose(fpS);
    return ret;
}

int combinarArchivos(FILE *fpA, FILE *fpB, FILE *fpS){
    tPersona a, b;
    long posA = ftell(fpA), posB = ftell(fpB);
    rewind(fpA);
    rewind(fpB);

    fread(&a, sizeof(tPersona), 1, fpA);
    fread(&b, sizeof(tPersona), 1, fpB);
    while(!feof(fpA) &&!feof(fpB)){
        if(a.dni < b.dni){
            fwrite(&a, sizeof(tPersona), 1, fpS);
            fread(&a, sizeof(tPersona), 1, fpA);
        }else if(a.dni > b.dni){
            fwrite(&b, sizeof(tPersona), 1, fpS);
            fread(&b, sizeof(tPersona), 1, fpB);
        }else{
            fwrite(&a, sizeof(tPersona), 1, fpS);
            fread(&a, sizeof(tPersona), 1, fpA);
            fwrite(&b, sizeof(tPersona), 1, fp);
            fread(&b, sizeof(tPersona), 1, fpB);
        }
    }
    while(!feof(fpA)){
        int a;
        fwrite(&a, sizeof(tPersona), 1, fpS);
        fread(&a, sizeof(tPersona), 1, fpA);
    }
    
    while(!feof(fpB)){
        int b;
        fwrite(&b, sizeof(int), 1, fpS);
        fread(&b, sizeof(int), 1, fpB);
    }

    fseek(fpA, posA, SEEK_SET);
    fseek(fpB, posB, SEEK_SET);

    return MERGE_OK;
}