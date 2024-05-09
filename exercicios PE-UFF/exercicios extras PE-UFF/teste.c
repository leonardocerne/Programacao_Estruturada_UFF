#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[50], s2[50];
    scanf(" %49[^\n]", s1);
    scanf(" %49[^\n]", s2);
    if (strcmp(s1, s2) == 0) printf("As strings sao iguais");
    if (strcmp(s1, s2) < 0) printf("A primeira string e menor que a segunda\n");
    if (strcmp(s1, s2) > 0) printf("A primeira string e maior que a segunda\n");
    printf("o tamanho da primeira string eh %d e o da segunda eh %d", strlen(s1), strlen(s2));
    return 0;
}