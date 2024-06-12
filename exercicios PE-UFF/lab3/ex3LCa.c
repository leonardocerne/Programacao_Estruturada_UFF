#include "TLC.c"

void mult_k5(TLC *l, int k){
    TLC *p = l, *tmp, *ant = p;
    if(p->info % k == 0){
        p->info = p->prox->info;
        tmp = p->prox;
        p->prox = tmp->prox;
        free(tmp);
    }
    else p = p->prox;
    while((p) && (p != l)){
        if(p->info % k == 0){
            ant->prox = p->prox;
            tmp = p;
            p = p->prox;
            free(tmp);
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
}

int main(void){
  TLC *l = TLC_inicializa();
  int x, k;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLC_ins_mais_facil(l, x);
  }while(1);
  TLC_imprime(l);
  printf("\n");

  scanf("%d", &k);
  mult_k5(l, k);
  TLC_imprime(l);
  printf("\n");
  TLC_libera(l);  
  return 0;
}