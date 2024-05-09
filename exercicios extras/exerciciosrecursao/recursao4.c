#include <stdio.h>

int sum(int *vet,int n, int x) {
    if(n == 0) return x;
    return sum(vet, n-1, x + vet[n-1]);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int vet[n];
    for(int i = 0; i < n; i++) scanf("%d", &vet[i]);
    int x = sum(vet, n, 0);
    if (x < 0) printf("INVALIDO");
    else printf("%d", x);
    return 0;
}