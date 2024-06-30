#include "TLDE.c"

void misc(TLDE *l, int x){
    TLDE *p = l, *q;
    while(p){
        if(p->info == x){
            TLDE *no = (TLDE*)malloc(sizeof(TLDE));
            if(x % 2 == 0){
                if(p->ant){
                    q = p->ant;
                    no->info = x - 1;
                    q->prox = no;
                    no->ant = q;
                    no->prox = p;
                    p->ant = no;
                    p = p->prox;
                }
                else{
                    q = p->prox;
                    no->info = x;
                    p->info = x - 1;
                    p->prox = no;
                    no->prox = q;
                    no->ant = p;
                    q->ant = no;
                    p = q;
                }
            }
            else{
                q = p->prox;
                no->info = x + 1;
                p->prox = no;
                no->ant = p;
                no->prox = q;
                q->ant = no;
                p = q;
            }
        }
        else p = p->prox;
    }
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