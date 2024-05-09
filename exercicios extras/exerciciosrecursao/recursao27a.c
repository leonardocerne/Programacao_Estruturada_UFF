#include <stdio.h>

void bin(int x) {
    if(x == 0) return;
    bin(x / 2);
    printf("%d", x % 2);
}

int main(void) {
    int x;
    scanf("%d", &x);
    bin(x);
    return 0;
}