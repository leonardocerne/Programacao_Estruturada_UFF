#include "FILA.h"
#include "PILHA.h"

void imp(TF *f){
    if(TF_vazia(f)) return;
    TF *aux = TF_cria();
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        printf("%d\n", x);
        TF_insere(aux, x);
    }
    while(!TF_vazia(aux)) TF_insere(f, TF_retira(aux));
    TF_libera(aux);
}

void imp_rev(TF *f){
    if(TF_vazia(f)) return;
    TP *p1 = TP_cria(), *p2 = TP_cria();
    while(!TF_vazia(f)) TP_push(p1, TF_retira(f));
    while(!TP_vazia(p1)){
        int x = TP_pop(p1);
        printf("%d\n", x);
        TP_push(p2, x);
    }
    while(!TP_vazia(p2)) TF_insere(f, TP_pop(p2));
    TP_libera(p1);
    TP_libera(p2);
}
