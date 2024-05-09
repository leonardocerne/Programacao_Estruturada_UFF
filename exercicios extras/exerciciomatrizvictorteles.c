#include <stdio.h>
#include <stdlib.h>
#include "mat.c"
#include "vet2.c"

void ordenamat(int **mat, int lin, int col) {
    int *vet = (int*)malloc(sizeof(int) * (lin * col));
    int x = 0, y = 0;
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++) vet[x + j] = mat[i][j];
        x += col;
    }
    qsort(vet, (lin*col), sizeof(int), cmp_int);
    for (int k = 0; k < lin; k++) {
        for (int l = 0; l < col; l++) mat[k][l] = vet[y + l];
        y += col;
    }
    free(vet);
}
int main(void) {
    int lin, col;
    scanf("%d%d", &lin, &col);
    int **mat = (int**)malloc(sizeof(int*) *  lin);
    for(int i = 0; i < lin; i++) mat[i] = (int*)malloc(sizeof(int) * col);
    mat_leit(mat, lin, col);
    ordenamat(mat, lin, col);
    mat_imp(mat, lin, col);
    libera(mat, lin);
    return 0;
}