#include "TLSE.c"

void inad(TLSE *l, int n){
    TLSE *p = l, *aux;
    while(p){
        if(p->info == n){
            aux = p->prox;
            for(int i = 0; i < n * 2; i++){
                TLSE *no = (TLSE*)malloc(sizeof(TLSE));
                no->info = n;
                p->prox = no;
                no->prox = aux;
                p = no;
            }
            p = aux;
        }
        else p = p->prox;
    }
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d", &n);
    inad(l, n);
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}