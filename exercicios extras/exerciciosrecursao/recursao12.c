#include <stdio.h>

void impcres(int x, int y) {
    if(y > x) return;
    printf("%d ", y);
    impcres(x, y+1);
}

int main(void) {
    int x;
    scanf("%d", &x);
    impcres(x, 0);
    return 0;
}