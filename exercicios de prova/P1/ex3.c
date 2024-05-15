// A questão dava uma matriz ordenada nas linhas e nas colunas, um número x, e pedia a coluna e linha do x na matriz, e se não estivesse na matriz, a linha e a coluna seriam -1;

#include <stdio.h>

void fa(int **mat, int lin, int col, int x, int *pos_lin_x, int *pos_col_x) {
    if((lin <= 0) || (col <= 0)) {
        *pos_lin_x = *pos_col_x = -1;
        return;
    }
    if(mat[0][col-1] == x) return;
    if(mat[0][col-1] > x){
        *pos_col_x--;
        fa(mat, lin, col-1, x, pos_lin_x, pos_col_x);
        return;
    }
    *pos_lin_x++;
    fa(&mat[1], lin-1, col, x, pos_lin_x, pos_col_x);
}
void f(int **mat, int lin, int col, int x, int *pos_lin_x, int *pos_col_x) {
    *pos_lin_x = 0;
    *pos_col_x = col - 1;
    fa(mat, lin,col,x,pos_lin_x,pos_col_x);
}