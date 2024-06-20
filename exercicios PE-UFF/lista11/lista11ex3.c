#include "TODAS.c"

TF *Junta_Filas(TF *f1, TF *f2){
    TF *faux = TF_inicializa(), *fresp = TF_inicializa();
    while(!TF_vazia(f1)){
        int x = TF_retira(f1);
        TF_insere(fresp, x);
        TF_insere(faux, x);
    }
    while(!TF_vazia(faux)) TF_insere(f1, TF_retira(faux));
    while(!TF_vazia(f2)){
        int x = TF_retira(f2);
        TF_insere(fresp, x);
        TF_insere(faux, x);
    }
    while(!TF_vazia(faux)) TF_insere(f2, TF_retira(faux));
    TF_libera(faux);
    return fresp;
}
int main(void){
    TF *f1 = TF_inicializa(), *f2 = TF_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TF_insere(f1, x);
    }while(1);
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TF_insere(f2, x);
    }while(1);
    TF_imprime(f1);
    printf("\n");
    TF_imprime(f2);
    TF *f = Junta_Filas(f1, f2);
    printf("\nA conjunta:\n");
    TF_imprime(f);
    printf("\nAs originais:\n");
    TF_imprime(f1);
    printf("\n");
    TF_imprime(f2);
    TF_libera(f);
    TF_libera(f1);
    TF_libera(f2);
    return 0;
}