#include "TLC.c"

TLC *TLC_desloca(TLC *l, int tam){
    TLC *p = l;
    int aux = p->info;
    while(tam){
        p->info = p->prox->info;
        p = p->prox;
        tam--;
    }
    p->info = aux;
    return l;
}
void i_p(TLC *l){
    TLC *p = l;
    int tam = 1, tamaux;
    while(p->prox != l){
        tam++;
        p = p->prox;
    }
    tamaux = tam;
    p = l;
    while(tam){
        if(p->info % 2 == 0) p = TLC_desloca(p, tamaux - 1);
        else {
            p = p->prox;
            tamaux--;
        }
        tam--;
    }
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
    i_p(l);
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}