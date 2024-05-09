#include <stdio.h>
#include <stdlib.h>
#include "mat.c"

int ePot(int n, int k) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n % k) return 0;
    return ePot(n/k, k);
}
int **had_aux(int n){
    if(n == 1) {
        int **resp = aloca(n, n);
        resp[0][0] = 1;
        return resp;
    }
    int **aux = had_aux(n/2), ir, jr, ia = -1, ja;
    int **resp = aloca(n, n);
    for(ir = 0; ir < n/2; ir++){
        ia++;
        ja = 0;
        for(jr = 0; jr < n/2;jr++) resp[ir][jr] = aux[ia][ja++];
    }   
    ia = -1;
    for(ir = 0; ir < n/2; ir++){
        ia++;
        ja = 0;
        for(jr = n/2; jr < n;jr++) resp[ir][jr] = aux[ia][ja++];
    } 
    ia = -1;
    for(ir = n/2; ir < n; ir++){
        ia++;
        ja = 0;
        for(jr = 0; jr < n/2;jr++) resp[ir][jr] = aux[ia][ja++];
    } 
    ia = -1;
    for(ir = n/2; ir < n; ir++){
        ia++;
        ja = 0;
        for(jr = n/2; jr < n;jr++) resp[ir][jr] = !aux[ia][ja++];
    }  
    libera(aux, n/2);
    return resp;
}
void had(int n){
    if(!ePot(n, 2)) return;
    int **mat = had_aux(n);
    mat_imp(mat, n, n);
    libera(mat, n);
}

int main(void) {
    int n;
    scanf("%d", &n);
    had(n);
    return 0;
}