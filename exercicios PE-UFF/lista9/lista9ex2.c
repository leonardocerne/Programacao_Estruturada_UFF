#include <stdio.h>
#include "TLDE.c"

TLDE *inverte(TLDE *l) {
    TLDE *nova = NULL, *p = l;
    int x;
    while(p) {
        x = p->info;
        nova = TLDE_ins_ini(nova, x);
        p = p->prox;
    }
    return nova;
}

int main(void) {
    TLDE *l = TLDE_inicializa();
    int x, n;
    printf("Insira quantos elementos voce quer botar na lista: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }
    printf("A lista original e: ");
    TLDE_imprime(l);
    printf("\n");
    TLDE *nova = inverte(l);
    printf("A lista original continua sendo: ");
    TLDE_imprime(l);
    printf("\n");
    printf("E a lista invertida fica: ");
    TLDE_imprime(nova);
    TLDE_libera(l);
    TLDE_libera(nova);
    return 0;
}