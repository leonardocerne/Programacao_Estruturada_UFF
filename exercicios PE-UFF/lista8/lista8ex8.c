#include <stdio.h>
#include "TLSE.c"

int igual(TLSE *l1, TLSE *l2){
    TLSE *p, *q;
    while((p) || (q)) {
        if (((p) && (!q)) || ((!p) && (q))) return 0;
        if(p->info == q->info) {
            p = p->prox;
            q = q->prox;
        }
        else return 0;
    }
    return 1;
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
    int resp = igual(l1, l2);
    if(resp == 1) printf("As listas sao iguais");
    else printf("As listas sao diferentes");
    return 0;
}