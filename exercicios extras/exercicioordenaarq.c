#include <stdio.h>
#include <stdlib.h>

void ordenarq(char *arq1, char *arq2, char *arqout) {
    FILE *fp1 = fopen(arq1, "r"), *fp2 = fopen(arq2, "r"), *fpout = fopen(arqout, "w");
    if ((!fp1) || (!fp2) || (!fpout)) exit(1);
    int num1, num2;
    int r = fscanf(fp1, "%d", &num1);
    int g = fscanf(fp2, "%d", &num2);
    if((r != 1) || (g != 1)) exit(1);
    while((r == 1) || (g == 1)) {
        if((r == 1) && (g == 1)) {
            if(num1 < num2) {
                fprintf(fpout, "%d ", num1);
                r = fscanf(fp1, "%d", &num1);
            }
            else{
                fprintf(fpout, "%d ", num2);
                g = fscanf(fp2, "%d", &num2);
            }
        }
        else if(r == 1){
            fprintf(fpout, "%d ", num1);
            r = fscanf(fp1, "%d", &num1);
        }
        else {
            fprintf(fpout, "%d ", num2);
            g = fscanf(fp2, "%d", &num2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fpout);
}

int main(void) {
    char arq1[50], arq2[50], arqout[50];
    ordenarq("entrada1.txt", "entrada2.txt", "saida.txt");
    return 0;
}