#include <stdio.h>

int main(void) {
    int a, b, resp;
    char o;
    do {
        scanf("%d %c %d", &a, &o, &b);
        switch (o) {
            case 'q':
                return 0;
            case 'Q':
                return 0;
            case '+': resp = a + b;
            break;
            case '-': resp = a - b;
            break;
            case '*': resp = a * b;
            break;
            case '/':
                if (b == 0) {
                    printf("INVALIDO\n");
                    continue;
                }
                else {
                    resp = a / b;
                }
            break;
            case '%': resp = a % b;
            default:
                printf("INVALIDO\n");
                continue;
        }
        printf("%d %c %d = %d\n", a, o, b, resp);
    } while (1);
}