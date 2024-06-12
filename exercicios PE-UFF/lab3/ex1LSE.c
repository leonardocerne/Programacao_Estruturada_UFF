#include "TLSE.c"

void ins_antes_TLSE(TLSE *l, int n){
    TLSE *p = l, *aux;
    while(p){
      if(p->info == n){
        aux = p->prox;
        for(int i = 0; i < n; i++){
          TLSE *no = (TLSE*)malloc(sizeof(TLSE));
          no->info = n;
          p->prox = no;
          no->prox = aux;
          p = no;
        }
        p = aux;
      }
      else p = p->prox;
    }  
}

int main(void){
  TLSE *l = TLSE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLSE_ins_ini(l, x);
  }while(1);
  TLSE_imprime(l);
  printf("\n");

  scanf("%d", &x);
  ins_antes_TLSE(l, x);
  TLSE_imprime(l);
  printf("\n");
  TLSE_libera(l);  
  return 0;
}