#include "TODAS.c"
/*
int repetido(char *palavra, TLSEP *l){
    TLSEP *p = l;
    while(p){
        if(strcmp(palavra, p->pal) == 0) return 0;
        p = p->prox;
    }
    return 1;
}

TLSEP *ordena (char **palavras, int n){
    TLSEP *resp = NULL; int x = 0, menor = INT_MAX;
    char aux[31];
    for(int k = 0; k < n; k++){
        x = 0;
        for(int i = 0; i < n; i++){
            if(repetido(palavras[i], resp) == 1){
                for(int j = 0; j < n; j++) if(strcmp(palavras[i], palavras[j]) == 0) x++;
                if(x < menor) {
                    menor = x;
                    strcpy(aux, palavras[i]);                       
                }
            }
        }
        for(int m = 0; m < n; m++){
            if(strcmp(palavras[m], aux) == 0){
                if(resp){
                    if(strcmp(resp->pal, aux) == 0){
                        resp->linhas = TLSE_ins_fim(resp->linhas, m);
                        resp->num_vezes++;
                    }
                    else resp = TLSEP_ins_ini(resp, aux, m);
                }
                else resp = TLSEP_ins_ini(resp, aux, m);
            }
        }
        menor = INT_MAX;
    }
    return resp; 
};

Na minha resolução, eu tentei ordenar a lista usando o algoritmo da torre de hanói, porém não funciona

*/

int compara(const void *x, const void *y){
    TLSEP **a = (TLSEP**)x, **b = (TLSEP**)y;
    TLSEP *px = *a, *py = *b;
    if(px->num_vezes > py->num_vezes) return -1;
    if(px->num_vezes < py->num_vezes) return 1;
    if(strcmp(px->pal, py->pal) > 0) return 1;
    if(strcmp(px->pal, py->pal) < 0) return -1;
}

TLSEP *ordena (char **palavras, int n){
    TLSEP *resp = NULL; int tam = 0;
    for(int i = 0; i < n; i++){
        TLSEP *ver = TLSEP_busca(resp, palavras[i]);
        if(!ver) {
            resp = TLSEP_ins_ini(resp, palavras[i], i);
            tam++;
        }
        else{
            ver->num_vezes++;
            ver->linhas = TLSE_ins_fim(ver->linhas, i);
        }
    }
    TLSEP **vet = (TLSEP**)malloc(sizeof(TLSEP*) * tam);
    for(int j = 0; j < tam; j++){
        vet[j] = resp;
        resp = resp->prox;
    }
    qsort(vet, tam, sizeof(TLSEP*), compara);
    for(int k = 0; k < tam; k++){
        if(k < tam-1) vet[k]->prox = vet[k+1];
    }
    vet[tam - 1]->prox = NULL;
    TLSEP *l = vet[0];
    free(vet);
    return l;
}

int main(){
    int n;
    scanf("%d", &n);
    char **pal = (char**)malloc(sizeof(char*) * n);
    for(int j = 0; j < n; j++) pal[j] = (char*)malloc(sizeof(char) * 31);
    for(int i = 0; i < n; i++) scanf("%s", pal[i]);
    for(int m = 0; m < n; m++) printf("\n%s\n", pal[m]);
    printf("Depois de ordena...\n");
    TLSEP *l = NULL;
    l = ordena(pal, n);
    TLSEP_imprime(l);
    TLSEP_libera(l);
    for(int f = 0; f < n; f++) free(pal[f]);
    free(pal);
    return 0;
}