#include <stdio.h>
#include <string.h>

void pal(char *str, int i, int f) {
    if (i >= f) {
        printf("palindromo");
        return;
    }
    if (str[i] == str[f]){
        pal(str, i + 1, f - 1);
    }
    else {
        printf("nao e palindromo");
        return;
    }
}
int main(void) {
    char str[50];
    scanf("%s", str);
    pal(str, 0, strlen(str)- 1);
    return 0;
}