#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    float cr;
    int mat;
    char nome[31];
} TALUNO;

TALUNO **TA_aloca(int n);
void TA_leit(TALUNO **vet, int n);
void TA_imp(TALUNO **vet, int n);
void TA_libera(TALUNO **vet, int n);
void ordena_TA(TALUNO **vet, int n);
int TA_comp(const void *al, const void *al2);