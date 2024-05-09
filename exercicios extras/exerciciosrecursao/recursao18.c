#include <stdio.h>

int fat(int n) {
    if(n < 0) return -1;
    if(n == 0) return 1;
    return n * fat(n - 1);
}

int supfat(int n){
    if(n == 0) return 1;
    int x = fat(n) * supfat(n - 1);
    return x;
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    x = supfat(n);
    printf("%d", x);
    return 0; 
}