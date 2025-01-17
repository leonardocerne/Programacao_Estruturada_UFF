#include "TODAS.c"

TP *radx(TP* p, int x){
    TP *aux = TP_inicializa(), *resp = TP_inicializa();
    // while(!TP_vazia(p)) TP_push(aux, TP_pop(p));
    // while(!TP_vazia(aux)){
    //    int y = TP_pop(aux);
    //    TP_push(p, y);
    //    if(y == x){
    //        if(!TP_vazia(resp)) TP_pop(resp);
    //        if(!TP_vazia(aux)) TP_push(p, TP_pop(aux));
    //   }                                                         Minha questão checava a pilha invertida e por isso dava errado
    //    else TP_push(resp, y);
    //}
    TP *respaux = TP_inicializa();
    while(!TP_vazia(p)){
        int y = TP_pop(p);
        TP_push(aux, y);
        if(y == x){
            if(!TP_vazia(resp)) TP_pop(resp);
            TP_push(resp, y);
            if(!TP_vazia(p)) TP_push(aux, TP_pop(p));
        }
        else TP_push(resp, y);
    }
    while(!TP_vazia(resp)) TP_push(respaux, TP_pop(resp));
    TP_libera(aux); TP_libera(resp);
    return respaux;
}

int main(void){
  printf("Digite os elementos da pilha… Quando for fornecido um número negativo, a pilha não receberá mais elementos…\n");
  TP *p = TP_inicializa();
  while(1){
    int aux;
    scanf("%d", &aux);
    if(aux < 0) break;
    TP_push(p, aux);
  }
  TP_imprime(p);
  printf("\n");
  int x;
  scanf("%d", &x);
  TP *resp = radx(p, x);
  TP_imprime(resp);
  TP_libera(resp);
  TP_libera(p);
  return 0;
}