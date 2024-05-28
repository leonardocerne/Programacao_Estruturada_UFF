#include <stdio.h>
#include "TLDE.c"

TLDE* rto (TLDE* l, int elem){
    TLDE *p, *aux, *prim = l;
    while((prim) && (prim->info == elem)){
        aux = prim;
        prim = prim->prox;
        free(aux);
    }
    p = prim;
    while(p) {
        if(p->info == elem) {
            if((p->ant) && (p->prox)){
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                aux = p;
                p = p->prox;
                free(aux);
            }
            else if(p->prox){
                p->prox->ant = NULL;
                aux = p;
                p = p->prox;
                free(aux);
            }
            else if(p->ant){
                p->ant->prox = NULL;
                aux = p;
                p = p->prox;
                free(aux);
            }
            else if((!p->ant) && (!p->prox)){
                free(p);
                prim = NULL;
            }
        }
        else p = p->prox;
    }
    return prim;
}

int main(void) {
    int n, x, elem;
    printf("Quantos elementos voce quer na lista: ");
    scanf("%d", &n);
    TLDE *l = TLDE_inicializa();
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }   
    printf("Insira o elemento que voce quer tirar: ");
    scanf("%d", &elem);
    printf("Aqui esta sua lista original: ");
    TLDE_imprime(l);
    printf("\n");
    l = rto(l, elem);
    if(l != NULL){
        printf("Aqui esta a lista depois de retirar as ocorrencias do elemento citado: ");
        TLDE_imprime(l);
        TLDE_libera(l);
    }
    else printf("A lista nao existe mais");
    return 0;
}