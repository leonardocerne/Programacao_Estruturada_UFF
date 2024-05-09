#include <stdio.h>

int main(void) {
    int n, ant, atual;
    scanf("%d", &n);
    scanf("%d", &ant);
    int cont = 1;
    int maior = cont;
    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &atual);
        if(atual > ant) cont ++;
        else cont = 1;
        ant = atual;
        if (cont > maior) maior = cont;
    }
    printf("%d", maior);
    return 0;
}