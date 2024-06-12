#include "TLSE.c"

void troca_rec_aux(TLSE *l, int N1, int N2){
    if(!l) return;
    TLSE *p = l;
    int tmp;
    if(l->info == N1){
        while((p) && (p->info != N2)) p = p->prox;
        if(p->info == N2){
            tmp = p->info;
            p->info = l->info;
            l->info = tmp;
            l->info *= -1; p->info *= -1;
        }   
    }
    if(l->info == N2){
        while((p) && (p->info != N1)) p = p->prox;
        if(p->info == N1){
            tmp = p->info;
            p->info = l->info;
            l->info = tmp;
            l->info *= -1; p->info *= -1;
        }   
    }
    return troca_rec_aux(l->prox, N1, N2);
}
void troca_rec(TLSE *l, int N1, int N2){
    if(!l) return;
    troca_rec_aux(l, N1, N2);
    TLSE *p = l;
    while(p){
        if(p->info < 0) p->info *= -1;
        p = p->prox;
    }
}
int main(void){
    TLSE *l = TLSE_inicializa();
    int x, n1, n2;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d%d", &n1, &n2);
    troca_rec(l, n1, n2);
    TLSE_imprime(l);
    printf("\n");
    TLSE_libera(l);  
    return 0;
}