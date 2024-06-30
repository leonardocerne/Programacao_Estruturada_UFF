#include "TLC.c"

void TLC_imprime_l1l2(TLC *l1, TLC *l2){
    if(l1){
        printf("%d ", l1->info);
        TLC *p = l1->prox;
        while((p != l1) && (p != l2)){
            printf("%d ", p->info);
            p = p->prox;
        }
    }
}

void TLC_liberal1l2(TLC *l1, TLC *l2){
    if(!l1) return;
    TLC *p = l1->prox, *t;
    while((p != l1) && (p != l2)){
        t = p;
        p = p->prox;
        free(t);
    }
}

void cross(TLC *l1, TLC *l2, int n){
    TLC *p1 = l1, *p2 = l2, *tmp;
    if((p1->info == n) || (p2->info == n)){
        if((p1->info == n) && (p2->info == n)){
            tmp = p1->prox;
            p1->prox = p2->prox;
            p2->prox = tmp;
            p1 = p1->prox;
            p2 = p2->prox;
        }
        else if (p1->info == n){
            p2 = p2->prox;
            while((p2 != l2) && (p2->info != n)) p2 = p2->prox;
            if((p1) && (p2) && (p1->info == n) && (p2->info == n)){
                tmp = p1->prox;
                p1->prox = p2->prox;
                p2->prox = tmp;
                p1 = p1->prox;
                p2 = p2->prox;
            }
        }
        else if (p2->info == n){
            p1 = p1->prox;
            while((p1 != l1) && (p1->info != n)) p1 = p1->prox;
            if((p1) && (p2) && (p1->info == n) && (p2->info == n)){
                tmp = p1->prox;
                p1->prox = p2->prox;
                p2->prox = tmp;
                p1 = p1->prox;
                p2 = p2->prox;
            }
        }
    }
    else {
        p1 = p1->prox;
        p2 = p2->prox;
    }
    while((p1 != l1) && (p2 != l2)){
        while((p1 != l1) && (p1->info != n)) {
            if(p1 == l2) break;
            p1 = p1->prox;
        }
        while((p2 != l2) && (p2->info != n)) {
            if(p2 == l1) break;
            p2 = p2->prox;
        }
        if((p1 == l2) || (p2 == l1)) break;
        if((p1 != l1) && (p2 != l2) && (p1->info == n) && (p2->info == n)){
            tmp = p1->prox;
            p1->prox = p2->prox;
            p2->prox = tmp;
            p1 = p1->prox;
            p2 = p2->prox;
        }
    }
}

int main(void){
    TLC *l1 = TLC_inicializa(), *l2 = TLC_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l1 = TLC_ins_mais_facil(l1, x);
    }while(1);
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l2 = TLC_ins_mais_facil(l2, x);
    }while(1);
    printf("Lista 1: ");
    TLC_imprime(l1);
    printf("\nLista 2: ");
    TLC_imprime(l2);
    printf("\nInsira o n:");
    scanf("%d", &x);
    cross(l1, l2, x);
    printf("\nLista alterada 1:");
    TLC_imprime_l1l2(l1, l2);
    printf("\nLista alterada 2:");
    TLC_imprime_l1l2(l2, l1);
    TLC_liberal1l2(l1, l2);
    TLC_liberal1l2(l2, l1);
    free(l1);
    free(l2);
    return 0;
}