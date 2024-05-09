#include <stdio.h>

int main() {
    int n, k = 0;
    scanf("%d", &n);
    int d = n - 1;
    if (d == 1 || d == 0) {
        printf("O numero %d eh primo", n);
    }
    else {
        while (k < n - 1) {
            if (d > 1 && n % d == 0) {
                printf("O numero %d nao e primo", n);
                k = n;
            }
            else if (d == 1) {
                printf("O numero %d e primo", n);
                k = n;
            }
            else {
                d--;
            }
        }
        return 0;
    }
}