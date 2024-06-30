#include "TLC.c"

void miscaux(TLC *l, TLC *p, int x){
    if(p == l) return;
    TLC *q;
    if(p->info == x){
        TLC *no = (TLC*)malloc(sizeof(TLC));
        if(x % 2 == 0){
            no->info = x;
            p->info = x - 1;
            TLC *q = p->prox;
            p->prox = no;
            no->prox = q;
            miscaux(l, q, x);
        }
        else{
            no->info = x + 1;
            TLC *q = p->prox;
            p->prox = no;
            no->prox = q;
            miscaux(l, q, x);
        }
    }
    else miscaux(l, p->prox, x);
}
void misc(TLC *l, int x){
    TLC *p = l, *q;
    if(p->info == x){
        TLC *no = (TLC*)malloc(sizeof(TLC));
        if(x % 2 == 0){
            no->info = x;
            p->info = x - 1;
            q = p->prox;
            p->prox = no;
            no->prox = q;
            p = q;
        }
        else{
            no->info = x + 1;
            q = p->prox;
            p->prox = no;
            no->prox = q;
            p = q;
        }
    }
    else p = p->prox;
    miscaux(l, p, x);
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