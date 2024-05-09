#include <stdio.h>

int main(void) {
    int x, p;
    printf("Insira um numero e qual potencia ele sera elevado: ");
    scanf("%d %d", &x, &p);
    int z = x;
    for (int i = 1; i < p; i++) {
        x *= z;
    }
    printf("Resultado = %d", x);
    return 0;
}