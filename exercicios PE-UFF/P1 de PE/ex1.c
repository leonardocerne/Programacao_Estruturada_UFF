/*
A questão passava um arquivo de entrada e um vetor preenchido com as palavras que aparecem no arquivo,
e pedia que ordenassemos o vetor conforme o numero de vezes que cada palavra aparecia no arquivo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **ordstr(char *arq_ent, char **lista_str, int n) {
    FILE *fp = fopen(arq_ent, "r");
    char palavra[50];
    int *vet = (int*)malloc(sizeof(int) * n), r, i;
    for(int j = 0; j < n; j++) vet[j] = 0;
    while (fscanf(fp, "%s", palavra) == 1) {
        for (int i = 0; i < n; i++) {
            if (strcmp(palavra, lista_str[i]) == 0) vet[i]++;
        }
    }
    for (int t = 0; t < n; t++){
        int menor = t;
        for(int l = t + 1; l < n; l++){        // ordena o vetor usando selection sort
            if(vet[menor] < vet[l])
                menor = l;
        }
        if(t != menor) {
            int tmp = vet[t];
            vet[t] = vet[menor];
            vet[menor] = tmp;   
            char *temp_str = lista_str[t];
            lista_str[t] = lista_str[menor];
            lista_str[menor] = temp_str;
        }      
    }
    for(int o = 0; o < n-1; o++){
        if(vet[o] == vet[o + 1]){
            if(strcmp(lista_str[o], lista_str[o + 1]) > 0) {
                char *temp_str = lista_str[o];
                lista_str[o] = lista_str[o + 1];
                lista_str[o + 1] = temp_str;
            }
        }
    }
    free(vet);
    fclose(fp);
    return lista_str;
} 

int main(void) {
    int n;
    printf("Insira quantas strings tera na lista: ");
    scanf("%d", &n);
    char **lista_str = (char**)malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++) lista_str[i] = (char*)malloc(sizeof(char) * 30);
    for(int j = 0; j < n; j++) scanf("%s", lista_str[j]);
    lista_str = ordstr("entrada.txt", lista_str, n);
    for(int m = 0; m < n; m++) printf("%s ", lista_str[m]);
    for(int k = 0; k < n; k++) free(lista_str[k]);
    free(lista_str);
    return 0;
}   
