#include "TLDE.c"

void misc(TLDE *l, int x){
    if(!l) return l;
    if(l->info == x){
        TLDE *no = (TLDE*)malloc(sizeof(TLDE));
        if(x % 2 == 0){
            TLDE *q = l->prox;
            no->info = x;
            l->info = x - 1;
            l->prox = no;
            no->ant = l;
            no->prox = q;
            q->ant = no;
            misc(q, x);
        }
        else{
            TLDE *q = l->prox;
            no->info = x + 1;
            l->prox = no;
            no->ant = l;
            no->prox = q;
            q->ant = no;
            misc(q, x);
        }
    }
    else misc(l->prox, x);
}

int main(void){
    TLDE *l = TLDE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_ins_ini(l, x);
    }while(1);
    TLDE_imprime(l);
    printf("\n");
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}