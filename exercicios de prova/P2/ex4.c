#include "TLSE.c"

TLSE* com_elem(TLSE* l1, TLSE* l2){
    //if((!l1) || (!l2)) return resp;
    //if(l1->info < l2->info) return com_elem(l1->prox, l2);
    //if(l2->info < l1->info) return com_elem(l1, l2->prox);      Meu código dava errado porque eu criava uma resp, sendo que não precisava,
    //if(l2->info == l1->info){                                   era só inserir na própria chamada recursiva
    //    TLSE *resp = TLSE_insere(resp, l1->info);
    //    return com_elem(l1->prox, l2->prox);
    //}
    if((!l1) || (!l2)) return NULL;
    if(l1->info < l2->info) return com_elem(l1->prox, l2);
    if(l2->info < l1->info) return com_elem(l1, l2->prox);
    if(l2->info == l1->info) return TLSE_insere(com_elem(l1->prox, l2->prox), l1->info);
}

int main(void){
  TLSE *l1 = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l1 = TLSE_insere(l1, n);
  }while(1);
  TLSE_imprime(l1);
  printf("\n");
    
  TLSE *l2 = NULL;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l2 = TLSE_insere(l2, n);
  }while(1);
  TLSE_imprime(l2);
  printf("\n");
  TLSE *comum = com_elem(l1, l2);
  TLSE_imprime(comum);
  printf("\n");
  TLSE_libera(comum);

  TLSE_imprime(l1);
  printf("\n");
  TLSE_imprime(l2);
  printf("\n");
  TLSE_libera(l1);
  TLSE_libera(l2);
  
  return 0;
}