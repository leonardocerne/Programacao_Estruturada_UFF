#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RetRepet(char *ArqEnt, char *ArqSaida){
    FILE *fp1 = fopen(ArqEnt, "r");
    FILE *fp2 = fopen(ArqSaida, "w");
    if((!fp1) || (!fp2)) exit(1);
    char ant[50], atual[50];
    int r = fscanf(fp1, "%s", ant);
    fprintf(fp2, "%s ", ant);
    while(r == 1){
        r = fscanf(fp1, "%s", atual);
        if(strcmp(ant, atual) != 0) fprintf(fp2, "%s ", atual);
        strcpy(ant, atual);
    }
    fclose(fp1);
    fclose(fp2);
}

int main(void) {
    char arqent[50], arqsai[50];
    scanf("%s", arqent);
    scanf("%s", arqsai);
    RetRepet(arqent, arqsai);
    return 0;
}