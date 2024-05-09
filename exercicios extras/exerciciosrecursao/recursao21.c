#include <stdio.h>

int tribon(int n){
    int x;
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;
    x = tribon(n-1) + tribon(n - 2) + tribon(n - 3);
    return x;
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = tribon(x);
    printf("%d", y);
    return 0;
}