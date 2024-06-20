#include "TODAS.c"

TF *p2f(TP *p){
    TF *f = TF_inicializa();
    while(!TP_vazia(p)) TF_insere(f, TP_pop(p));
    return f;
}
int main(void){
    TP *p = TP_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        TP_push(p, x);
    }while(1);
    TP_imprime(p);
    TF *f = p2f(p);
    printf("\n");
    TF_imprime(f);
    TP_libera(p);
    TF_libera(f);
    return 0;
}