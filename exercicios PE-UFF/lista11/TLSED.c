#include "TLSED.h"

TLSED *TLSED_inicializa(void){
    TLSED *l = (TLSED *)malloc(sizeof(TLSED));
    l->prim = NULL;
    return l;
}

TLSE *TLSED_busca(TLSED *l, int x){
    TLSE *resp = l->prim;
    while((resp) && (resp->info != x)) resp = resp->prox;
    return resp;
}
void TLSED_ins_ini(TLSED *l,int x){
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    novo->info = x;
    novo->prox = l->prim;
    l->prim = novo;
}
void TLSED_retira(TLSED *l, int x){
    TLSE *p = l->prim, *ant = NULL;
    while((p) && (p->info != x)){
        ant = p;
        p = p->prox;
    }
    if(!p) return;
    if(!ant) l->prim = p->prox;
    else ant->prox = p->prox;
    free(p);
}    
void TLSED_imprime(TLSED *l){
    TLSE *p = l->prim;
    while(p){
        printf("%d ", p->info);
        p = p->prox;
    }
}
void TLSED_libera(TLSED *l){
    TLSE *p = l->prim, *q;
    while(p){
        q = p;
        p = p->prox;
        free(q);
    }
    free(l);
}
