#include <stdio.h>

void parcres(int x, int y) {
    if(y > x) return;
    printf("%d ", y);
    parcres(x, y+2);
}

int main(void) {
    int x;
    scanf("%d", &x);
    parcres(x, 0);
    return 0;
}