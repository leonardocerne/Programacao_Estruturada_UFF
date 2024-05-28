#include <stdio.h>
#include "TLDE.c"

TLDE *ordena (TLDE* l){
    TLDE *p = l, *nova = NULL, *prim, *q, *ant;
    int x;
    nova = TLDE_ins_ini(nova, p->info);
    p = p->prox;
    q = nova;
    prim = q;
    while(p){
        x = p->info;
        if(x < q->info){
            q = TLDE_ins_ini(q, x);
            prim = q;
        }
        else{
            while((q) && (q->info <= x)) {
                ant = q;
                q = q->prox;
            }
            TLDE *novo = TLDE_ins_ini(NULL, x);
            ant->prox = novo;
            novo->ant = ant;
            novo->prox = q;
            if(q) q->ant = novo;
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
    TLDE *l = TLDE_inicializa();
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }
    printf("Aqui esta a lista original: ");
    TLDE_imprime(l);
    printf("\n");
    TLDE *nova = ordena(l);
    printf("Aqui esta a lista ordenada: ");
    TLDE_imprime(nova);
    TLDE_libera(l);
    TLDE_libera(nova);
    return 0;
}