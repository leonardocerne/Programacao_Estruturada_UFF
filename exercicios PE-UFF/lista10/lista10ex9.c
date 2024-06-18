#include "TLC.c"

TLC *juntalistas(TLC *l1, TLC *l2){
    TLC *p1 = l1, *p2 = l2;
    while(p1->prox != l1) p1 = p1->prox;
    while(p2->prox != l2) p2 = p2->prox;
    p1->prox = l2;
    p2->prox = l1;
    p1 = l1;
    return l1;
}

int main(void){
    TLC *l1 = TLC_inicializa(), *l2 = TLC_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLC_ins_mais_facil(l1, x);
    }while(1);
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLC_ins_mais_facil(l2, x);
    }while(1);
    l1 = juntalistas(l1, l2);
    TLC_imprime(l1);
    TLC_libera(l1);
    return 0;
}