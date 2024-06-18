#include "TLC.c"

void inverte(TLC *l){
    TLC *p = l;
    int tam = 0, fim, tmp;
    do{
        tam++;
        p = p->prox;
    }while(p != l);
    p = l;
    fim = tam - 1;
    for(int i = 0; i < tam / 2; i++) {
        TLC *q = p;
        for(int j = 0; j < fim; j++) {
            q = q->prox;
        }
        tmp = q->info;
        q->info = p->info;
        p->info = tmp;
        p = p->prox;
        fim -= 2;
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
    inverte(l);
    printf("\n");
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}