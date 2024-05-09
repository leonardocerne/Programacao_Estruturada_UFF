#include "TALUNO.h"

TALUNO **TA_aloca(int n){
    TALUNO **novo = (TALUNO **)malloc(sizeof(TALUNO *) * n);
    int i;
    for(i = 0; i < n; i++) novo[i] = NULL;
    return novo;
}
void TA_leit(TALUNO **vet, int n) {
    int i;
    for(i = 0; i < n; i++) {
        vet[i] = (TALUNO *)malloc(sizeof(TALUNO));
        printf("Digite mat, cr e nome...\n");
        scanf("%d", &vet[i]->mat);                                  // função que lê cada aluno
        scanf("%f", &vet[i]->cr);
        scanf(" %30[^\n]", vet[i]->nome);
    }
}
void TA_imp(TALUNO **vet, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("nome: %s\tmatricula: %d\t cr: %.2f\n", vet[i]-> nome, vet[i]-> mat, vet[i]->cr);
    }
}

void TA_libera(TALUNO **vet, int n){
    int i;
    for(i = 0; i < n; i++) free(vet[i]);
    free(vet);
}

int TA_comp(const void *al, const void *al2){
    TALUNO **x1 = (TALUNO **)al, **x2 = (TALUNO **)al2;
    TALUNO *pal = *x1, *pal2 = *x2;
    if(pal->cr >pal2->cr) return -1;
    if(pal->cr <pal2->cr) return 1;
    int resp = strcmp(pal->nome, pal2->nome);
    if(resp < 0) return -1;
    if(resp > 0) return 1;
    if(pal->mat < pal2->mat) return -1;
    return 1;
}
void ordena_TA(TALUNO **vet, int n){
    qsort(vet, n, sizeof(TALUNO *), TA_comp);
}