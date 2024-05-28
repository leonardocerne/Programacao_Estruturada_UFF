#include <stdio.h>
#include "TLDE.c"

TLDE* i_p (TLDE *l){
    TLDE *nova = NULL, *p = l;
    while(p) {
        if(p->info % 2 != 0){
            nova = TLDE_ins_ini(nova, p->info);
            p = p->prox;
        }
        else p = p->prox;
    }
    p = l;
    while(p){
        if(p->info % 2 == 0){
            nova = TLDE_ins_ini(nova, p->info);
            p = p->prox;
        }
        else p = p->prox;
    }
    inverte(nova);
    return nova;
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
    TLDE *nova = i_p(l);
    printf("Aqui esta a lista nova: ");
    TLDE_imprime(nova);
    TLDE_libera(l);
    TLDE_libera(nova);
    return 0;
}