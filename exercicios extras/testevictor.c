#include <stdio.h>
#include <stdlib.h>
void libera(int **mat, int lin) {
    for(int i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);
}
void vet_bs(int *vet, int n){
    int i, j;
    for(j = n - 1; j > 0; j--)
        for(i = 0; i < j; i++)
            if(vet[i] > vet[i + 1]){
                int tmp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = tmp;
            }
}
int grupos(int **mat,int lin, int col){
    for (int i=0;i<lin;i+=3){
        for(int j=0;j<col;j+=3){
            int vet[9]={mat[i][j],mat[i][j+1],mat[i][j+2],mat[i+1][j],mat[i+1][j+1],mat[i+1][j+2],mat[i+2][j],mat[i+2][j+1],mat[i+2][j+2]};
            vet_bs(vet,9);
            for (int h=0;h<9;h++) if (vet[h]!=h+1) return 0;
        }
    }
    return 1;
}
int ordena(int **mat, int lin, int col){
    int vetaux[lin];
    for (int i = 0; i<9; i++) {
        for (int j = 0; j < 9; j++) {
            vetaux[j] = mat[i][j];
        }
        vet_bs(vetaux,9);
        for (int h=0;h<9;h++) if(vetaux[h]!= h+1) return 0;
    }
    for (int i=0; i<col;i++){
        for (int j=0;j<lin;j++) {
            vetaux[j] = mat[j][i];
        }
        vet_bs(vetaux,9);
        for (int h=0;h<lin;h++) if (vetaux[h]!=h+1) return 0;
    }
    return 1;
}
int ** aloca(int **og, int lin, int col) {
    int **mat = (int **)malloc(sizeof(int*) * lin);
    int i;
    for (i = 0; i < lin; i++){
        mat[i] = (int *)malloc(sizeof(int) * col);
        for (int j=0;j<col;j++){
            mat[i][j]=og[i][j];
        }
    }
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
int main() {
    int **mat = (int **)malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++){
        mat[i] = (int *) malloc(sizeof(int) * 9);
    }
    mat_leit((int **) mat, 9, 9);
    int **mat2 = aloca((int **) mat, 9, 9);
    int x = ordena(mat,9,9);
    if (x==0) printf("nao eh sudoku");
    else {
        int y = grupos((int **) mat, 9, 9);
        if (y==0) printf("nao eh sudoku");
        else printf("sudoku");
    }
    libera(mat,9);
    libera(mat2,9);
    return 0;
}