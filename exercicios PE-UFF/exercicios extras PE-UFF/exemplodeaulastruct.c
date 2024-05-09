#include "TALUNO.c"

int main(void){
    int n;
    do{
        scanf("%d", &n);
    } while(n <= 0);
    TALUNO **vet = TA_aloca(n);           // ponteiro de ponteiros pra TALUNO alocado dinamicamente
    TA_leit(vet, n);
    TA_imp(vet, n);
    ordena_TA(vet, n);
    TA_imp(vet, n);
    TA_libera(vet, n);
    return 0;
}  