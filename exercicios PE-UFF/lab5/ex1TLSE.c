#include "TLSE.c"

void misc(TLSE *l, int x){
    TLSE *p = l, *ant = l, *q;
    while(p){
        if(p->info == x){
            TLSE *no = (TLSE*)malloc(sizeof(TLSE));
            if(x % 2 == 0){
                if(p == ant){
                    q = p->prox;
                    no->info = x;
                    p->info = x - 1;
                    p->prox = no;
                    no->prox = q;
                    ant = no;
                    p = q;
                }
                else{
                    no->info = x - 1;
                    ant->prox = no;
                    no->prox = p;
                    ant = p;
                    p = p->prox;
                }
            }
            else{
                no->info = x + 1;
                q = p->prox;
                p->prox = no;
                no->prox = q;
                ant = p;
                p = q;
            }
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
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