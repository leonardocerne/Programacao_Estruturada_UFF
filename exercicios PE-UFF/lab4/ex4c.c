#include "TLSE.c"

TLSE *ret_mult_k3(TLSE *l, int k){
    TLSE *p = l, *ant = l, *tmp;
    while(p){
        if(p->info % k == 0){
            if(p == ant){
                p = p->prox;
                tmp = ant;
                ant = p;
                free(tmp);
                l = ant;
            }
            else {
                ant->prox = p->prox;
                tmp = p;
                p = p->prox;
                free(tmp);
            }
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
    return l;
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x, k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d", &k);
    l = ret_mult_k3(l, k);
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}