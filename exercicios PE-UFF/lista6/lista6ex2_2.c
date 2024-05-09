#include <stdio.h>
#include <stdlib.h>

void resumo(char *Arq) {
    int vet[11], tmp, r = 1;
    for(int i = 0; i < 11; i++) vet[i] = 0;
    FILE *fp = fopen(Arq, "r");
    while(r == 1) {
        r = fscanf(fp, "%d", &tmp);
        if (r == 1) vet[tmp]++;
    }
    for(int j = 0; j < 11; j++) {
        printf("o numero %d aparece %d vezes\n", j, vet[j]);
    }
    fclose(fp);
}

int main(void) {
    char arqent[50];
    scanf("%s", arqent);
    resumo(arqent);
    return 0;
}