#include <stdio.h>

void dec_p_bin(int n){
    if (n < 2) printf("%d", n);
    else {
        dec_p_bin(n/2);
        printf("%d", n%2);
    }
}
int main(void) {
    int n;
    do {
        scanf("%d", &n);
        if (n < 0) return 0;
        else {
            dec_p_bin(n);
            printf("\n");
        }
    } while(1);
}