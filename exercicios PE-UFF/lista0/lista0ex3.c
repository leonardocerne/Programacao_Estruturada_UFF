#include <stdio.h>

int main(void) {
    int n;
    do {
        printf("Escreva um numero para descobrir todos os divisores dele: ");
        scanf("%d", &n);
        if (n < 2) return 0;
        else {
            for (int i = 1; i <= n; i++) {
                if (n % i == 0) printf("%d ", i);
            }
            printf("\n");
        }
    } while (1);
}