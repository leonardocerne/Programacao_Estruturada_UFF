#include "vet.h"

void copia(int *vet, int *vet2, int n) {
    int i;
    for (i = 0; i < n; i++)
        vet2[i] = vet[i];
}

int main(void) {
    int n, i, indice;
    printf("Escreva a quantidade de ladrões: \n");
    scanf("%d", &n);
    int vet[n];
    int vet2[n];
    vet_leit(vet, n);
    copia(vet, vet2, n);
    vet_qs(vet, n);
    int ladrao = vet[n - 2];
    for (i = 0; i < n; i++) {
        if (vet2[i] == ladrao) {
            indice = i;
        }
    }
    printf("%d", indice);
    return 0;
}