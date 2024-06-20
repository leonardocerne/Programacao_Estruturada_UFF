#include "TODAS.c"

void retira_pares(TP *p){
    TP *paux = TP_inicializa();
    while(!TP_vazia(p)) {
        int x = TP_pop(p);
        if(x % 2 != 0) TP_push(paux, x);
    }
    while(!TP_vazia(paux)) TP_push(p, TP_pop(paux));
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
    retira_pares(p);
    printf("\n");
    TP_imprime(p);
    TP_libera(p);
    return 0;
}