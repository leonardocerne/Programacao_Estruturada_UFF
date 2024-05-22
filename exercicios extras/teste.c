#include <stdio.h>
#include <stdlib.h>

typedef struct lse{
    int info;
    struct lse *prox;
}TLSE;

TLSE *TLSE_inicializa(void) {
    return NULL;
}
TLSE *TLSE_ins_ini(TLSE *l, int x) {
    TLSE *novo = (TLSE *)malloc(sizeof(TLSE));          // cria um tipo TLSE, atualiza as infos dele, e retorna o ponteiro pra ele.
    novo -> info = x;
    novo -> prox = l;
    return novo;
}
void TLSE_imprime(TLSE *l){
    TLSE *p = l;
    while(p) {
        printf("%d\n", p->info);        // vai do primeiro até o ultimo elemento apontando sempre pro próximo, para quando chega em NULL
        p = p->prox;
    }
}
void TLSE_imp_rec(TLSE *l){
    if(l) {
        printf("%d\n", l -> info);      // imprime de forma recursiva 
        TLSE_imp_rec(l -> prox);
    }
}
void TLSE_imp_rec_rev(TLSE *l) {
    if(l) {
        TLSE_imp_rec_rev(l->prox);
        printf("%d\n", l->info);        // imprime de forma recursiva ao contrário
    }
}
void TLSE_libera(TLSE *l) {
    TLSE *p = l, *t;
    while(p) {
        t = p;
        p = p->prox;
        free(t);
    }
}
void TLSE_libera_rec(TLSE *l) {
    if(l) {
        TLSE_libera_rec(l->prox);
        free(l);
    }
}
void TLSE_imp_rev_it(TLSE *l) {
    TLSE *p = l, *laux = NULL;
    while(p) {
        laux = TLSE_ins_ini(laux, p->info);
        p = p->prox;
    }
    TLSE_imprime(laux);
    TLSE_libera(laux);
}
TLSE *TLSE_retira(TLSE *l, int x) {
    TLSE *ant = NULL, *p = l;
    while((p) && (p->info!=x)) {
        ant = p;
        p = p->prox;
    }
    if(!p) return l;
    if(!ant) l = l->prox;
    else ant->prox = p->prox;
    free(p);
    return l;
}
TLSE *TLSE_ret_rec(TLSE *l, int x) {
    if(!l) return l;
    if(l->info==x){
        TLSE *t = l;
        l = l->prox;
        free(t);
    }
    else
        l->prox = TLSE_ret_rec(l->prox, x);
    return l;
}
TLSE *TLSE_ins_ord(TLSE *l, int x) {
    TLSE *ant = NULL, *p = l;
    while((p) && (p->info==x)) {
        ant = p;
        p = p->prox;
    }
    if(!ant) return TLSE_ins_ini(l, x);
    TLSE *novo = TLSE_ins_ini(p, x);
    ant->prox = novo;
    return l;
}
int main(void){        
        //na main
    TLSE *l = NULL;     // ou
    TLSE *l1 = TLSE_inicializa(); 
    l = TLSE_ins_ini(l, 1); // insere no começo
    l = TLSE_ins_ini(l, 2);
    l = TLSE_ins_ini(l, 3);
    TLSE_imprime(l);
    printf("\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_imp_rec_rev(l);
    printf("\n");
    TLSE_imp_rev_it(l);
    printf("\n");
    l = TLSE_ret_rec(l, 3);
    printf("TESTE\n");
    TLSE_imp_rec(l);
    printf("TESTE\n");
    TLSE_libera_rec(l);
    free(l1);
    //TLSE_libera(l);
    // l = NULL; se não usar variavel tmp
    return 0;
}