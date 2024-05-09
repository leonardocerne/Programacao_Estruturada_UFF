#include <stdio.h>

void peito(int n) {
    if (n == 1) printf("1 ");
    else {
        peito(n-1);
        printf("%d ", n);
        peito(n-1);
    }
    return;
}
int main(void) {
    int n;
    scanf("%d", &n);
    peito(n);
}