#include <stdio.h>
#include <limits.h>

int fat(int n){
    if (n < 0) return INT_MIN;
    if (n == 0) return 1;
    return n * fat(n - 1);
}

int main(void) {
    int n, x;
    do {
        scanf("%d", &n);
        if (n < 0) return 0;
        else {
            x = fat(n);
            printf("%d", x);
        }
    } while (1);
}