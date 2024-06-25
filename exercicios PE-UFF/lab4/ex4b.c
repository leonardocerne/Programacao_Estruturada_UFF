#include "TODAS.c"

TF *ret_mult_k2(TF *f, int k){
    TF *fresp = TF_inicializa(), *faux = TF_inicializa();
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        if(x % k != 0) TF_insere(fresp, x);
        TF_insere(faux, x);
    }
    while(!TF_vazia(faux)) TF_insere(f, TF_retira(faux));
    return fresp;
}

int main(void){
    TF *f = TF_inicializa();
    int x, k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TF_insere(f, x);        
    }while(1);
    TF_imprime(f);
    scanf("%d", &k);
    printf("\nchamo a funcao\n");
    TF *fresp = ret_mult_k2(f, k);
    TF_imprime(fresp);
    printf("\nconfirmando que f ta inalterada\n");
    TF_imprime(f);
    TF_libera(f); TF_libera(fresp);
    return 0;
}