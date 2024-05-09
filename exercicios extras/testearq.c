#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(char *narq1, char *narq2, char *ns) {
        FILE *fp1 = fopen(narq1, "r"), *fp2 = fopen(narq2, "r"), *fps = fopen(ns, "w");
        if ((!fp1) || (!fp2) || (!fps)) exit(1);
        int r1, r2, n1, n2;
        r1 = fscanf(fp1, "%d", &n1);    // retorna 1 se foi lido com sucesso
        r2 = fscanf(fp2, "%d", &n2);
        while((r1==1) && (r2==1)){ //confirma que leu dois elementos validos
            if (n1<n2){
                fprintf(fps, "%d\n", n1);
                r1 = fscanf(fp1, "%d", n1);       
            }
            else {
                fprintf(fps, "%d\n", n2);
                if (n1==n2) {
                    r1 = fscanf(fp1, "%d", &n1);
                    r2 = fscanf(fp2, "%d", &n2);
                }
            }
        }
        while(r1==1){
            fprintf(fps, "%d\n", n1);
            r1 = fscanf(fp1, "%d", &n1);
        }
        while(r2==1){
            fprintf(fps, "%d\n", n2);
            r2 = fscanf(fp2, "%d", &n2);
        }
        fclose(fp1);
        fclose(fp1);
        fclose(fps);
    }

int main(int argc, char **argv){
    if (argc != 4) printf("ERRO");
    else{
        merge(argv[1], argv[2], argv[3]);
    }
    return 0;
}