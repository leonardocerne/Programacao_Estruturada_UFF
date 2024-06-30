#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definindo a struct
typedef  struct paciente{
    char nome[11];
    char data_nasc[9];
    int insc;
} TP;

int compara(const void *a, const void *b){
    TP **pa = (TP**)a;
    TP **pb = (TP**)b;
    TP *pac_a = (*pa), *pac_b = (*pb);
    if(strcmp(&pac_a->data_nasc[4], &pac_b->data_nasc[4]) > 0) return 1;
    if(strcmp(&pac_a->data_nasc[4], &pac_b->data_nasc[4]) < 0) return -1;
    if(strcmp(&pac_a->data_nasc[2], &pac_b->data_nasc[2]) > 0) return 1;
    if(strcmp(&pac_a->data_nasc[2], &pac_b->data_nasc[2]) < 0) return -1;
    if(strcmp(pac_a->data_nasc, pac_b->data_nasc) > 0) return 1;
    if(strcmp(pac_a->data_nasc, pac_b->data_nasc) < 0) return -1;
    if(strcmp(pac_a->nome, pac_b->nome) > 0) return 1;
    if(strcmp(pac_a->nome, pac_b->nome) < 0) return -1;
    if(pac_a->insc > pac_b->insc) return 1;
    return -1;
}
TP *retira_k(TP **vet,int k, int n){
    TP **vetcopia = (TP**)malloc(sizeof(TP*) * n);
    for(int i = 0; i < n; i++){
        vetcopia[i] = (TP*)malloc(sizeof(TP));
        strcpy(vetcopia[i]->data_nasc, vet[i]->data_nasc);
        strcpy(vetcopia[i]->nome, vet[i]->nome);
        vetcopia[i]->insc = vet[i]->insc;
    }
    qsort(vetcopia, n, sizeof(TP*), compara);
    TP *resp = (TP*)malloc(sizeof(TP));
    strcpy(resp->data_nasc, vetcopia[k - 1]->data_nasc);
    strcpy(resp->nome, vetcopia[k - 1]->nome);
    resp->insc = vetcopia[k - 1]->insc;
    for(int j = 0; j < n; j++){
        if(vet[j]->insc == vetcopia[k - 1]->insc){
            free(vet[j]);
            vet[j] = NULL;
        }
    }
    for(int t = 0; t < n; t++){
        free(vetcopia[t]);
    }
    free(vetcopia);
    return resp;
}

int main(void){
    //Inicializando e recebendo as variáveis que serão usadas
    int n, k;
    printf("Digite a quantidade de pacientes: ");
    scanf("%d", &n);

    printf("Digite o k-esimo paciente que deseja vacinar: ");
    scanf("%d", &k);

    //Criando o vetor que será preenchido com os ponteiros de structs
    TP **vet = (TP**)malloc(sizeof(TP*)*n);

    //Criando cada ponteiro e preenchendo as suas structs respectivas
    for(int i = 0; i < n; i++){
        vet[i] = (TP*)malloc(sizeof(TP));
        printf("Digite o nome do paciente %d: ", i);
        scanf("%s", vet[i]->nome);

        printf("Digite a data de nascimento(ddmmaaaa) do paciente %d: ", i);
        scanf("%s", vet[i]->data_nasc);

        printf("Digite o numero de insc do paciente %d: ", i);
        scanf("%d", &vet[i]->insc);

        printf("\n");
    }

    //Com o banco de dados feito, vamos chamar a função para pegar o k-ésimo paciente ordenado
    TP * paciente_k = retira_k(vet,k,n);

    //Printando o paciente_k que será vacinado    
    printf("O paciente %d eh o: %s, nascido em: %s, com numero de ins: %d ",k,paciente_k->nome,paciente_k->data_nasc,paciente_k->insc);

    //Vamos desalocar os vetores utilizados
    for(int i = 0; i < n; i++){
        free(vet[i]);
    }
    free(vet);

    return 0;
}
