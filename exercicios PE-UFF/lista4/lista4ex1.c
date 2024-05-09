#include <stdio.h>
#include <string.h>

void shift_troca_string(char *str) {
    int h = strlen(str);
    for(int i = 0; i < h ; i++) {
        if(str[i] == 65) str[i] = 122;
        else if(str[i] == 97) str[i] = 90;
        else if((str[i] > 65) && (str[i] < 91)) str[i] += 31;
        else if((str[i] > 97) && (str[i] < 123)) str[i] -= 33;
        else str[i] = '!';
    }
}
int main(void) {
    char ent[100];
    scanf(" %99[^\n]", ent);
    shift_troca_string(ent);
    printf("%s\n", ent);
    return 0;
}


