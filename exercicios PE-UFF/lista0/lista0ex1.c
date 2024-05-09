#include <stdio.h>

int main(void) {
    int x, y;
    do {
        int resp = 0;
        printf("insira dois numeros para calcular o MDC entre eles: ");
        scanf("%d %d", &x, &y);
        if ((x <= 1) || (y <= 1)) return 0;
        else {
            int i = 2;
            while ((i <= x) || (i <= y)) {
                if ((x % i == 0) && (y % i == 0)) {
                    resp = i;
                    i++;
                }
                else i++;
            }
        }
        if (resp == 0) printf("o MDC eh 1\n");
        else printf("O MDC e %d\n", resp);
    } while (1);
}
