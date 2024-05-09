#include <stdio.h>

int pot(int n, int x){
    if(x == 0) return 1;
    return n * pot(n, x-1);
}

int fatexp(int n){
    if(n < 0) return -1;
    if(n == 0) return 1;
    return pot(n, fatexp(n-1));
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = fatexp(x);
    printf("%d", y);
}