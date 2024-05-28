#include <stdio.h>
#include "TLDE.c"

TLDE *copia (TLDE *l){
    TLDE *nova = NULL, *p = l;
    int x,tam = 0;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    int fim = tam-1;
    for(int i = 0; i < tam; i++) {
        TLDE *q = p;
        for(int j = 0; j < fim; j++) q = q->prox;
        x = q->info;
        nova = TLDE_ins_ini(nova, x);
        fim--;
    }
    return nova;
}

int main(void) {
    int x, n;
    TLDE *l = TLDE_inicializa();
    printf("Insira quantos elementos a lista tera: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }
    TLDE *nova = copia(l);    
    printf("Aqui esta sua lista original: ");
    TLDE_imprime(l);
    printf("\n");
    printf("Aqui esta sua copia: ");
    TLDE_imprime(nova);
    TLDE_libera(l);
    TLDE_libera(copia);
    return 0;
}