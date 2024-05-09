#include <stdio.h>
#include <stdlib.h>
#include "mat.c"

void misc(int **mat, int lin, int col, int flag) {
    if (flag == 0) {
        for (int i = 0; i < col; i++){
            for (int j = 0; j < lin; j++) {
                printf("%d ", mat[j][i]);
            }
            printf("\n");
        }
    }    
    else {
        for (int k = 0; k < lin; k ++){
            for (int f = 0; f < k + 1; f++){
                printf("%d ", mat[k][f]);
            }
            printf("\n");
        }
    }
}

int main(void) {
    int lin, col;
    scanf("%d%d", &lin, &col); 
    int **mat = aloca(lin, col);
    mat_leit(mat, lin, col);
    int flag = esim(mat, lin, col);
    misc(mat, lin, col, flag);
    return 0;
}