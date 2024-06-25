#include "TLSE.c"

TLSE *ret_mult_k4(TLSE *l, int k){
    if(!l) return l;
    if(l->info % k == 0){
        TLSE *t = l;
        l = l->prox;
        free(t);
        l = ret_mult_k4(l, k);
    }
    else l->prox = ret_mult_k4(l->prox, k);
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
    l = ret_mult_k4(l, k);
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}