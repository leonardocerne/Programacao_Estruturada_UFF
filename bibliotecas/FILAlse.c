#include "FILA.h"
#include "TLSE.c"

struct fila{
    TLSE *ini, *fim;
};

TF *TF_cria(void){
    TF *f = (TF*)malloc(sizeof(TF));
    f->ini = f->fim = NULL;
    return f;
}

int TF_vazia(TF *f) {
    return f->ini == NULL;
}

void TF_insere(TF *f, int x){
    TLSE *novo = (int*)malloc(sizeof(TLSE));
    novo->prox = NULL;
    if(f->fim) f->fim->prox = novo;
    else f->ini = novo;
    f->fim = novo;
}

int TF_retira(TF *f){
    if(TF_vazia(f)) exit(1);
    int resp = f->ini->info;
    TLSE *p = f->ini;
    f->ini = f->ini->prox;
    if(!f->ini) f->fim = NULL;
    free(p);
    return resp;
}

void TF_libera(TF *f){
    TLSE_libera(f->ini);
    free(f);
}