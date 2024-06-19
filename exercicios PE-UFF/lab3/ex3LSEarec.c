#include "TLSE.c"

void mult_k1_rec(TLSE *l, int x){
    if(!l) return;
    if((l->info % x) == 0){
        if(l->prox){
            l->info = l->prox->info;
            TLSE *t = l->prox;
            l->prox = t->prox;
            free(t);
            mult_k1_rec(l, x);
        }
        else{
            free(l);
            return;
        }
    }
    else mult_k1_rec(l->prox, x);
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
  mult_k1_rec(l, k);
  TLSE_imprime(l);
  printf("\n");
  TLSE_libera(l);  
  return 0;
}