#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    int prim = (x * (x - 1)) + 1;
    printf("%d ", prim);
    for (int i = 1; i < x; i++) {
        prim += 2;
        printf("%d ", prim);
    }
    return 0;
}