#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vet2.c"

int main(void) {
    char str[100], str2[100];
    scanf(" %99[^\n]", str);
    scanf(" %99[^\n]", str2);
    qsort(str, 100, sizeof(char), cmp_str);
    qsort(str2, 100, sizeof(char), cmp_str);
    if (strcmp(str, str2) == 0) printf("sao permutacoes");
    else printf("nao sao permutacoes");
    return 0;
}