#include "TODAS.c"

TP *f2p(TF *f){
    TP *p = TP_inicializa();
    while(!TF_vazia(f)) TP_push(p, TF_retira(f));
    while(!TP_vazia(p)) TF_insere(f, TP_pop(p));
    while(!TF_vazia(f)) TP_push(p, TF_retira(f));
    return p;
}

int main(void){
    TF *f = TF_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TF_insere(f, x);
    }while(1);
    TF_imprime(f);
    TP *p = f2p(f);
    printf("\n");
    TP_imprime(p);
    TP_libera(p);
    TF_libera(f);
    return 0;
}