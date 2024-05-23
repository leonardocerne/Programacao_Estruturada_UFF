#include <stdio.h>
#include "TLSE.c"

TLSE *copia(TLSE *l) {
    TLSE *nova = NULL, *p = l;
    int x,tam = 0;
    while(p) {
        tam++;
        p = p->prox;
    }
    p = l;
    int fim = tam-1;
    for(int i = 0; i < tam; i++) {
        TLSE *q = p;
        for(int j = 0; j < fim; j++) q = q->prox;
        x = q->info;
        nova = TLSE_insere(nova, x);
        fim--;
    }
    return nova; 
}

int main(void) {
    int x, n;
    TLSE *l = TLSE_inicializa();
    printf("Insira quantos elementos a lista tera: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        l = TLSE_insere(l, x);
    }
    TLSE *nova = copia(l);    
    printf("Aqui esta sua lista original: ");
    TLSE_imprime(l);
    printf("\n");
    printf("Aqui esta sua copia: ");
    TLSE_imprime(nova);
    TLSE_libera(l);
    TLSE_libera(copia);
    return 0;
}