#include <stdio.h>

int pad(int n){
    int x;
    if (n < 0) return -1;
    if ((n == 0) || (n == 1) || (n == 2)) return 1;
    x = pad(n-2) + pad(n - 3);
    return x;
}

int main(void) {
    int n,x;
    scanf("%d", &n);
    x = pad(n);
    if (x < 0) printf("INVALIDO");
    else printf("%d", x);
    return 0;
}