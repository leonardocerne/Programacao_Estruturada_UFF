#include "TLC.c"

TLC *i_p(TLC *l){
    TLC *p = l, *resp = TLC_inicializa();
    if(p->info % 2 != 0) resp = TLC_ins_mais_facil(resp, p->info);
    p = p->prox;
    while(p != l){
        if(p->info % 2 != 0) resp = TLC_ins_mais_facil(resp, p->info);
        p = p->prox;
    }
    p = l;
    if(p->info % 2 == 0) resp = TLC_ins_mais_facil(resp, p->info);
    p = p->prox;
    while(p != l){
        if(p->info % 2 == 0) resp = TLC_ins_mais_facil(resp, p->info);
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
    printf("\n");
    TLC *resp = i_p(l);
    TLC_imprime(resp);
    TLC_libera(l);
    TLC_libera(resp);
    return 0;
}