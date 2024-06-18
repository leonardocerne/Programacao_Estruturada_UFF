#include "TLC.c"

TLC *ordena(TLC *l){
    TLC *resp = TLC_inicializa(), *p = l, *tmp;
    int tam = 1, tamaux, menor = 1000, tamaux2;
    while(p->prox != l){
        tam++;
        p = p->prox;
    }
    p = l;
    tamaux = tam;
    tamaux2 = tam;
    while(tam){
        while(tamaux){
            if(p->info < menor){
                menor = p->info;
                tmp = p;
            }
            p = p->prox;
            tamaux--;
        }
        resp = TLC_ins_mais_facil(resp, menor);
        tmp->info = 1000;
        menor = 1000;
        p = l;
        tam--;
        tamaux = tamaux2;
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
    TLC *resp = ordena(l);
    TLC_imprime(resp);
    TLC_libera(l);
    TLC_libera(resp);
    return 0;
}