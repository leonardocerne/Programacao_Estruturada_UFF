#include <stdio.h>
#include <string.h>

char * codifica(char *str) {
    char *nova = (char*)malloc(sizeof(char)*(strlen(str)+1)); 
    for(int i = 0; i < strlen(str); i++) nova[i] = str[i];
    for(int j = 0; j < strlen(str); j++){
        if(nova[j] >= 97 && nova[j] <= 122) nova[j] = '?';
    }
    nova[strlen(str)] = '\0';
    return nova;
}
int main(void) {
    char ent[100];
    scanf(" %99[^\n]", ent);
    char *nova = codifica(ent);
    printf("%s", nova);
    free(nova);
}