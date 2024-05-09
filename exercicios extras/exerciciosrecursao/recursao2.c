#include <stdio.h>

int fib(int n){
    int x;
    if (n < 0) return -1;
    if (n == 0) return 0;
    if ((n == 1) || (n == 2)) return 1;
    x = fib(n-1) + fib(n - 2);
    return x;
}

int main(void) {
    int n,x;
    scanf("%d", &n);
    x = fib(n);
    if (x < 0) printf("INVALIDO");
    else printf("%d", x);
    return 0;
}