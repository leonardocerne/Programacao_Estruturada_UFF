#include <stdio.h>
#include <stdlib.h>

typedef struct fila TF;
TF *TF_cria(void);
int TF_vazia(TF *f);
void TF_insere(TF *f, int x);
int TF_retira(TF *f);
void TF_libera(TF *f);
void imp(TF *f);