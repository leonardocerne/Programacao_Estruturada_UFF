#include <stdio.h>
#include <stdlib.h>

int **aloca(int lin, int col){
  int **resp = (int **) malloc(sizeof(int *) * lin), i;
  for(i = 0; i < lin; i++)
  resp[i] = (int *) malloc(sizeof(int) * col);
  return resp; 
}

void desaloca(int **mat, int lin){
  int i;
  for(i = 0; i < lin; i++) free(mat[i]);
  free(mat);
}

void imprime(int **mat, int nl, int nc){
  int i, j;
  for(i = 0; i < nl; i++){
    for(j = 0; j < nc; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }
}

int aux(int **mat, int lin, int col, int x){
    if(mat[lin][col] == x)return col;
    if(col<0)return -1;
    return aux(mat, lin, col-1, x);
}

void busca_elem(int **mat, int num_lin, int num_col, int x, int *pos_x_lin, int *pos_x_col){
    int y = num_lin - 1;
    if(y < 0){
        *pos_x_lin = -1;
        *pos_x_col = -1;
        return;
    }
    // if(aux(mat, y, num_col, x) != -1){     mudei essa linha do meu código, ao invés de num_col - 1, passei num_col
    if(aux(mat, y, num_col - 1, x) != -1){                  
        *pos_x_lin = y;
        *pos_x_col = aux(mat, y, num_col, x);
        return;
    }
    else{
        busca_elem(mat, num_lin - 1, num_col, x, pos_x_lin, pos_x_col);
    }
}

int main(void){
  int lin, col;
  scanf("%d%d", &lin, &col);
  if((lin <= 0) && (col <= 0)) return 0;

  int **mat = aloca(lin, col), i = 0, j = 0, aux, vet[lin * col], ind = 0;
  while(1){
    scanf("%d", &aux);
    //garante ordem crescente na linha...
    if((j > 0) && (mat[i][j - 1] >= aux)) continue;
    //garante ordem crescente na coluna...
    if((i > 0) && (mat[i - 1][j] >= aux)) continue;
    int k;
    //proibe repeticoes...
    for(k = 0; k < ind; k++)
      if(vet[k] == aux) break;
    if(k < ind) continue;
    //todas as condicoes estao satisfeitas: insere na matriz...
    vet[ind++] = aux;
    mat[i][j++] = aux;
    if(j == col){
      j = 0;
      i++;
      if(i == lin) break;
    }
  }
    
  imprime(mat, lin, col);
  int elem, pos_lin, pos_col; 
  printf("Digite o elemento a ser procurado... ");
  scanf("%d", &elem);
  busca_elem(mat, lin, col, elem, &pos_lin, &pos_col);
  printf("O elemento %d esta em mat[%d][%d]\n", elem, pos_lin, pos_col);
  desaloca(mat, lin);
  return 0; 
}