#include <stdio.h>
#include "TLDE.c"

int Contrario (TLDE *l1, TLDE *l2){
    int tam1 = 0, tam2 = 0, x, fim;
    TLDE *p = l1, *q = l2;
    while(p) {
        tam1++;
        p = p->prox;
    }
    while(q) {
        tam2++;
        q = q->prox;
    }
    fim = tam2 -1;
    p = l1;
    if (tam1 == tam2) {
        while(p) {
            q = l2;
            for(int i = 0; i < fim; i++) q = q->prox;
            if(p->info != q->info) return 0;
            p = p->prox;
            fim--;
        }
        return 1;
    }
    return 0;
}

int main(void) {
    int n1, n2, x;
    printf("Insira quantos elementos voce quer na lista 1 e 2: ");
    scanf("%d%d", &n1, &n2);
    TLDE *l1 = TLDE_inicializa();
    TLDE *l2 = TLDE_inicializa();
    for(int i = 0; i < n1; i++) {
        scanf("%d", &x);
        l1 = TLDE_ins_ini(l1, x);
    }
    for(int j = 0; j < n2; j++) {
        scanf("%d", &x);
        l2 = TLDE_ins_ini(l2, x);
    }
    int resp = Contrario(l1, l2);
    if(resp == 1)printf("As listas sao a inversa uma da outra");
    else printf("Nao sao inversas uma da outra");
    TLDE_libera(l1);
    TLDE_libera(l2);
    return 0;
}