#include <stdio.h>
#include <stdlib.h>

void resumo(char *Arq) {
    FILE *fp = fopen(Arq, "r");
    if(!fp) exit(1);
    int aux, n;
    int r = fscanf(fp, "%d", &aux);
    if (r == 1) n = 1;
    while(r == 1) {
        r = fscanf(fp, "%d", &aux);
        if(r == 1) n++;
    }
    int *vet = (int*)malloc(sizeof(int) * n);
    rewind(fp);
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d", &vet[i]);
        printf("%d", i);
    }
    for(int ii = 0; ii < n; ii++){
        printf("%d ", vet[ii]);
    }
    printf("\n");
    for(int j = 0; j < n; j++){
        aux = vet[j];
        int cont = 0;
        int apa = 0;
        for(int m = 0; m < j; m++) if(vet[m] == aux) apa++;
        for(int k = 0; k < n; k++) {
            if(vet[k] == aux) cont++;
        }
        if(apa == 0) {
            printf("O numero: %d aparece %d vezes\n", aux, cont);
        }
    }
    fclose(fp);
}

int main(void) {
    char arqent[50];
    resumo("entrada.txt");
    return 0;
}