#include "TLC.c"

int contrario(TLC *l1, TLC *l2){
    TLC *p1 = l1, *p2 = l2;
    int tam1 = 1, tam2 = 1, fim2;
    while(p1->prox != l1) {
        tam1++;
        p1 = p1->prox;
    }
    while(p2->prox != l2){
        tam2++;
        p2 = p2->prox;
    }
    fim2 = tam2 - 1;
    p1 = l1; p2 = l2;
    if(tam1 != tam2) return 0;
    while(tam1){
        for(int i = 0; i < fim2; i++) p2 = p2->prox;
        if(p1->info != p2->info) return 0;
        fim2--;
        tam1--;
        p1 = p1->prox;
        p2 = l2;
    }
    return 1;
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
    int resp = contrario(l1, l2);
    TLC_imprime(l1);
    printf("\n");
    TLC_imprime(l2);
    printf("\n");
    if(resp == 1) printf("As listas sao inversas.");
    else printf("As listas nao sao inversas.");
    TLC_libera(l1); TLC_libera(l2);
    return 0;
}