#include <stdio.h>
#include <math.h>

int digitos(int n) {
    int dig = 0;
    while (n > 0) {
        n /= 10;
        dig ++;
    }
    return dig;
}

int inversor(int n, int dig) {
    int cn = n;
    int resp = 0, d = 1, d2 = dig - 1;
    for (int i = 0; i < dig; i++) {
        resp += (cn % 10) * (int)pow(10, d2);
        d++;
        d2--;
        cn /= 10;
    }
    return resp;
}

int main(void) {
    int n, inv, dig;
    do {
        scanf("%d", &n);
        if (n < 0) return 0;
        else {
            dig = digitos(n);
            inv = inversor(n, dig);
            if (n == inv) printf("VERDADEIRO\n");
            else printf("FALSO\n");
        }
    } while(1);
}
