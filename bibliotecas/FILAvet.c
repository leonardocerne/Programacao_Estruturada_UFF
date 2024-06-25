#include "FILA.h"

struct fila {
    int *vet, tam, n, ini;
};

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

void TF_insere(TF *f, int x){
    if(f->n == f->tam){
        int *novo = (int*)malloc(sizeof(int) * 2 * f->tam), j, i, *p;
        i = f->ini;
        for(j = 0; j < 0; j++){
            novo[j] = f->vet[i];
            i = (i+1) % f->tam;
        }
        f->ini = 0;
        f->tam *= 2;
        p = f->vet;
        f->vet = novo;
        free(p);
    }
    int pos_elem = (f->ini + f->n) % f->tam;
    f->vet[pos_elem] = x;
    f->n++;
}

void TF_retira(TF *f){
    if(TF_vazia(f)) exit(1);
    int resp = f->vet[f->ini];
    f->ini = (f->ini + 1) % f->tam;
    f->n--;
    if(f->n <= (f->tam/4)){
        int *novo = (int*)malloc(sizeof(int) * (f->tam / 2)), i, j;
        i = f->ini;
        for(j = 0; j < f->n; j++){
            novo[j] = f->vet[i];
            i = (i+1) % f->tam;
        }
        f->ini = 0;
        f->tam /= 2;
        free(f->vet);
        f->vet = novo;
    }
    return resp;
}

void realoca(TF *f, int novo_tam){
    int *novo = (int *)malloc(sizeof(int)* novo_tam), j, i;
    i = f->ini;
    for(j = 0; j < f->n; j++){
        novo[j] = f->vet[i];
        i = (i+1) % f->tam;
    }
    f->ini = 0; f->tam = novo_tam;
    free(f->vet); f->vet = novo;
}