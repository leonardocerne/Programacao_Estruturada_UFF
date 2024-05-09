#include <stdio.h>

int mult(int x, int y, int c){
    if(y == 0) return c;
    return mult(x, y-1, c + x);
}
int main(void) {
    int x, y, resp;
    scanf("%d%d", &x, &y);
    resp = mult(x, y, 0);
    printf("%d", resp);
    return 0;
}