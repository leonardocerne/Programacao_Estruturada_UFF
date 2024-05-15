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
        TLSE_lib_rec(l->prox);
        free(l);
    }
}
int main(void){        
        //na main
    TLSE *l = NULL;     // ou
    TLSE *l1 = TLSE_inicializa(); 
    l = TLSE_ins_ini(l, 6); // insere no começo
    l = TLSE_ins_ini(l, 6);
    l = TLSE_ins_ini(l, 6); // a lista até agora tá (0, 2, 1)
    TLSE_imprime(l);
    printf("\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_imp_rec_rev(l);
    TLSE_libera_rec(l);
    free(l1);
    //TLSE_libera(l);
    // l = NULL; se não usar variavel tmp
    return 0;
}