#include "TLC.c"

TLC *inverte(TLC *l){
    TLC *nova = TLC_inicializa(), *p = l;
    nova = TLC_ins_mais_facil(nova, p->info);
    p = p->prox;
    while(p != l){
        nova = TLC_ins_mais_facil(nova, p->info);
        p = p->prox;
    }
    nova = nova->prox;
    return nova;
}

int main(void){
    TLC *l = TLC_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLC_ins_mais_facil(l, x);
    }while(1);
    TLC_imprime(l);
    TLC *nova = inverte(l);
    printf("\n");
    TLC_imprime(nova);
    TLC_libera(l);
    TLC_libera(nova);
    return 0;
}