#include <stdio.h>

int tetran(int n){
    int x;
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 0;
    if (n == 3) return 1;
    x = tetran(n-1) + tetran(n - 2) + tetran(n - 3) + tetran(n - 4);
    return x;
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = tetran(x);
    printf("%d", y);
    return 0;
}