#include <stdio.h>
#include <stdbool.h>

bool primo(int x) {
    int z = 1, c = 0;
    if (x == 1) return true;
    else {
        while (z <= x) {
            if (x % z == 0) c++;
            z++;
        }
        if (c == 2) return true;
        else return false;
    }
}

int main(void) {
    do {
        int n, x = 0, p = 1;
        printf("Insira a quantidade de numeros primos que voce quer: ");
        scanf("%d", &n);
        if (n <= 0) return 0;
        while (x < n) {
            if (primo(p) == true) {
                printf("%d ", p);
                p++;
                x++;
            }
            else p++;
        }
        printf("\n");
    } while(1);
}