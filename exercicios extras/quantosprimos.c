#include <stdio.h>
#include <stdbool.h>

bool primo(int n);
int main() {
    int x, k= 0, soma = 0;
    printf("Informe a quantidade de numeros que voce vai checar se e primo: ");
    scanf("%d", &x);
    while (k < x) {
        int atual;
        scanf("%d", &atual);
        if (primo(atual) == true) {
            soma += atual;
        }
        k++;
    }
    printf("A soma dos primos digitados eh %d", soma);
    return 0;
}
bool primo(int n) {
    int d = n - 1, k = 0;
    if (d == 1) {
        return true;
    } else {
        while (k < n - 1) {
            if (d > 1 && n % d == 0) {
                k = n;
            } else if (d == 1) {
                return true;
                k = n;
            } else {
                d--;
            }
        }
        return false;
    }
}
