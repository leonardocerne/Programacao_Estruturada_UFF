#include <stdio.h>
#include "TLDE.c"

void inverte(TLDE *l) {
    TLDE *p = l;
    int tam = 0, tmp;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    int fim = tam - 1;
    for(int i = 0; i < tam / 2; i++) {
        TLDE *q = p;
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
    inverte(l);
    printf("A lista invertida e: ");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
    }