#include <stdio.h>
#include "vet2.c"

int main(void) {
    int n, c = 0;
    printf("Digite o tamanho dos números");
    scanf("%d", &n);
    int vet[n], vet2[n];
    vet_leit(vet, n);
    vet_leit(vet2, n);
    vet_qs(vet, n);
    vet_qs(vet2, n);
    for (int i = 0; i < n; i++) {
        if (vet[i] == vet2[i]) c++;
    }
    if (c == n) printf("A eh permutacao de B");
    else printf("A nao eh permutacao de B");
    return 0;
}