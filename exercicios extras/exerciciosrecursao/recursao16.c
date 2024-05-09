#include <stdio.h>

int fatduplo(int x) {
    if(x < 0) return -1;
    if(x == 1) return 1;
    return x * fatduplo(x - 2);
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = fatduplo(x);
    if(y == 0) printf("ERRO, numero par");
    else printf("%d", y);
    return 0;
}