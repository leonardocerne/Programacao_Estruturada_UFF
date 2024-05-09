#include <stdio.h>
#include "vet2.c"
#include <stdlib.h>
#include <string.h>

int cmpinteiro(const void *x, const void *y) {
    int *px = (int*)x, *py = (int*)y;
    int a = (*px), b = (*py);
    if(a > b) return -1;
    if(a < b) return 1;
    return 0;
}

int cmpchar(const void *x, const void *y) {
    char *px = (char*)x, *py = (char*)y;
    char a = (*px), b = (*py);
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int cmpstring(const void *x, const void *y) {
    char **px = (char**)x, **py = (char**)y;
    char *a = (*px), *b = (*py);
    if (strcmp(a, b) < 0) return -1;
    if (strcmp(a, b) > 0) return 1;
    return 0;
}

int main(void) {
    char **vet = (char**)malloc(sizeof(char*) * 4);
    for (int i = 0; i < 4; i++) vet[i] = (char*)malloc(sizeof(char) * 30);
    for (int k = 0; k < 4; k++) scanf(" %29[^\n]", vet[k]);
    qsort(vet, 4, sizeof(char*), cmpstring);
    for (int m = 0; m < 4; m++) printf("%s ", vet[m]);
    for (int d = 0; d < 4; d++) free(vet[d]);
    free(vet);
    return 0;
}