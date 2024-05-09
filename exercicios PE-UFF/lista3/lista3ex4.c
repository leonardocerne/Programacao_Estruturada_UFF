#include <stdio.h>
#include "vet2.c"

int main(void) {
    int n, m;
    do {
        int  resp = 0;
        scanf("%d %d", &n, &m);
        if ((n == 0) && (m == 0)) return 0;
        int vet[m];
        vet_leit(vet, m);
        for (n; n>0; n--){
            int c = 0;
            for(int i = 0; i < m; i++) {
                if (vet[i] == n) c++;
            }
            if (c > 1) resp++;
        }
        printf("%d\n", resp);
    } while (1);
}