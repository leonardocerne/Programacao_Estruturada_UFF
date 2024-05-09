// Escreva uma função recursiva para comparar uma parte de duas strings. Sua função recebe os dois índices e as duas strings, e retorna os seguintes valores:
//                              0, s1 = s2, [i1, i2]
// f(s1, s2, i1, i2) =  1, s1 > s2, [i1, i2]
//                             -1, caso contrário.
// Pode ser informado i1 > i2. Seu programa deve passar como terceiro (quarto) parâmetro, o menor (maior) índice: int f(char *s1, char *s2, int i1, int i2);

#include <stdio.h>
#include <string.h>
#include <limits.h>

int faux(char *s1, char *s2, int i1, int i2){
    if(i1 > i2) return 0;
    if(s1[i1] < s2[i1]) return -1;
    if(s1[i1] > s2[i1]) return 1;
    f(s1, s2, i1+1, i2);
}

int f(char *s1, char *s2, int i1, int i2) {
    if((i1 > strlen(s1)) || (i2 > strlen(s1)) || (i1 > strlen(s2)) || (i1 > strlen(s2))) return INT_MIN;
    if(i1 > i2) return faux(s1, s2, i2, i1);
    if(i2 > i1) return faux(s1, s2, i1, i2);
}

int main(void) {
    int i1, i2;
    scanf("%d%d", &i1, &i2);
    char s1[30], s2[30];
    scanf("%s", s1);
    scanf("%s", s2);
    int x = f(s1, s2, i1, i2);
    if(x < -1) printf("ERRO");
    else printf("%d", x);
    return 0;
}