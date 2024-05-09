#include <stdio.h>
#include <stdlib.h>

void crescentes(char* Arq) {
    FILE *fp = fopen(Arq, "r");
    int atual, ant, cont = 1, maior = 1;
    if(!fp) exit(1);
    int r = fscanf(fp, "%d", &ant);
    if (r != 1) printf("Arquivo vazio");
    else {
        while (r == 1) {
            r = fscanf(fp, "%d", &atual);
            if (r == 1){
                if(atual > ant) cont++;
                else cont = 1;
                if(cont > maior) maior = cont;
                ant = atual;
            }
        }
        printf("%d", maior);
    }
    fclose(fp);
}

int main(void) {
    char arq[50];
    crescentes("entrada.txt");
    return 0;
}