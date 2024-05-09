#include <stdio.h>

int seqf(int x) {
    if(x == 1) return 1;
    if(x == 2) return 2;
    int y = (2 * seqf(x-1)) + (3 * seqf(x - 2));
    return y;
}

int main(void) {
    int x;
    scanf("%d", &x);
    int y = seqf(x);
    printf("%d", y);
    return 0;
}