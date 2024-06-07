#include <stdio.h>
#include "TLDE.c"

TLDE *desloca(TLDE *l) {
    TLDE *p = l;
    int aux = p->info;
    while(p->prox){
        p->info = p->prox->info;
        p = p->prox;
    }
    p->info = aux;
    return l;
}

void i_p (TLDE *l){
    TLDE *p = l;
    int tam = 0;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    while(tam) {
        if(p->info % 2 == 0) {
            p = desloca(p);
            tam--;
        }
        else{
            tam--;
            p = p->prox;
        }
    }
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
    i_p(l);
    printf("Aqui esta a lista alterada: ");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}