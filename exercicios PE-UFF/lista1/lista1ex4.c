#include <stdio.h>

int main(void) {
    int n, x, y;
    printf("quantos testes voce quer: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int resp = 0;
        printf("insira a quantidade de figurinhas de victor e leo: ");
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
        if (resp == 0) printf("1 figurinha\n");
        else printf("%d figurinhas\n", resp);
    }
    return 0;
}
