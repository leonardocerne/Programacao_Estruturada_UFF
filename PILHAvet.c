#include "PILHA.h"

struct pilha{
    int n, topo;
    int *vet;
};

TP *TP_cria(){
    TP *p = (TP*)malloc(sizeof(TP));
    p->n = 10;
    p->topo = 0;
    p->vet = (int*)malloc(sizeof(int) * p->n);
    return p;
}

int TP_vazia(TP *p){
    return p->topo == 0;
}

void TP_push(TP *p, int x){
    if(p->topo == p->n){
        p->n *= 2;
        p->vet = realloc(p->vet, p->n *sizeof(int));
    }
    p->vet[p->topo++] = x;
}

void TP_libera(TP *p){
    free(p->vet);
    free(p);
}

int TP_pop(TP *p){
    if(TP_vazia(p)) exit(1);
    int resp = p->vet[--p->topo];
    if(p->topo <= p->n / 4){
        p->n /= 2;
        p->vet = realloc(p->vet, p->n * sizeof(int));
    }
    return resp;
}

