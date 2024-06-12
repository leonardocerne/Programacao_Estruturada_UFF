#include "TLSE.c"

int misc_aux(TLSE *l, int i){
    if(!l) return 1;
    if(i % 2 == 0){
        if(l->info % 2 != 0) return 0;
    }
    else{
        if(l->info % 2 == 0) return 0;
    }
    return misc_aux(l->prox, i + 1);
}

int misc(TLSE *l){
    if(!l) return 0;
    int x = misc_aux(l, 1);
    return x;
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
  int resp = misc(l);
  if(resp == 1) printf("ta certo");
  else printf("ta errado");
  printf("\n");
  TLSE_libera(l);  
  return 0;
}
