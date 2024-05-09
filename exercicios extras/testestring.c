#include <stdio.h>
#include <string.h>

int main(void)  {
    char str[50], str2[50];
    scanf("%s", str);
    scanf("%s", str2);
    printf("%s %s\n", str, str2);
    strcpy(str2, str);
    printf("%s", str2);
    return 0;
}