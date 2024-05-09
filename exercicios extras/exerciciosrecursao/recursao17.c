#include <stdio.h>

int fatquad(int n, int u){
    if(n < 0) return -1;
    if(u == n) return 1;
    return u * fatquad(n, u - 1);
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    int u = 2 * n;
    x = fatquad(n, u);
    printf("%d", x);
    return 0; 
}