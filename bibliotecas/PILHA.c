#include "PILHA.h"

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