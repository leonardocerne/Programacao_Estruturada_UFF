#include <stdio.h>
#include "TLSE.c"

TLSE *desloca(TLSE *l) {
    TLSE *p = l;
    int aux = p->info;
    while(p->prox) {
        p->info = p->prox->info;
        p = p->prox;
    }
    p->info = aux;
    return l;
}

void i_p (TLSE *l){
    TLSE *p = l;
    int tam = 1;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    while(tam >= 0){
        if(p->info % 2 == 0) {
            p = desloca(p);
            tam--;
        }
        else {
            p = p->prox;
            tam--;
        }
    }
}

int main(void) {
    int n, x;
    printf("Insira quantos elementos voce quer na lista: ");
    scanf("%d", &n);
    TLSE *l = TLSE_inicializa();
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLSE_insere(l, x);
    }
    printf("Aqui esta a lista original: ");
    TLSE_imprime(l);
    printf("\n");
    i_p(l);
    printf("Aqui esta a lista alterada: ");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}