#include <stdio.h>
#include "TLC.c"

TLC *rec(TLC *l, int n, TLC *primeiro){
    if(l == primeiro) return l;
    if(l -> info == n){
        TLC *proximo = l -> prox;
        for(int i = 0; i < n; i++){
            TLC *novo = (TLC*)malloc(sizeof(TLC));
            l -> prox = novo;
            novo -> prox = proximo;
            novo -> info = n;
            l = novo;
        }
        rec(proximo, n, primeiro);
    }else rec(l -> prox, n, primeiro);
}

TLC *ins_antes_TLC(TLC *l, int N){
    TLC *p = l;

    // verificar o primeiro caso
    if(p -> info == N){
        TLC *proximo = l -> prox;
        for(int i = 0; i < N; i++){
            TLC *novo = (TLC*)malloc(sizeof(TLC));
            p -> prox = novo;
            novo -> prox = proximo;
            novo -> info = N;
            p = novo;
        }
        p = proximo;
    }else{
        p = p -> prox;
    }

    p = rec(p, N, l);
    return l;
}

int main(){
    TLC *l = NULL;
    int e;
    do{
        scanf("%d", &e);
        if(e<0)break;
        TLC_ins_mais_facil(l, e);
    }while(1);

    printf("\n");
    int n;
    scanf("%d", &n);
    l = ins_antes_TLC(l, n);
    TLC_imprime(l);
    TLC_libera(l);
    return 1;
}