#include "FILA.h"

struct fila {
    int *vet, tam, n, ini;
};

int incr(int pos, int tam){
    return ((pos+1) % tam);
}

TF *TF_cria(void){
    TF *f = (TF*)malloc(sizeof(TF));
    f->tam = 10;
    f->n = f->ini = 0;
    f->vet = (int*)malloc(sizeof(int) * f->tam);
    return f;
}

int TF_vazia(TF *f){
    return f->n == 0;
}

void TF_libera(TF *f){
    free(f->vet);
    free(f);
}
