#include "TLC.c"

void ins_antes_TLC(TLC *l, int n){
    TLC *p = l, *aux;
    if(p->info == n){
        aux = p->prox;
        for(int j = 0; j < n; j++){
            TLC *no = (TLC*)malloc(sizeof(TLC));
            no->info = n;
            p->prox = no;
            no->prox = aux;
            p = no;
        }
        p = aux;
    }
    p = p->prox;
    while((p) && (p != l)){
      if(p->info == n){
        aux = p->prox;
        for(int i = 0; i < n; i++){
          TLC *no = (TLC*)malloc(sizeof(TLC));
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
  TLC *l = TLC_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLC_ins_mais_facil(l, x);
  }while(1);
  TLC_imprime(l);
  printf("\n");

  scanf("%d", &x);
  ins_antes_TLC(l, x);
  TLC_imprime(l);
  printf("\n");
  
  TLC_libera(l);
  return 0;
}