#include <stdio.h>

void fibp(int x) {
    if(x < 0) return;
    if(x == 0) printf("b");
    else if(x == 1) printf("a");
    else {
    fibp(x - 1);
    fibp(x - 2);
    }
}
int main(void) {
    int x;
    scanf("%d", &x);
    fibp(x);
    return 0;
}