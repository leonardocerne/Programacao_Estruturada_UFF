#include <stdio.h>
#include "vet.c"
#include <stdlib.h>

int cmp_int(const void *x, const void *y){
    int *px = (int *)x, *py = (int *)y;
    if ((*px) < (*py)) return -1;
    if ((*px) > (*py)) return 1;
    return 0;
}

int cmp_int_dec(const void *x, const void *y){
    int *px = (int *)x, *py = (int *)y;
    if ((*px) < (*py)) return 1;
    if ((*px) > (*py)) return -1;
    return 0;
}

int* copia_ordena(int *vet, int n) {      // precisa do * pq retorna um vetor
    int* resp = (int *)malloc(n * sizeof(int));
    if(resp == NULL) exit(1);
    int i;
    for(i = 0; i < n; i++) resp[i] = vet [i];
    qsort(resp, n, sizeof(int), cmp_int);
    return resp;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int vet[n];
    vet_leit(vet, n);
    vet_imp(vet, n);
    printf("\n");
    int *resp = copia_ordena(vet, n);
    int i;
    for(i = 0; i < n; i++) printf("%d ", resp[i]);
    printf("\n");
    free(resp);
    return 0;
}