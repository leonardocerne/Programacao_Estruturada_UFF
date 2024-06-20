#include <stdio.h>
#include <stdlib.h>

typedef struct pilha TP;
int TP_vazia(TP *p);
void TP_push(TP *p, int x);
int TP_pop(TP *p);
TP *TP_cria(void);
TP *TP_libera(TP *p);
void imprime(TP *p);
void ordena(TP *p);