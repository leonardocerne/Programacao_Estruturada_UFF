#include <stdio.h>
#include <string.h>

typedef struct aluno{
    char nome[31];
    char mat[10], turma[3];
    float p1, p2;
}TALUNO;

float media_geral(TALUNO **mat, int n, char *turma){
    int cont = 0;
    float media = 0;
    for (int i = 0; i < n; i++) {
        if(strcmp(mat[i]->turma, turma) == 0) {
            media += (mat[i]->p1 + mat[i]->p2) / 2;
            cont++;
        }
    }
    if(cont == 0) return -1;
    return media / cont;
}

int main(void) {
    int n;
    printf("Digite a quantidade de alunos:");
    scanf("%d", &n);
    char turma[3];
    printf("Digite a turma que voce quer calcular a media");
    scanf("%s", turma);
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
    float mediageral = media_geral(mataluno, n, turma);
    printf("A media da turma %s foi %.1f.", turma, mediageral);
    for(int j = 0; j < n; j++) free(mataluno[j]);
    free(mataluno);
    return 0;
}