#include <stdio.h>

int main(void){
  int a, b, *pi;
  double c, d, *pf;
  char e, f, *pc;
  pi = &a;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\t", a, &a, b, &b, pi, &pi);
  printf("c = %f(%p)\td = %f(%p)\tpf = %p(%p)\t", c, &c, d, &d, pf, &pf);
  printf("e = %c(%p)\tf = %c(%p)\tpc = %p(%p)\n", e, &e, f, &f, pc, &pc);
  a = 1;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  (*pi) += 5;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  b = 3;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  (*pi) = a + b;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  pi--;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);  
  printf("%d\n", (*pi));
  (*pi) = 5;
  printf("%d\n", (*pi));
  pi++;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  pi++;
  printf("a = %d(%p)\tb = %d(%p)\tpi = %p(%p)\n", a, &a, b, &b, pi, &pi);
  return 0;
}