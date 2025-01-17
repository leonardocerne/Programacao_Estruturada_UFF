#include "TLDE.h"

TLDE* TLDE_inicializa(){
  return NULL;
}

void TLDE_imprime(TLDE *l){
  TLDE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLDE_imp_rec(TLDE *l){
  if(l){
    printf("%d ", l->info);
    TLDE_imp_rec(l->prox);
  }
}

void TLDE_imp_rec_rev(TLDE *l){
  if(l){
    TLDE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLDE_libera(TLDE *l){
  TLDE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void TLDE_lib_rec(TLDE *l){
  if(l){
    TLDE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLDE* TLDE_busca(TLDE *l, int elem){
  TLDE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

TLDE* TLDE_busca_rec(TLDE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLDE_busca_rec(l->prox, elem);
}

TLDE *TLDE_ins_ini(TLDE *l, int x){
    TLDE *novo = (TLDE *)malloc(sizeof(TLDE));
    novo->info = x;
    novo->prox = l;
    novo->ant = NULL;
    if(l) l->ant = novo;
    return novo;
}

TLDE *TLDE_retira(TLDE *l, int x) {
    TLDE *p = TLDE_busca(l, x);
    if(!p) return l;
    if(p==l) l = l->prox;
    else p->ant->prox = p->prox;
    if(p->prox) p->prox->ant = p->ant;
    free(p);
    return l;
}

TLDE *TLDE_ins_ord(TLDE *l, int x){
    if((!l) || (l->info >= x)) return TLDE_ins_ini(l, x);
    TLDE *p = l, *ant = NULL;
    while((p) && (p->info<x)){
        ant = p;
        p = p->prox;
    }
    TLDE *novo = TLDE_ins_ini(NULL, x);
    ant->prox = novo;
    novo->ant = ant;
    novo->prox = p;
    if(p) p->ant = novo;
    return l;
}

TLDE *TLDE_ins_ord_rec(TLDE *l, int x) {
    if((!l) || (l->info >= x)) return TLDE_ins_ini(l, x);
    l->prox = ior_aux(l->prox, x, l);
    return l;
}

TLDE *ior_aux(TLDE *l, int x, TLDE *ant){
    if((!l) || (l->info >= x)){
        TLDE *novo = TLDE_ins_ini(NULL, x);
        novo->prox = l;
        novo->ant = ant;
        if(l) l->ant = novo;
        ant->prox = novo;
        return novo;
    }
    l->prox = ior_aux(l->prox, x, l);
    return l;
}

void inverte(TLDE *l) {
    TLDE *p = l;
    int tam = 0, tmp;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    int fim = tam - 1;
    for(int i = 0; i < tam / 2; i++) {
        TLDE *q = p;
        for(int j = 0; j < fim; j++) {
            q = q->prox;
        }
        tmp = q->info;
        q->info = p->info;
        p->info = tmp;
        p = p->prox;
        fim -= 2;
    }
    return;
}