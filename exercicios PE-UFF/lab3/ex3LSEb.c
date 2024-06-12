#include "TLSE.c"

TLSE *mult_k2(TLSE *l, int k){
    TLSE *nova = NULL, *p = l;
    while(p){
        if(p->info % k != 0) nova = TLSE_ins_ini(nova, p->info);
        p = p->prox;
    }
    inverte(nova);
    p = l;
    TLSE_libera(p);
    return nova;
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
  l = mult_k1(l, k);
  TLSE_imprime(l);
  printf("\n");
  TLSE_libera(l);  
  return 0;
}