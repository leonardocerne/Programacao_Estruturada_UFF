#include <stdio.h>
#include "TLSE.c"

TLSE* junta_listas (TLSE* l1, TLSE* l2){
    TLSE *p = l1, *ult;
    while(p){
        ult = p;
        p = p->prox;
    }
    ult->prox = l2;
    return l1;
}
int main(void) {
    int n1, n2, x;
    printf("Insira quantos elementos voce quer na lista 1 e 2: ");
    scanf("%d%d", &n1, &n2);
    TLSE *l1 = TLSE_inicializa();
    TLSE *l2 = TLSE_inicializa();
    for(int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = TLSE_insere(l1, x);
    }
    for(int j = 0; j < n2; j++) {
        scanf("%d", &x);
        l2 = TLSE_insere(l2, x);
    }
    printf("A lista 1 eh: ");
    TLSE_imprime(l1);
    printf("\n");
    printf("A lista 2 eh: ");
    TLSE_imprime(l2);
    printf("\n");
    l1 = junta_listas(l1, l2);
    printf("E a juncao das duas eh: ");
    TLSE_imprime(l1);
    TLSE_libera(l1);
    return 0;
}