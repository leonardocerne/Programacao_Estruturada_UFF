#include <stdio.h>
#include <string.h>

void retira_fim_n (char *str, int n) {
    for (int i = 0; i < strlen(str) - n; i++){
        printf("%c", str[i]);
    }
}
int main(void) {
    int n;
    char s[100];
    scanf("%d", &n);
    scanf(" %99[^\n]", s);
    if(n > strlen(s)) printf("ERRO");
    else retira_fim_n(s, n);
    return 0;
}