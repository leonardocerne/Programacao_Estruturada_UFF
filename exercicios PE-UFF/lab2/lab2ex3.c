#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ret_pont (char *arq_ent, char *arq_saida, char **pontuacao, int n) {
    FILE *fpin = fopen(arq_ent, "r"), *fpout = fopen(arq_saida, "w");
    if((!fpin) || (!fpout)) exit(1);
    char ant[50], atual[50];
    int c = 0;
    fscanf(fpin, "%s", ant);
    fprintf(fpout,"%s ", ant);
    while(fscanf(fpin, "%s", atual) == 1) {
        c = 0;
        for (int k = 0; k < n; k++) {
            if(strcmp(atual, pontuacao[k]) == 0) c++;
        }
        if (c == 0) fprintf(fpout, "%s ", atual);
        strcpy(ant, atual);
    }
    fclose(fpin);
    fclose(fpout);
}

int main(void) {
    int n;
    scanf("%d", &n);
    char **pont = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++) pont[i] = (char*)malloc(sizeof(char*) * 31);
    for (int j = 0; j < n; j++) scanf(" %30[^\n]", pont[j]);
    char arqent[50], arqsai[50];
    ret_pont("entrada.txt", "saida.txt", pont, n);
    return 0;
}