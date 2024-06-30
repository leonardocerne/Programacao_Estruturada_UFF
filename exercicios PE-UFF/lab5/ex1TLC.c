#include "TLC.c"

void misc(TLC *l, int x){
    TLC *p = l, *q;
    if(p->info == x){
        TLC *no = (TLC*)malloc(sizeof(TLC));
        if(x % 2 == 0){
            q = p->prox;
            no->info = x;
            p->info = x - 1;
            p->prox = no;
            no->prox = q;
            p = q;
        }
        else{
            q = p->prox;
            no->info = x + 1;
            p->prox = no;
            no->prox = q;
            p = q;
        }
    }
    else p = p->prox;
    while(p != l){
        if(p->info == x){
            TLC *no = (TLC*)malloc(sizeof(TLC));
            if(x % 2 == 0){
                q = p->prox;
                no->info = x;
                p->info = x - 1;
                p->prox = no;
                no->prox = q;
                p = q;
            }
            else{
                q = p->prox;
                no->info = x + 1;
                p->prox = no;
                no->prox = q;
                p = q;
            }
        }
        else p = p->prox;
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
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}