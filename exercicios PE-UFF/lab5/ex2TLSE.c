#include "TLSE.c"

void cross(TLSE *l1, TLSE *l2, int n){
    TLSE *p1 = l1, *p2 = l2, *tmp;
    while((p1) && (p2)){
        while((p1) && (p1->info != n)) p1 = p1->prox;
        while((p2) && (p2->info != n)) p2 = p2->prox;
        if((p1) && (p2) && (p1->info == n) && (p2->info == n)){
            tmp = p1->prox;
            p1->prox = p2->prox;
            p2->prox = tmp;
            p1 = p1->prox;
            p2 = p2->prox;
        }
    }
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