#include <stdio.h>
#include "TLSE.c"

void inverte(TLSE *l) {
    TLSE *p = l;
    int tam = 0, tmp;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    int fim = tam - 1;
    for(int i = 0; i < tam / 2; i++) {
        TLSE *q = p;
        for(int j = 0; j < fim; j++) {
            q = q->prox;
        }
        tmp = q->info;
        q->info = p->info;
        p->info = tmp;
        p = p->prox;
        fim -= 2;
    }
    return;
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
    inverte(l);
    printf("A lista invertida e: ");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
    }