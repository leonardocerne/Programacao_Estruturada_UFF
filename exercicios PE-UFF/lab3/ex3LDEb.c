#include "TLDE.c"

TLDE *mult_k4(TLDE *l, int k){
    TLDE *nova = NULL, *p = l;
    while(p){
        if(p->info % k != 0) nova = TLDE_ins_ini(nova, p->info);
        p = p->prox;
    }
    inverte(nova);
    p = l;
    TLDE_libera(p);
    return nova;
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
  l = mult_k4(l, k);
  TLDE_imprime(l);
  printf("\n");
  TLDE_libera(l);  
  return 0;
}