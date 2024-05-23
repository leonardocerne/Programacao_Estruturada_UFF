#include <stdio.h>
#include "TLSE.c"

void i_p (TLSE *l){
    int pares = 0, c = 0, ci = 0;
    TLSE *p = l, *ant = NULL, *ult, *aux;
    while(p) {
        if(p->info % 2 == 0) pares++;
        p = p->prox;
    }
    p = l;
    while(p) {
        ult = p;
        p = p->prox;
    }
    p = l;
    while(p) {
        if((p->info % 2 == 0) && (c < pares)) {
            TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
            novo->info = p->info;
            novo->prox = NULL;
            ult->prox = novo;
            ult = ult->prox;
            c++;
            aux = p;
            p = p->prox;
            free(aux);
            if(ant) ant->prox = p;
        }
        else {
            if(ci == 0) l = p;
            ant = p;
            p = p->prox;
            ci++;
        }
    }
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
    i_p(l);
    printf("Aqui esta a lista alterada: ");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}