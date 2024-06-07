#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_intdec(const void *x, const void *y) { 
        int *px = (int *)x, *py = (int *)y;
        if ((*px) > (*py)) return -1;           
        if ((*px) < (*py)) return 1;
        return 0;               
}
void ordena(char *nome_arq_texto, char **palavras, int n){
    FILE *fp = fopen(nome_arq_texto, "r");
    char ant[50], atu[50];
    int *vet = (int*)malloc(sizeof(int) * n); // atu;
    if(!fp) exit(1);
    for(int c = 0; c < n; c++) vet[c] = 0;
    int r = fscanf(fp, "%s", ant);
    if(r == 1)
        for(int i = 0; i < n; i++)
            if(strcmp(ant, palavras[i]) == 0) vet[i]++;
    while(r == 1){
        r = fscanf(fp, "%s", ant);
        if(r == 1){
            for(int j = 0; j < n; j++){
                if(strcmp(ant, palavras[j]) == 0) vet[j]++;
            }
        }
    }
    // int *vet2 = (int*)malloc(sizeof(int) * n);     
    // for(int l = 0; l < n; l++) vet2[l] = vet[l];
    // qsort(vet2, n, sizeof(int), cmp_intdec);
    // char **aux = (char **)malloc(sizeof(char*) * n);
    // for(int y = 0; y < n; y++) aux[y] = (char *)malloc(sizeof(char) * 30);
    // for(int h = 0; h < n; h++) strcpy(aux[h], palavras[h]);                       meu codigo funciona mas dá erro quando as strings aparecem
    // for(int s = 0; s < n; s++){                                                   a mesma quantidade de vezes, porque não ordena em ordem alfabética
    //    atu = vet2[s];    
    //    for(int z = 0; z < n; z++){
    //        if(atu == vet[z]){
    //            strcpy(palavras[s], aux[s]);
    //            vet[z] = -1;
    //        }
    //    }
    // }
    for (int t = 0; t < n; t++){
        int menor = t;
        for(int l = t + 1; l < n; l++){        // ordena o vetor usando selection sort, e faz as trocas no vetor de palavras junto
            if(vet[menor] < vet[l])
                menor = l;
        }
        if(t != menor) {
            int tmp = vet[t];
            vet[t] = vet[menor];
            vet[menor] = tmp;   
            char *temp_str = palavras[t];
            palavras[t] = palavras[menor];
            palavras[menor] = temp_str;
        }      
    }
    for(int o = 0; o < n-1; o++){
        if(vet[o] == vet[o + 1]){
            if(strcmp(palavras[o], palavras[o + 1]) > 0) {          // ordena as palavras com o mesmo numero de aparições por ordem alfabética
                char *temp_str = palavras[o];
                palavras[o] = palavras[o + 1];
                palavras[o + 1] = temp_str;
            }
        }
    }
    fclose(fp);
    free(vet);
    // free(vet2);
    // for(int p = 0; p < n; p++) free(aux[p]);
    // free(aux);
}

int main(int argc, char **argv){
  if(argc == 1) printf("ERRO: <./nome_exec> <arq_texto> <palavras a serem pesquisadas separadas por espacos em branco\n");
  else{
    int n = argc - 2, i;
    char **pal = (char **)malloc(sizeof(char *) * n);
    for(i = 0; i < n; i++){
      pal[i] = (char *) malloc(sizeof(char) * 31);
      strcpy(pal[i], argv[i + 2]);
    }
    ordena(argv[1], pal, n);
    printf("Depois de ordena...\n");
    for(i = 0; i < n; i++){
      printf("pal[%d] = %s\n", i, pal[i]);
      free(pal[i]);
    }
    free(pal);
  }
  return 0;
}