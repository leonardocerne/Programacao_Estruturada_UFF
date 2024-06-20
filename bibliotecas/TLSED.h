#include <stdio.h>
#include <stdlib.h>

typedef struct lse{
    int info;
    struct lse *prox;
}TLSE;

typedef struct lsed{
    TLSE *prim;
}TLSED;

TLSED *TLSED_inicializa(void);
TLSE *TLSED_busca(TLSED *l, int x);
void TLSED_ins_ini(TLSED *l,int x);
void TLSED_retira(TLSED *l, int x);
void TLSED_imprime(TLSED *l);
void TLSED_libera(TLSED *l);