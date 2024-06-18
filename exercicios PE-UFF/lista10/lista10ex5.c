#include "TLC.c"

TLC *rto(TLC *l, int n){
    TLC *p = l, *resp = TLC_inicializa();
    if(p->info != n) resp = TLC_ins_mais_facil(resp, p->info);
    p = p->prox;
    while(p != l){
        if(p->info != n) resp = TLC_ins_mais_facil(resp, p->info);
        p = p->prox;
    }
    resp = resp->prox;
    inverte(resp);
    return resp;
}

int main(void){
    TLC *l = TLC_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLC_ins_mais_facil(l, x);
    }while(1);
    TLC_imprime(l);
    scanf("%d", &n);
    printf("\n");
    TLC *resp = rto(l, n);
    TLC_imprime(resp);
    TLC_libera(l);
    TLC_libera(resp);
    return 0;
}