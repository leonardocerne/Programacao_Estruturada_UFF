#include "TLSE.c"

int misc (TLSE *l){
    int i = 1;
    TLSE *p = l;
    while(p){
        if(i % 2 == 0){
            if(p->info % 2 != 0) return 0;
        }
        else{
            if(p->info % 2 == 0) return 0;
        }
        p = p->prox;
        i++;
    }
    return 1;
}

int main(void){
  
  
}