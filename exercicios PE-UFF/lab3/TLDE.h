#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
    int info;
    struct lde *ant, *prox;
}TLDE;

TLDE* TLSE_ins_ini(TLDE *l, int elem);
void TLSE_imprime(TLDE *l);
void TLSE_libera(TLDE *l);
TLDE* TLSE_retira(TLDE *l, int elem);
TLDE* TLSE_busca(TLDE *l, int elem);
TLDE *TLSE_ins_ord(TLDE *l, int x);
void TLSE_imp_rec(TLDE *l);
void TLSE_imp_rec_rev(TLDE *l);
void TLSE_lib_rec(TLDE *l);
TLDE* TLSE_busca_rec(TLDE *l, int elem);
TLDE* TLSE_retira_rec(TLDE *l, int elem);
TLDE* TLDE_ins_ord_rec(TLDE *l, int x);
TLDE *ior_aux(TLDE *l, int x, TLDE *ant);
void inverte(TLDE *l);