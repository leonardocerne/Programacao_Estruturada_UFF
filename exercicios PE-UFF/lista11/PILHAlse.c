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

void imprime(TP *p){
    TP *aux = TP_cria();
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        printf("%d\n", x);
        TP_push(aux, x);
    }
    while(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
    TP_libera(aux);
}

void ordena(TP *p){
    if(TP_vazia(p)) return;
    TP *a1 = TP_cria(), *a2 = TP_cria();
    while(!TP_vazia(p)){
        int menor = TP_pop(p);
        while(!TP_vazia(p)){
            int x = TP_pop(p);
            if(x < menor){
                TP_push(a1, menor);
                menor = x;
            }
            else TP_push(a1, x);
        }
        TP_push(a2, menor);
        while(!TP_vazia(a1)) TP_push(p, TP_pop(a1));
    }
    while(!TP_vazia(a2)) TP_push(p, TP_pop(a2));
    TP_libera(a1); TP_libera(a2);
}
