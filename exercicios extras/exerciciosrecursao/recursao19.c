#include <stdio.h>

int pot(int n, int x){
    if(x == 0) return 1;
    return n * pot(n, x-1);
}

int hipfat(int n){
    if(n < 0) return -1;
    if(n == 0) return 1;
    int x = pot(n,n) * hipfat(n - 1);
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = hipfat(x);
    printf("%d", y);
}