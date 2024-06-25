#include "TODAS.c"

TP *ret_mult_k1(TP *p, int k){
    TP *presp = TP_inicializa(), *paux = TP_inicializa();
    while(!TP_vazia(p)){
        int x = TP_pop(p);
        if(x % k != 0) TP_push(presp, x);
        TP_push(paux, x);
    }
    while(!TP_vazia(paux)) TP_push(p, TP_pop(paux));
    while(!TP_vazia(presp)) TP_push(paux, TP_pop(presp));
    TP_libera(presp);
    return paux;
}

int main(void){
    TP *p = TP_inicializa();
    int x, k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TP_push(p, x);        
    }while(1);
    TP_imprime(p);
    scanf("%d", &k);
    printf("\nchamo a funcao\n");
    TP *presp = ret_mult_k1(p, k);
    TP_imprime(presp);
    printf("\nconfirmando que p ta inalterada\n");
    TP_imprime(p);
    TP_libera(p); TP_libera(presp);
    return 0;
}
