#include "TLDE.c"

void inad(TLDE *l, int n){
    if(!l) return;
    if(l->info == n){
        TLDE *aux = l->prox;
        for(int i = 0; i < n * 2; i++){
            TLDE *no = (TLDE*)malloc(sizeof(TLDE));
            no->info = n;
            l->prox = no;
            no->ant = l;
            no->prox = aux;
            aux->ant = no;
            l = no;
        }
        inad(aux, n);
    }
    else inad(l->prox, n);
}

int main(void){
    TLDE *l = TLDE_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_ins_ini(l, x);
    }while(1);
    TLDE_imprime(l);
    printf("\n");
    scanf("%d", &n);
    inad(l, n);
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}