#include "TODAS.c"
#include <limits.h>

TP *merge(TP **vetp, int n){
    TP **copia = (TP **) malloc(sizeof(TP*) * n);
    TP *aux = TP_inicializa(), *aux2 = TP_inicializa(), *resp = TP_inicializa();
    int qnt = 0, maior = INT_MIN, x;
    for(int i = 0; i < n; i++){
        copia[i] = TP_inicializa();
        while(!TP_vazia(vetp[i])) {
            TP_push(copia[i], TP_pop(vetp[i]));
            qnt++;
        }
    }
    for(int j = 0; j < qnt; j++){
        for(int g = 0; g < n; g++){
            if(!TP_vazia(copia[g])) x = TP_pop(copia[g]);
            if(x > maior) maior = x;
            TP_push(aux, x);
        }
        while(!TP_vazia(aux)) TP_push(aux2, TP_pop(aux));
        for(int f = 0; f < n; f++){
            x = TP_pop(aux2);
            if(x != maior) TP_push(copia[f], x);
        }
        TP_push(resp, maior);
        maior = INT_MIN;
    }
    return resp;
}

int main(void){
    int n;
    printf("Digite o numero de pilhas... ");
    scanf("%d", &n);
    if(n <= 0) return 0;
    TP **vetp = (TP **) malloc(sizeof(TP*) * n);
    int i;
    for(i = 0; i < n; i++) vetp[i] = TP_inicializa();
    i = 0;
    while(i < n){
        printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha não receberá mais elementos...\n", i + 1);
        int ant;
        scanf("%d", &ant);
        TP_push(vetp[i], ant);
        while(1){
            int aux;
            scanf("%d", &aux);
            if(aux > ant) break;
            TP_push(vetp[i], aux);
            ant = aux;
        }
        i++;
    }
    TP *resp = merge(vetp, n);
    TP_imprime(resp);
    TP_libera(resp);
    for(i = 0; i < n; i++) TP_libera(vetp[i]);
    free(vetp);
    return 0;
}