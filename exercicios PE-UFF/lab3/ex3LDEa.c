#include "TLDE.c"

void mult_k3(TLDE *l, int k){
    TLDE *p = l, *tmp;
    int temp;
    while(p){
        if(p->info % k == 0){
            if(p->ant){
                p->ant->prox = p->prox;
                if(p->prox) p->prox->ant = p->ant;
                tmp = p;
                p = p->prox;
                free(tmp);
            }
            else{
                tmp = p->prox;
                temp = p->info;
                p->info = tmp->info;
                tmp->info = temp;
                tmp->ant->prox = tmp->prox;
                tmp->prox->ant = tmp->ant;
                free(tmp);
            }
        }
        else p = p->prox;
    }
}

int main(void){
  TLDE *l = TLDE_inicializa();
  int x, k;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLDE_ins_ini(l, x);
  }while(1);
  TLDE_imprime(l);
  printf("\n");

  scanf("%d", &k);
  mult_k3(l, k);
  TLDE_imprime(l);
  printf("\n");
  TLDE_libera(l);  
  return 0;
}