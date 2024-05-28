#include <stdio.h>
#include "TLDE.c"

TLDE* desloca (TLDE* l, int n){
    TLDE *p = l;
    while(p->prox) p = p->prox;
    if(n % 2 != 0) {
        p->prox = l;
        l->ant = p;
        p->ant->prox = NULL;
        p->ant = NULL;
        return p;
    }
    else{
        TLDE *q = l->prox;
        p->prox = l;
        l->ant = p;
        q->ant = NULL;
        l->prox = NULL;
        return q;
    }
}

int main(void){
    int n, x;
    printf("Digite quantos numeros vao ter na lista: ");
    scanf("%d", &n);
    TLDE *l = TLDE_inicializa();
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }
    printf("Sua lista original: ");
    TLDE_imprime(l);
    printf("\n");
    l = desloca(l, n);
    printf("Sua lista deslocada: ");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}