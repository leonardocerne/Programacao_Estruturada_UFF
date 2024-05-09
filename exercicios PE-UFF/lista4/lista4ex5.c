#include <stdio.h>
#include <string.h>

int cic (char *str1, char *str2){
    int i = 0, c = 0, x = 0;
    while (i < strlen(str1)) {
        if (x == strlen(str2)) break;
        if (str1[i] == str2[c]){
            x++;
            c++; 
        }
        else {
            x = 0;
            c = 0;
        }
        i++;
    }
    if (x == strlen(str2)) return 1;
    return 0;
}
int main(void) {
    int x;
    char p[100], s[100];
    scanf(" %99[^\n]", p);
    scanf(" %99[^\n]", s);
    if (strlen(p) < strlen(s)) printf("ERRO");
    else {
        x = cic(p, s);
        printf("%d", x);
    }
    return 0;
}