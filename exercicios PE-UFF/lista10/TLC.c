#include "TLC.h"

TLC *TLC_inicializa(){
    return NULL;
}

void TLC_imprime(TLC *l){
    if(l){
        printf("%d ", l->info);
        TLC *p = l->prox;
        while(p != l){
            printf("%d ", p->info);
            p = p->prox;
        }
    }
}

void aux(TLC *atual, TLC *l){
    if(atual == l) return;
    printf("%d\n", atual->info);
    aux(atual->prox, l);
}

void TLC_imp_rec(TLC *l){
    if(!l) return;
    printf("%d\n", l->info);
    aux(l->prox, l);
}

void TLC_libera(TLC *l){
    if(!l) return;
    TLC *p = l->prox, *t;
    while(p != l){
        t = p;
        p = p->prox;
        free(t);
    }
    free(l);
}

TLC *TLC_busca(TLC *l, int x){
    if((!l) || (l->info == x)) return l;
    TLC *p = p->prox;
    while((p != l) && (p->info != x)) p = p->prox;
    if(p != l) return p;
    return NULL;
}

TLC *TLC_ins_mais_facil(TLC *l, int x){
    TLC *novo = (TLC*)malloc(sizeof(TLC));
    novo->info = x;
    if(!l){
        novo->prox = novo;                              // insere sempre na segunda posição
        return novo;                                    // ex: se eu tenho uma lista [3, 2, 1] e quero inserir o elemento 5
    }                                                   // então a lista vira [3, 5, 2, 1]
    novo->prox = l->prox;
    l->prox = novo;
    return l;
}

TLC *TLC_ins_ult(TLC *l, int x){
    if((!l) || (l->prox == l)) return TLC_ins_mais_facil(l, x);
    TLC *ant = l, *p = l->prox;
    while(p != l){
        ant = p;
        p = p->prox;
    }
    TLC *novo = (TLC*)malloc(sizeof(TLC));
    novo->info = x;
    ant->prox = novo;
    novo->prox = l;
}

TLC *retira(TLC *l, int x){
    if(!l) return l;
    if((l->prox = l) && (l->info == x)){
        free(l);
        return NULL;
    }
    TLC *ant = l, *p = l->prox;
    if(l->info == x){
        while(p != l){
            ant = p;
            p = p->prox;
        }
    }
    else{
        while((p != l) && (p->info != x)){
            ant = p;
            p = p->prox;
        }
        if(p == l) return l;
    }
    ant->prox = p->prox;
    if(p == l) l = l->prox;
    free(p);
    return l;
}

void inverte(TLC *l){
    TLC *p = l;
    int tam = 0, fim, tmp;
    do{
        tam++;
        p = p->prox;
    }while(p != l);
    p = l;
    fim = tam - 1;
    for(int i = 0; i < tam / 2; i++) {
        TLC *q = p;
        for(int j = 0; j < fim; j++) {
            q = q->prox;
        }
        tmp = q->info;
        q->info = p->info;
        p->info = tmp;
        p = p->prox;
        fim -= 2;
    }
}