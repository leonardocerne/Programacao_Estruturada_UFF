#include <stdio.h>

int sum2(int n, int x) {
    if (n == 0) return x;
    return sum2(n - 1, x + n);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int x = sum2(n, 0);
    if (x < 0) printf("INVALIDO");
    else printf("%d", x);
    return 0;
}