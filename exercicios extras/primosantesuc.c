#include <stdio.h>
#include <stdbool.h>
bool primo(int n) {
    int i = 1, c = 0;
    while (i < n) {
        if (n % i == 0) {
            c++;
        }
        i++;
    }
    if (c == 1) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int x, i = 1, c = 0, contador = 2;
    scanf("%d", &x);
    while (i < x) {
        if (x % i == 0) {
            c++;
        }
        i++;
    }
    int xc = x - 1;
    if (c == 1) {
        printf("os numeros primos anteriores sao: ");
        while (contador != 0) {
            if (primo(xc) == true) {
                contador -= 1;
                printf("%d ", xc);
            }
            xc--;
        }
        int zx = x + 1;
        printf("\nos numeros primos sucessores sao: ");
        contador = 2;
        while (contador != 0) {
            if (primo(zx) == true) {
                contador -= 1;
                printf("%d ", zx);
            }
            zx++;
        }
    }
    contador = 2;

    return 0;
}