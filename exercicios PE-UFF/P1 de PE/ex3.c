/*
A questão pedia que fizemos uma função recursiva que recebia uma matriz, ordenada em linhas e colunas,
e achasse e retornasse a posição de um elemento x procurado.
Onde a função teria corpo: void f(int **mat, int lin, int col, int x, int *pos_lin, int *pos_col).
*/
#include "stdlib.h"
#include "stdio.h"
void fa(int **mat, int lin, int col, int x, int *pos_lin, int *pos_col){
    if ((lin<=0)||(col<=0)){
        (*pos_lin) = (*pos_col) = -1;
        return;
    }
    if (mat[0][col-1]==x) return;
    if (mat[0][col-1]>x){
        (*pos_col)--;
        fa(mat,lin,col-1,x,pos_lin,pos_col);
    }
    else {
        (*pos_lin)++;
        fa(&mat[1], lin - 1, col, x, pos_lin, pos_col);
    }
}
void f(int **mat, int lin, int col, int x, int *pos_lin, int *pos_col){
    (*pos_lin) = 0;
    (*pos_col) = col-1;
    fa((int **) mat, lin, col, x, pos_lin, pos_col);
}
int main(){
    int x, lin,col;
    scanf("%d",&x);
    scanf("%d",&lin);
    scanf("%d",&col);
    int **mat = (int**)malloc(sizeof(int*)*lin );
    for (int i=0;i<col;i++){
        mat[i] = (int*) malloc(sizeof (int)*col);
    }
    for (int i=0;i<lin;i++){
        for (int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int pos_col;
    int pos_lin;
    f((int **) mat, lin, col, x, &pos_lin, &pos_col);
    printf("[%d][%d]",pos_lin,pos_col);
    for (int i=0;i<lin;i++) free(mat[i]);
    free(mat);
    return 0;
}