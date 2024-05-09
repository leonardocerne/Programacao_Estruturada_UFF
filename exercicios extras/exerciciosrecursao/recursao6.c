#include <stdio.h>

int pot(int n,int u, int x){
    if(x == 1) return n;
    return pot(n*u, u, x-1);
}
int main(void) {
    int n, x, resp;
    scanf("%d%d", &n, &x);
    int u = n;
    if(x == 0) printf("1");
    else if(x < 0) printf("INVALIDO");
    else {
        resp = pot(n, u, x);
        printf("%d", resp);
    }
    return 0;
}