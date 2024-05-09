#include <stdio.h>

int teste(int n) {
    int cn = n, f, u = n % 100;
    while (cn / 100 != 0) {
        cn /= 10;
        f = cn;
    }
    if (((f + u) * (f + u)) == ((f * 100) + u))  return 1;
    else return 0;
}
int main(void) {
    int x, resp;
    do {
        printf("Digite um numero: ");
        scanf("%d", &x);
        if (x < 0) return 0;
        else {
            resp = teste(x);
            printf("%d\n", resp);
        }
    } while (1);
}