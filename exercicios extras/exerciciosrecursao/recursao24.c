#include <stdio.h>

int pell(int n){
    int x;
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    x = 2 * pell(n-1) + pell(n - 2);
    return x;
}

int main(void) {
    int n,x;
    scanf("%d", &n);
    x = pell(n);
    if (x < 0) printf("INVALIDO");
    else printf("%d", x);
    return 0;
}