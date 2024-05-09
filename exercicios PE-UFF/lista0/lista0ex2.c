#include <stdio.h>

int main(void) {
    do {
        int n, resp, antigo = 1, atual = 1, novo;
        printf("informe o n: ");
        scanf("%d", &n);
        if (n < 0) return 0;
        if (n == 0) printf("fib(%d) eh 1\n", n);
        else if (n == 1) printf("fib(%d) eh 1\n", n);
        else {
            for (int i = 2; i < n; i++) {
                novo = atual + antigo;
                antigo = atual;
                atual = novo;
            }
            printf("fib(%d) eh %d\n", n, novo);
        }
    } while(1);
}