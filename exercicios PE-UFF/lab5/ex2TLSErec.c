#include "TLSE.c"

void cross(TLSE *l1, TLSE *l2, int n){
    if((!l1) || (!l2)) return;
    TLSE *tmp;
    while((l1) && (l1->info != n)) l1 = l1->prox;
    while((l2) && (l2->info != n)) l2 = l2->prox;
    if((l1) && (l2) && (l1->info == n) && (l2->info == n)){
        tmp = l1->prox;
        l1->prox = l2->prox;
        l2->prox = tmp;
        cross(l1->prox, l2->prox, n);
    }
    else cross(l1, l2, n);
}
int main(void){
    TLSE *l1 = TLSE_inicializa(), *l2 = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLSE_insere(l1, x);
    }while(1);
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLSE_insere(l2, x);
    }while(1);
    printf("Lista 1: ");
    TLSE_imprime(l1);
    printf("\nLista 2: ");
    TLSE_imprime(l2);
    printf("\nInsira o n:");
    scanf("%d", &x);
    cross(l1, l2, x);
    printf("\nLista alterada 1:");
    TLSE_imprime(l1);
    printf("\nLista alterada 2:");
    TLSE_imprime(l2);
    TLSE_libera(l1);
    TLSE_libera(l2);
    return 0;
}