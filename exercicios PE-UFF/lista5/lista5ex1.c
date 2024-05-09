#include <stdio.h>
#include <stdlib.h>
#include "mat.c"
#include "vet2.c"


int compcol(int **mat, int *linha) {
    int resp = 0; 
    int *coluna = (int*)malloc(sizeof(int) * 9);
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
    if (resp == 9) return 1;
    else return 5;
}

int complinha(int **mat, int *linha) {
    int resp = 0;
    int *coplinha = (int*)malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 9; k++) {
            coplinha[k] = mat[i][k];
        }
        qsort(coplinha, 9, sizeof(int), cmp_int);
        int lin = 0;
        for (int j = 0; j < 9; j++)
            if (coplinha[j] == linha[j]) lin++;
        if (lin == 9) resp++;
    }
    free(coplinha);
    if (resp == 9) return 1;
    return 0;
}

int compgrupo(int **mat, int *linha) {
    int resp = 0;
    int *grupo = (int*)malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0;j < 9; j+=3) {
            int x = 0;
            int gp = 0;
            for (int k = 0; k < 3; k++) {
                grupo[x] = mat[i + k][j];
                grupo[x + 1] = mat[i + k][j + 1];
                grupo[x + 2] = mat[i + k][j + 2];
                x += 3;
            }
            qsort(grupo, 9, sizeof(int), cmp_int);
            for (int c = 0; c < 9; c++) 
                if (grupo[c] == linha[c]) gp++;
            if (gp == 9) resp++;    
        }
    }
    free(grupo);
    if (resp == 9) return 1;
    return 0;
}
int main(void) {
    int **mat = aloca(9, 9);
    mat_leit(mat, 9, 9);
    int linha[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int y = compcol(mat, linha);
    int x = complinha(mat, linha);
    int z = compgrupo(mat, linha);
    if ((y + x + z) == 3) printf("E resolucao.");
    else printf("Nao eh resolucao.");
    libera(mat, 9);
    return 0;
}