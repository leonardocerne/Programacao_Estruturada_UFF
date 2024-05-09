#include <stdio.h>
#include <stdlib.h>
 
int* ins_antes_depois_x(int *vet, int n, int x, int *tam_vet_resposta) {
    int q = 0;
    for(int i = 0; i < n; i++) if (vet[i] == x) q++;
    *tam_vet_resposta = n + (q * 2);
    int *nova = (int*)malloc(sizeof(int)*(*tam_vet_resposta));
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] == x) {
            nova[l] = x - 1;
            nova[l + 1] = x;
            nova[l + 2] = x + 1;
            l += 3;
        }
        else {
            nova[l] = vet[i];
            l += 1;
        }
    }
    return nova;
}
int main(void){
   int n;
  do{
    scanf("%d", &n);
    if(n > 0)break;
  }while(1);
  int vet[n], i, x, tam_vet2;
  for(i = 0; i < n; i++)scanf("%d", &vet[i]);
  scanf("%d", &x);
  for(i = 0; i < n; i++)printf("%d\n", vet[i]);
  int *resp = ins_antes_depois_x(vet, n, x, &tam_vet2);
  for(i = 0; i < tam_vet2; i++) printf("%d\n", resp[i]);
  free(resp);
  return 0;
}