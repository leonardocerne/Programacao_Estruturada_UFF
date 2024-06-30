#include <stdio.h>
#include <stdlib.h>

typedef struct lc{
    int info;
    struct lc *prox;
}TLC;
TLC *TLC_inicializa();
void TLC_imprime(TLC *l);
void aux(TLC *atual, TLC *l);
void TLC_imp_rec(TLC *l);
void TLC_libera(TLC *l);
TLC *TLC_busca(TLC *l, int x);
TLC *TLC_ins_mais_facil(TLC *l, int x);
TLC *TLC_ins_ult(TLC *l, int x);
TLC *retira(TLC *l, int x);
void inverte(TLC *l);