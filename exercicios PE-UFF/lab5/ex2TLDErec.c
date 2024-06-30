#include "TLDE.c"

void cross(TLDE *l1, TLDE *l2, int n){
    if((!l1) || (!l2)) return;
    while((l1) && (l1->info != n)) l1 = l1->prox;
    while((l2) && (l2->info != n)) l2 = l2->prox;
    if((l1) && (l2) && (l2->info == n) && (l1->info == n)){
        TLDE *tmp = l1->prox;
        l1->prox = l2->prox;
        l2->prox->ant = l1;
        l2->prox = tmp;
        tmp->ant = l2;
        cross(l1->prox, l2->prox, n);
    }
    else cross(l1, l2, n);
}

int main(void){
    TLDE *l1 = TLDE_inicializa(), *l2 = TLDE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLDE_ins_ini(l1, x);
    }while(1);
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLDE_ins_ini(l2, x);
    }while(1);
    printf("Lista 1: ");
    TLDE_imprime(l1);
    printf("\nLista 2: ");
    TLDE_imprime(l2);
    printf("\nInsira o n:");
    scanf("%d", &x);
    cross(l1, l2, x);
    printf("\nLista alterada 1:");
    TLDE_imprime(l1);
    printf("\nLista alterada 2:");
    TLDE_imprime(l2);
    TLDE_libera(l1);
    TLDE_libera(l2);
    return 0;
}