#include <stdio.h>
#include <stdlib.h>
#include "vet2.c"
#include "mat.c"

int main(void) {
    int **mat = aloca(9, 9);
    mat_leit(mat, 9, 9);
    int linha[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *coluna = (int*)malloc(sizeof(int) * 9);
    int resp = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            coluna[j] = mat[j][i];
        }
        qsort(coluna, 9, sizeof(int), cmp_int);
        int col = 0;
        for (int k = 0; k < 9; k++)
            if (coluna[k] == linha[k]) col++;
        if (col == 9) resp++;
    }
    free(coluna);
    printf("%d", resp);
    return 0;
}