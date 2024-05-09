// escreva um programa que ordena uma turma de n alunos.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordena(char **turma, int n) {
    int i, j;
    char tmp[31];
    for (j = n - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (strcmp(turma[i], turma[i + 1]) > 0) {
                strcpy(tmp, turma[i]);
                strcpy(turma[i], turma[i + 1]);
                strcpy(turma[i + 1], tmp);
            }
}
int main(void) {
    int n;
    scanf("%d", &n);
    char **turma = (char**)malloc(sizeof(char*) * n);
    for(int m = 0; m < n; m++) turma[m] = (char*)malloc(sizeof(char)*31);
    for (int i = 0; i < n; i++) scanf(" %30[^\n]", turma[i]);
    ordena(turma, n);
    for(int j = 0; j < n; j++) {
        printf("%s ", turma[j]);
    }
    for(int k = 0; k < n; k++) free(turma[k]);
    free(turma);
    return 0;
}