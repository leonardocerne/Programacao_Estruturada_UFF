#include "TLSE.c"

void inad(TLSE *l, int n){
    if(!l) return;
    if(l->info == n){
        TLSE *aux = l->prox;
        for(int i = 0; i < n * 2; i++){
            TLSE *no = (TLSE*)malloc(sizeof(TLSE));
            no->info = n;
            l->prox = no;
            no->prox = aux;
            l = no;
        }
        inad(aux, n);
    }
    else inad(l->prox, n);
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