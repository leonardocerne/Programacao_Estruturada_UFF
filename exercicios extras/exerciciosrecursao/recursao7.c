#include <stdio.h>

void invvet(int *vet, int n, int x){
    if((n == x) || (x < n)) return 0;
    int tmp = vet[n];
    vet[n] = vet[x];
    vet[x] = tmp;
    invvet(vet, n+1, x-1);
}

int main(void){
    int vet[100];
    for(int i = 0; i < 100; i++) scanf("%d", &vet[i]);
    invvet(vet, 0, 99);
    for(int j = 0; j < 100; j++) printf("%d ", vet[j]);
    return 0;
}