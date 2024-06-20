#include "TODAS.c"

TF *inv_fila(TF *f){
    TF *fresp = TF_inicializa();
    TP *p = TP_inicializa();
    while(!TF_vazia(f)) TP_push(p, TF_retira(f));
    while(!TP_vazia(p)) TF_insere(fresp, TP_pop(p));
    return fresp; 
}

int main(void){
    TF *f = TF_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TF_insere(f, x);
    }while(1);
    TF_imprime(f);
    TF *f2 = inv_fila(f);
    printf("\n");
    TF_imprime(f2);
    TF_libera(f);
    TF_libera(f2);
    return 0;
}