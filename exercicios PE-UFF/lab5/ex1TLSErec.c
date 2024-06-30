#include "TLSE.c"

void misc(TLSE *l, int x){
    if(!l) return l;
    if(l->info == x){
        TLSE *no = (TLSE*)malloc(sizeof(TLSE));
        if(x % 2 == 0){
            TLSE *q = l->prox;
            no->info = x;
            l->info = x - 1;
            l->prox = no;
            no->prox = q;
            misc(q, x);
        }
        else{
            TLSE *q = l->prox;
            no->info = x + 1;
            l->prox = no;
            no->prox = q;
            misc(q, x);
        }
    }
    else misc(l->prox, x);
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}