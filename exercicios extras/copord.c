#include <stdio.h>
#include <stdlib.h>
#include "vet2.c"

    int *cop_ord (int *vet, int n);

    int main(void) {
        int n;
        do{
            scanf("%d", &n);
        } while (n <= 0);
        int vet[n];
        vet_leit(vet, n);
        vet_imp(vet, n);
        int *resp = cop_ord(vet, n);
        vet_imp(vet, n);
        vet_imp(resp, n);
        free(resp);
        return 0;
    }

    int *cop_ord(int *vet, int n) {
        int *resp = (int*)malloc(sizeof(int) * n);
        if (!resp) exit(1);
        int i;
        for(i = 0; i < n; i++)
            resp[i] = vet[i] + 1;
        qsort(resp, n, sizeof(int), cmp_int);
        return resp;    
    }
