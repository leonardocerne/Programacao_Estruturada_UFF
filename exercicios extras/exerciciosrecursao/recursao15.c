#include <stdio.h>

void pardecr(int x) {
    if(x < 0) return;
    printf("%d ", x);
    pardecr(x-2);
}
int main(void) {
    int x;
    scanf("%d", &x);
    pardecr(x);
    return 0;
}