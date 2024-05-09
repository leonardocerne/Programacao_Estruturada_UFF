#include <stdio.h>
#include <stdbool.h>

bool tres(long long int n) {
    long long int n2 = n;
    while (n2 > 0) {
        if (n2 % 10 == 3) {
            return true;
        }
        n2 /= 10;
    }
    return false;
}

int main() {
    long long int c, x, tatual = 0, novo, antigo = 1, atual = 1;
    while (scanf("%lld", &x) != EOF) {
        while (tatual < x) {
            novo = atual + antigo;
            if (novo % 3 == 0 || tres(novo) == true) {
                c++;
                tatual++;
            }
            antigo = atual;
            atual = novo;
        }
        printf("%lld\n", novo);
    }
    return 0;
}