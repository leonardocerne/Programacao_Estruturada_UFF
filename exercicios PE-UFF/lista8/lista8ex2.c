#include <stdio.h>
#include "TLSE.c"

TLSE *inverte(TLSE *l) {
    TLSE *nova = NULL, *p = l;
    int x;
    while(p) {
        x = p->info;
        nova = TLSE_insere(nova, x);
        p = p->prox;
    }
    return nova;
}

int main(void) {
    TLSE *l = TLSE_inicializa();
    int x, n;
    printf("Insira quantos elementos voce quer botar na lista: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLSE_insere(l, x);
    }
    printf("A lista original e: ");
    TLSE_imprime(l);
    printf("\n");
    TLSE *nova = inverte(l);
    printf("A lista original continua sendo: ");
    TLSE_imprime(l);
    printf("\n");
    printf("E a lista invertida fica: ");
    TLSE_imprime(nova);
    TLSE_libera(l);
    TLSE_libera(nova);
    return 0;
}