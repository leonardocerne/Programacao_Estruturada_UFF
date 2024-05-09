#include <stdio.h>

float cat(float n){
    float x;
    if (n < 0) return -1;
    if (n == 0) return 1;
    x = ((2 * ((2 * n) - 1)) / (n + 1)) * cat(n - 1);
    return x;
}

int main(void) {
    float n,x;
    scanf("%f", &n);
    x = cat(n);
    if (x < 0) printf("INVALIDO");
    else printf("%.0f", x);
    return 0;
}