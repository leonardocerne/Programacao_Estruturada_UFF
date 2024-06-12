#include "TLSE.c"

void mult_k1(TLSE *l, int k){
    TLSE *p = l, *ant = l, *tmp, *tmp2;
    int temp;
    while(p){
        if(p->info % k == 0){
            if(p != ant){
              ant->prox = p->prox;
              tmp = p;
              p = p->prox;
              free(tmp);
            }
            else{
              tmp = p->prox;
              p->info = tmp->info;
              p->prox = tmp->prox;
              free(tmp);
            }
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x, k;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_ins_ini(l, x);
  }while(1);
  TLSE_imprime(l);
  printf("\n");

  scanf("%d", &k);
  mult_k1(l, k);
  TLSE_imprime(l);
  printf("\n");
  TLSE_libera(l);  
  return 0;
}