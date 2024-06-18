#include "TLC.c"

TLC *TLC_desloca(TLC *l, int n){
    TLC *p = l;
    if(n % 2 == 0) p = p->prox;
    else{
        while(p->prox != l) p = p->prox;
    }
    return p;
}

int main(void){
    TLC *l = TLC_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLC_ins_mais_facil(l, x);
    }while(1);
    scanf("%d", &n);
    TLC_imprime(l);
    l = TLC_desloca(l, n);
    printf("\n");
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}