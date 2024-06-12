#include "TLC.c"

TLC* mult_k6(TLC *l, int k){
    TLC *p = l, *nova = NULL;
    if(p->info % k != 0) nova = TLC_ins_mais_facil(nova, p->info);
    p = p->prox;
    while(p != l){
        if(p->info % k != 0) nova = TLC_ins_mais_facil(nova, p->info);
        p = p->prox;
    }
    p = l;
    nova = nova->prox;
    inverte(nova);
    TLC_libera(p);
    return nova;
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
  l = mult_k6(l, k);
  TLC_imprime(l);
  printf("\n");
  TLC_libera(l);  
  return 0;
}