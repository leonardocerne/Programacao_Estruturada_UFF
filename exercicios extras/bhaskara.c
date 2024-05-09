#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    printf("Informe o a, b e c da sua formula de bhaskara: ");
    scanf("%f %f %f", &a, &b, &c);
    float delta = (b * b) - (4 * a * c);
    float r1 = (-b + sqrt(delta)) / (2 * a);
    float r2 = (-b - sqrt(delta)) / (2 * a);
    if (delta < 0) {
        printf("Nao tem raizes");
    }
    else {
        printf("As raizes sao %.0f e %.0f", r1, r2);
    }
    return 0;
}