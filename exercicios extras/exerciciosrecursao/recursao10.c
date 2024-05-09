#include <stdio.h>

int oco(int x, int n, int r){
    if(x == 0) return r;
    if(n == (x % 10)) r++;
    oco(x / 10, n, r);
}
int main(void) {
    int x, n, resp;
    scanf("%d%d", &x, &n);
    resp = oco(x, n, 0);
    printf("%d", resp);
    return 0;
}