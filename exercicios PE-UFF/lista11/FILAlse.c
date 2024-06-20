#include "TLSE.c"
#include "FILA.h"

struct fila{
	TLSE *ini;
	TLSE *fim;
};

TF *TF_inicializa(void){
	TF *f = (TF *)malloc(sizeof(TF));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int TF_vazia(TF *f){
	return !(f->ini); // 1 se vazia , 0 caso contrário
}

void TF_insere(TF *f, int elem){
	TLSE *novo = (TLSE *)malloc(sizeof(TLSE));
	novo->info = elem;
	novo->prox = NULL; // INSERÇÃO NO FIM
	if (!TF_vazia(f))f->fim->prox = novo;
	else f->ini = novo;
	f->fim = novo;
}
	
int TF_retira(TF *f){
	if (TF_vazia(f)) exit(1);

	int resp = f->ini->info;

	TLSE *q = f->ini;
	f->ini=f->ini->prox;
	if (!f->ini) // esvaziou a fila
		f->fim = NULL;
	free(q);
	return resp;
}

void TF_libera(TF *f){
	TLSE *q, *p = f->ini;
	while(p){
		q = p;
		p = p->prox;
		free(q);
	}
	free(f);
}

void TF_imprime(TF *f){
 	TF *aux = TF_inicializa();
	while (!TF_vazia(f)){
		int x = TF_retira(f);
		printf("%d ",x);
		TF_insere(aux,x);
	}
	while(!TF_vazia(aux)) TF_insere(f, TF_retira(aux));
	TF_libera(aux);
}

void imp(TF *f){
    if(TF_vazia(f)) return;
    TF *aux = TF_cria();
    while(!TF_vazia(f)){
        int x = TF_retira(f);
        printf("%d\n", x);
        TF_insere(aux, x);
    }
    while(!TF_vazia(aux)) TF_insere(f, TF_retira(aux));
    TF_libera(aux);
}

void imp_rev(TF *f){
    if(TF_vazia(f)) return;
    TP *p1 = TP_cria(), *p2 = TP_cria();
    while(!TF_vazia(f)) TP_push(p1, TF_retira(f));
    while(!TP_vazia(p1)){
        int x = TP_pop(p1);
        printf("%d\n", x);
        TP_push(p2, x);
    }
    while(!TP_vazia(p2)) TF_insere(f, TP_pop(p2));
    TP_libera(p1);
    TP_libera(p2);
}
