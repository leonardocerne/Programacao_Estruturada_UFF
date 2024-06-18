#include "TLC.c"

int igual(TLC *l1, TLC *l2){
    TLC *p1 = l1, *p2 = l2;
    if(p1->info != p2->info) return 0;
    p1 = p1->prox; p2 = p2->prox;
    while((p1 != l1) && (p2 != l2)){
        if(p1->info != p2->info) return 0;
        p1 = p1->prox; p2 = p2->prox;
    }
    if((p1 == l1) && (p2 == l2)) return 1;
    return 0;
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
    int resp = igual(l1, l2);
    TLC_imprime(l1);
    printf("\n");
    TLC_imprime(l2);
    if(resp == 1) printf("As listas sao iguais.");
    else printf("As listas sao diferentes.");
    TLC_libera(l1); TLC_libera(l2);
    return 0;
}