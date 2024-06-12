#include "TLSE.c"

void troca (TLSE *l, int N1, int N2){
    TLSE *pn1 = l, *pn2 = l;
    int tmp;
    while((pn1) && (pn2)){
        if(pn1->info == N1){
            while((pn2) && (pn2->info != N2)) pn2 = pn2->prox;
            tmp = pn1->info;
            pn1->info = pn2->info;
            pn2->info = tmp;
            pn1->info *= -1;
            pn2->info *= -1;
            pn2 = pn1;
        }
        if(pn2->info == N2){
            while((pn1) && (pn1->info != N1)) pn1 = pn1->prox;
            tmp = pn1->info;
            pn1->info = pn2->info;
            pn2->info = tmp;
            pn1->info *= -1;
            pn2->info *= -1;
            pn1 = pn2;
        }
        else{
            pn1 = pn1->prox;
            pn2 = pn2->prox;
        }
    }
    pn1 = l;
    while(pn1){
        if(pn1->info < 0) pn1->info *= -1;
        pn1 = pn1->prox;
    }
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x, n1, n2;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d%d", &n1, &n2);
    troca(l, n1, n2);
    TLSE_imprime(l);
    printf("\n");
    TLSE_libera(l);  
    return 0;
}