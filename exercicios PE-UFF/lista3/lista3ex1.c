#include <stdio.h>

int main(void) {
    int n, in = 0;
    scanf("%d", &n);
    int vet[n];
    for (int i = 2; i <= n; i++) {
        vet[in] = i;
        in++;
    }
    for (int m = 0; m < n; m++) {
        if (vet[m] != -1) {
            for (int p = m + 1; p < n; p++) {
                if ((vet[p] % vet[m] == 0) && (vet[p] != -1)) vet[p] = -1;
            }
        }
    }
    for (int l = 0; l < n; l++){
        if (vet[l] != -1) printf("%d ", vet[l]);
    }
    return 0;
}