// esse exercício consiste em inserir de 1 até n - 1 antes e depois de cada n na lista


#include "TLSE.c"

void insere_cres_ad(TLSE *l, int n){
    TLSE *p = l, *aux, *aux2;
    while(p){
        if(p->info == n){
            aux = p->prox;
            aux2 = p;
            for(int i = 0; i < n - 1; i++){
                TLSE *no = (TLSE*)malloc(sizeof(TLSE));
                no->info = i + 2;
                p->prox = no;
                no->prox = aux;
                p = no;
            }
            for(int j = 1; j < n; j++){
                TLSE *no = (TLSE*)malloc(sizeof(TLSE));
                no->info = j;
                p->prox = no;
                no->prox = aux;
                p = no;
            }
            p = aux;
            aux2->info = 1;
        }
        else p = p->prox;
    }
}
int main(void){
    TLSE *l = TLSE_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d", &n);
    insere_cres_ad(l, n);
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;
}