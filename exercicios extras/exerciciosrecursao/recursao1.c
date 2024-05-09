#include <stdio.h>

int fat(int n){
    if(n < 0) return -1;
    if(n == 0) return 1;
    return n * fat(n - 1);
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    x = fat(n);
    if (x < 0) printf("invalido");
    else printf("%d", x);
    return 0; 
}