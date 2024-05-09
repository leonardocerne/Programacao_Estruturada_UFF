#include <stdio.h>
#include <stdlib.h>

void ordena(char *str) {
    int i, j, tmp;
    int t = 0;
    while (str[t]) t++;       
    for (j =  t - 1; j > 0; j--)
        for (i = 0; i < j; i++)
            if (str[i] > str[i + 1]) {      
                tmp = str[i];               
                str[i] = str[i + 1];
                str[i + 1] = tmp;
            }
}

int main(void){
  char str[101];
  scanf(" %100[^\n]", str);
  ordena(str);
  printf("%s\n", str);
  return 0;
}