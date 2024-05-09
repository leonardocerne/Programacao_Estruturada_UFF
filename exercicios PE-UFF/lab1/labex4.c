#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void k_str(char *str, int k){
    if (k < 0) return 0;
    k_str(str, k - 1);
    printf("")
}

int main(void){
  char str[101];
  scanf(" %100[^\n]", str);
  int k;
  scanf("%d", &k);
  k_str(str, k);
  return 0;
}