#include <string.h>
#include <stdio.h>

void invstr(char *str, int n, int x) {
    if((n == x) || (x < n)) return 0;
    char tmp = str[n];
    str[n] = str[x];
    str[x] = tmp;
    invstr(str, n+1, x-1);
}
int main(void) {
    char str[50];
    scanf("%s", str);
    invstr(str, 0, strlen(str) - 1);
    printf("%s", str);
    return 0;
}