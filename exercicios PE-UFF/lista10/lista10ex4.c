#include "TLC.c"

TLC *TLC_copia(TLC *l){
    TLC *resp = TLC_inicializa(), *p = l;
    resp = TLC_ins_mais_facil(resp, p->info);
    p = p->prox;
    while(p != l){
        resp = TLC_ins_mais_facil(resp, p->info);
        p = p->prox;
    }
    resp = resp->prox;
    inverte(resp);
    return resp;
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
    TLC *resp = TLC_copia(l);
    printf("\n");
    TLC_imprime(l);
    printf("\nCopia: ");
    TLC_imprime(resp);
    TLC_libera(l);
    TLC_libera(resp);
    return 0;
}