#include <stdio.h>
#include <stdlib.h>
#include "vet2.c"
#include "mat.c"

int** mult (int m1, int n1, int **mat1, int m2, int n2, int **mat2) {
    int **matresp = aloca(m1, n2);
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n2; j++) {
            matresp[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                matresp[i][j] += (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    return matresp;
}

int main(void) {
    int m1, n1, m2, n2;
    do {
        scanf("%d%d%d%d", &m1,&n1,&m2,&n2);
    } while(n1 != m2);
    int **mat1 = aloca(m1, n1);
    int **mat2 = aloca(m2, n2);
    mat_leit(mat1, m1, n1);
    mat_leit(mat2, m2, n2);
    int **matresp = mult(m1, n1, mat1, m2, n2, mat2);
    printf("Primeira matriz:\n");
    mat_imp(mat1, m1, n1);
    printf("\nSegunda matriz:\n");
    mat_imp(mat2, m2, n2);
    printf("\nMatriz resposta:\n");
    mat_imp(matresp, m1, n2);
    return 0;
}