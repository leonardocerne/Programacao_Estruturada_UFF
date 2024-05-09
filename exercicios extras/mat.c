#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ** aloca(int lin, int col) {
    int **mat = (int **)malloc(sizeof(int *) * lin);
    int i;
    for (i = 0; i < lin; i++) 
        mat[i] = (int *)malloc(sizeof(int) * col);
    return mat;    
}

void mat_leit(int **mat, int lin, int col) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void mat_imp(int **mat, int lin, int col) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void libera(int **mat, int lin) {
    int i;
    for(i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);
}
 
void leiturasim(int **mat, int lin) {
    int i, j;
    for (i = 0; i < lin; i ++){
        for (j = 0; j <= i; j++){
            scanf("%d", &mat[i][j]);
        }
    }
} 

void imprimesim(int **mat, int lin) {
    int i, j;
    for (i = 0; i < lin; i ++){
        for (j = 0; j < i + 1; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int **alocasim(int **mat, int lin) {
    int **sim = (int **)malloc(sizeof(int *) * lin);
    int i;
    for (i = 0; i < lin; i++) {
        sim[i] = (int *)malloc(sizeof(int) * (i + 1));
    }
    return sim;
}

int esim(int **mat, int l, int c) {
    if (l != c) return 0;
    int i, j;
    for (i = 1; i < l; i++)
        for (j = 0; j < i; j++) {
            if(mat[i][j] != mat[j][i]) return 0;
        }
    return 1;    
}

