#include <stdio.h>
#include <string.h>

typedef struct aluno{
    char nome[31];
    char mat[10], turma[3];
    float p1, p2;
}TALUNO;

void imprime (TALUNO **mat, int n) {
    float media;
    for(int i = 0; i < n; i++) {
        media = (mat[i]->p1 + mat[i]->p2) / 2;
        if (media >= 6.0) printf("O aluno %s da turma %s de matricula %s foi aprovado com media %.1f.\n", mat[i]->nome, mat[i]->turma, mat[i]->mat, media);
    }
    return;
}

int main(void) {
    int n;
    printf("Digite a quantidade de alunos:");
    scanf("%d", &n);
    TALUNO **mataluno = (TALUNO**)malloc(sizeof(TALUNO*) * n);
    for(int i = 0; i < n; i++) {
        mataluno[i] = (TALUNO*)malloc(sizeof(TALUNO));
        printf("Digite o nome do aluno:");
        scanf(" %30[^\n]", mataluno[i]->nome);
        printf("Digite o numero de matricula do aluno:");
        scanf("%s", mataluno[i]->mat);
        printf("Digite a turma do aluno:");
        scanf("%s", mataluno[i]->turma);
        printf("Digite a nota da P1 e P2 do aluno:");
        scanf("%f%f", &mataluno[i]->p1, &mataluno[i]->p2);
    }
    imprime(mataluno, n);
    for(int j = 0; j < n; j++) free(mataluno[j]);
    free(mataluno);
    return 0;
}