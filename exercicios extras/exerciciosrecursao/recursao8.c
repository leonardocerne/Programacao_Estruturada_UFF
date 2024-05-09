#include <stdio.h>

int mdc(x, y) {
    if(y == 0) return x;
    return mdc(y, x%y);
}

int main(void){
    int n1, n2, x;
    scanf("%d%d", &n1, &n2);
    x = mdc(n1, n2);
    printf("%d", x);
    return 0;
}