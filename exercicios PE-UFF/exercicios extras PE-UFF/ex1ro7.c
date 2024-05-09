#include <stdio.h>

int main(void) {
    int a, b, resp;
    char o;
    do {
        scanf("%d %c %d", &a, &o, &b);
        if ((o == 'q') || (o == 'Q')) return 0;
        if (o == '+') resp = a + b;
        else if (o == '-') resp = a - b;
        else if (o == '*') resp = a * b;
        else if (o == '/') {
            if (b == 0) {
                printf("INVALIDO\n");
                continue;
            }
            else resp = a / b;
        }
        else if (o == '%') resp = a % b;
        else {
            printf("INVALIDO\n");
            continue;
        }
        printf("%d %c %d = %d\n", a, o, b, resp);
    } while(1);
}
