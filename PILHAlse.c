#include "PILHA.h"
#include "TLSE.c"

typedef struct lse{
    int info;
    struct lse *prox;
}TLSE;

struct pilha{
    TLSE *topo;
};

TP *TP_cria(void){
    TP *p = (TP*)malloc(sizeof(TP));
    p->topo = NULL;
    return p;
}

int TP_vazia(TP *p){
    return p->topo == NULL;
}

void TP_push(TP *p, int x){
    TLSE *novo = TLSE_ins_ini(p->topo, x);
    p->topo = novo;
}

int TP_pop(TP *p){
    if(TP_vazia(p)) exit(1);
    int resp = p->topo->info;
    TLSE *t = p->topo;
    p->topo = t->prox;
    free(t);
    return resp;
}

void TP_libera(TP *p){
    TLSE_libera(p->topo);
    free(p);
}


