#include <stdio.h>
#include "TLDE.c"

void i_p (TLDE *l){
    TLDE *p = l, *ult, *aux;
    int pares = 0, imp = 0;
    while(p){
        if(p->info % 2 == 0) pares++;
        ult = p;
        p = p->prox;
    }
    p = l;
    while(p) {
        if((p->info % 2 == 0) && (pares > 0)) {
            TLDE *no = TLDE_ins_ini(NULL, p->info);
            no->ant = ult;
            ult->prox = no;
            if(p->ant){
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
            }
            else{
                p->prox->ant = NULL;
            }
            aux = p;
            p = p->prox;
            free(aux);
            ult = no;
            pares--;
        }
        else{
            if((imp == 0) && (pares > 0)) l = p;
            p = p->prox;
            imp++;
        }
    }
}

int main(void) {
    int n, x;
    printf("Insira quantos elementos voce quer na lista: ");
    scanf("%d", &n);
    TLDE *l = TLDE_inicializa();
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        l = TLDE_ins_ini(l, x);
    }
    printf("Aqui esta a lista original: ");
    TLDE_imprime(l);
    printf("\n");
    i_p(l);
    printf("Aqui esta a lista alterada: ");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}