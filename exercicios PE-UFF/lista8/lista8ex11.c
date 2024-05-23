#include <stdio.h>
#include "TLSE.c"

TLSE * ordena (TLSE* l) {
    TLSE *p = l, *nova = NULL, *q, *ant,*ult, *prim;
    int x, tam = 0;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    nova = TLSE_insere(nova, p->info);
    q = nova;
    prim = q;
    p = p->prox;
    while(p) {
        x = p->info;
        if(x < q->info) {
            q = TLSE_insere(q, x);
            prim = q;
        }
        else{
            while((q) && (x >= q->info)) {
                ant = q;
                q = q->prox;
            }
            TLSE *tmp = (TLSE*)malloc(sizeof(TLSE));
            ant->prox = tmp;
            tmp->info = x;
            tmp->prox = q;
        }
        p = p->prox;
        q = prim;
    }
    return prim;
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
    TLSE *nova = ordena(l);
    printf("Aqui esta a lista ordenada: ");
    TLSE_imprime(nova);
    TLSE_libera(l);
    TLSE_libera(nova);
    return 0;
}