#include <stdio.h>

void impdecr(int x) {
    if(x < 0) return;
    printf("%d ", x);
    impdecr(x-1);
}
int main(void) {
    int x;
    scanf("%d", &x);
    impdecr(x);
    return 0;
}