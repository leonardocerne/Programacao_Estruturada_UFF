#include <stdio.h>
#include <stdlib.h>

void retira_mult_k(int *vet, int *novo_tam_vet, int k){
    for (int i = 0; i < *novo_tam_vet; i++) {
        if (vet[i] % k == 0) {
            for (int j = i; j < *novo_tam_vet; j++) {
                vet[j] = vet[j + 1];
            }
            (*novo_tam_vet)--;
            i--;
        }
    }
}

int main(void){
  int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);
  int vet[n], i, k;
  for(i = 0; i < n; i++)scanf("%d", &vet[i]);
  scanf("%d", &k);
  retira_mult_k(vet, &n, k);
  for(i = 0; i < n; i++) printf("%d\n", vet[i]);
  return 0;
}
