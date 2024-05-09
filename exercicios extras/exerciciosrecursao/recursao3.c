#include <stdio.h>

int inv(int n, int x) {
    if (n == 0) return x;
    return inv(n / 10, x * 10 + n % 10);
}

int main(void) {
    int n,x;
    scanf("%d", &n);
    x = inv(n, 0);
    printf("%d", x);
    return 0;
}