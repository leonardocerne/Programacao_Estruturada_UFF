#include <stdio.h>
#include <stdlib.h>

int buscas(int *vet, int k, int in, int fi) {
    if (in > fi) return -1;
    int meio = (in + fi) / 2;
    if(vet[meio] == k) {
        int p = buscas(vet, k, in, meio - 1);
        if (p == -1) return meio;
        else return p;
    }
    else {
        int pe = buscas(vet, k, in, meio - 1);
        int pd = buscas(vet, k, meio + 1, fi);
        if (pe != -1) return pe;
        else return pd;
    }
}
int main(void) {
    int n;
    scanf("%d", &n);
    int *vet = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &vet[i]);
    int k;
    scanf("%d", &k);
    int r = buscas(vet, k, 0, n-1);
    printf("%d", r);
    return 9;
}