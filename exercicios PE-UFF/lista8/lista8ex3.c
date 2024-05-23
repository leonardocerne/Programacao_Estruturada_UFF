#include <stdio.h>
#include "TLSE.c"

TLSE *desloca(TLSE *l, int n) {
    if (n % 2 != 0) {
        TLSE *p = l, *q = l, *aux = l;
        for(int j = 0; j < n-2; j++) aux = aux->prox;
        for(int i = 0; i < n-1; i++) {
            q = q->prox;
        }
        q->prox = p;
        aux->prox = NULL;
        return q;
    }
    else {
        TLSE *p = l, *q = l, *aux = l;
        aux = aux->prox;
        for(int m = 0; m < n-1; m++) q = q->prox;
        q->prox = p;
        p->prox = NULL;
        return aux;
    }
}

int main(void){
    int n, x;
    printf("Digite quantos numeros vao ter na lista: ");
    scanf("%d", &n);
    TLSE *l = TLSE_inicializa();
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        l = TLSE_insere(l, x);
    }
    printf("Sua lista original: ");
    TLSE_imprime(l);
    printf("\n");
    l = desloca(l, n);
    printf("Sua lista deslocada: ");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}