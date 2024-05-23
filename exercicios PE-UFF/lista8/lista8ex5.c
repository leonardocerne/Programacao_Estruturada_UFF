#include <stdio.h>
#include "TLSE.c"

TLSE* rto (TLSE* l, int elem){
    TLSE *p = l, *q = NULL, *aux, *prim;
    while(p) {
        if(p->info == elem){
            aux = p;
            p = p->prox;
            free(aux);
        }
        else{
            q = p;
            break;
        }
    }
    p = p->prox;
    prim = q;
    while(p) {
        if(p->info == elem){
            aux = p;
            p = p->prox;
            if(aux->prox == NULL) {
                q->prox = NULL;
                free(aux);
            }
            else free(aux);
        }
        else{
            q->prox = p;
            q = p;
            p = p->prox;
        }
    }    
    return prim;
}

int main(void) {
    int n, x, elem;
    printf("Quantos elementos voce quer na lista: ");
    scanf("%d", &n);
    TLSE *l = TLSE_inicializa();
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLSE_insere(l, x);
    }   
    printf("Insira o elemento que voce quer tirar: ");
    scanf("%d", &elem);
    printf("Aqui esta sua lista original: ");
    TLSE_imprime(l);
    printf("\n");
    l = rto(l, elem);
    printf("Aqui esta a lista depois de retirar as ocorrencias do elemento citado: ");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}