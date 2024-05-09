#include <stdio.h>

int main() {
    int x, atual = 1, antigo = 1, c = 0, novo;
    scanf("%d", &x);
    printf("1 1 ");
    while (c < x - 2) {
        novo = atual + antigo;
        printf("%d ", novo);
        antigo = atual;
        atual = novo;
        c++;
    }
    return 0;
}