#include <stdio.h>

int fat(int n);
int main() {
    int numero, fatorial;
    scanf("%d", &numero);
    fatorial = fat(numero);
    printf("O Fatorial de %d e %d", numero, fatorial);
    return 0;
}
int fat(int n) {
    int k = n - 1, valor, antigo = n;
    while (k > 0) {
        valor = antigo * k;
        antigo = valor;
        k--;
    }
    return valor;
}