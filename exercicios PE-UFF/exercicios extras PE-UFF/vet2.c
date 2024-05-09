#include <stdio.h>
#include <string.h>

void vet_leit(int *vet, int n){
    int i;
    for(i = 0; i < n; i++)                  // lê o vetor
        scanf("%d", &vet[i]);
}

void vet_imp(int *vet, int n){
    int i;
    for(i = 0; i < n; i++)                  // imprime o vetor
        printf("%d ", vet[i]);
    printf("\n");
}

void vet_bs(int *vet, int n) {
    int i, j, tmp;
    for (j = n - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (vet[i] > vet[i + 1]) {      // ordena o vetor usando bubble sort
                tmp = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = tmp;
            }
}

void vet_ss(int *vet, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int menor = i, j;
        for (j = i + 1; j < n; j++)          // ordena o vetor usando selection sort
            if (vet[menor] > vet[j])
                menor = j;
        if (i != menor) {
            int tmp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = tmp;
        }
    }
}

void vet_qs(int *vet, int n) {
    if (n <= 1) return;
    int x = vet[0], a = 1, b = n - 1;
    do {
        while((a < n) && (vet[a] <= x)) a++;
        while(vet[b] > x) b--;
        if (a < b) {                       // ordena o vetor usando quick sort
            int tmp = vet[a];
            vet[a] = vet[b];
            vet[b] = tmp;
            a++; b--;
        }
    } while (a <= b);
    vet[0] = vet[b];
    vet[b] = x;
    vet_qs(vet, b);
    vet_qs(&vet[b + 1], n - 1 - b);
}

int vet_bb(int *vet, int n, int x) {
    int ini = 0, fim = n-1, meio;
    while(ini <= fim) {
        meio = (ini + fim) / 2;
        if(vet[meio] == x) return meio;    // busca binária em vetor ordenado
        if(vet[meio] < x) ini = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int cmp_int(const void *x, const void *y) { 
        int *px = (int *)x, *py = (int *)y; // derreferenciamento, ou seja, afirma o tipo dos elementos
        if ((*px) < (*py)) return -1;           //função comparação
        if ((*px) > (*py)) return 1;
        return 0;               
    }   

int cmp_str(const void *x, const void *y) {
    return (strcmp((char *) x, (char *) y));
}
