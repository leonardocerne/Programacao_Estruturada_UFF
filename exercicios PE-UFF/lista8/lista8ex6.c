#include <stdio.h>
#include "TLSE.c"

TLSE* i_p (TLSE *l){
    TLSE *nova = NULL, *p = l;
    while(p) {
        if(p->info % 2 != 0){
            nova = TLSE_insere(nova, p->info);
            p = p->prox;
        }
        else p = p->prox;
    }
    p = l;
    while(p) {
        if(p->info % 2 == 0) {
            nova = TLSE_insere(nova, p->info);
            p = p->prox;
        }
        else p = p->prox;
    }
    inverte(nova);
    return nova;
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
    TLSE *nova = i_p(l);
    printf("Aqui esta a lista nova: ");
    TLSE_imprime(nova);
    TLSE_libera(l);
    TLSE_libera(nova);
    return 0;
}