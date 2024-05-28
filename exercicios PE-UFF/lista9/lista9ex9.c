#include <stdio.h>
#include "TLDE.c"

TLDE* junta_listas (TLDE* l1, TLDE* l2){
    TLDE *p = l1, *q = l2, *ult;
    while(p){
        ult = p;
        p = p->prox;
    }
    ult->prox = l2;
    l2->ant = ult;
    return l1;
}

int main(void) {
    int n1, n2, x;
    printf("Insira quantos elementos voce quer na lista 1 e 2: ");
    scanf("%d%d", &n1, &n2);
    TLDE *l1 = TLDE_inicializa();
    TLDE *l2 = TLDE_inicializa();
    for(int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = TLDE_ins_ini(l1, x);
    }
    for(int j = 0; j < n2; j++) {
        scanf("%d", &x);
        l2 = TLDE_ins_ini(l2, x);
    }
    printf("A lista 1 eh: ");
    TLDE_imprime(l1);
    printf("\n");
    printf("A lista 2 eh: ");
    TLDE_imprime(l2);
    printf("\n");
    l1 = junta_listas(l1, l2);
    printf("E a juncao das duas eh: ");
    TLDE_imprime(l1);
    TLDE_libera(l1);
    return 0;
}