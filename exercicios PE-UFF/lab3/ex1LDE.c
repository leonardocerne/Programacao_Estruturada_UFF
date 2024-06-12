#include "TLDE.c"

void ins_antes_TLDE(TLDE *l, int n){
    TLDE *p = l, *aux;
    while(p){
        if(p->info == n){
            aux = p->prox;
            for(int i = 0; i < n; i++){
                TLDE *no = (TLDE*)malloc(sizeof(TLDE));
                no->info = n;
                p->prox = no;
                no->ant = p;
                no->prox = aux;
                if(aux) aux->ant = no;
                p = no;
            }
            p = aux;
        }
        else p = p->prox;
    }
}

int main(void){
  TLDE *l = TLDE_inicializa();
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLDE_ins_ini(l, x);
  }while(1);
  TLDE_imprime(l);
  printf("\n");

  scanf("%d", &x);
  ins_antes_TLDE(l, x);
  TLDE_imprime(l);
  printf("\n");
  TLDE_libera(l);
  return 0;
}