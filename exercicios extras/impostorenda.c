#include <stdio.h>

int main() {
    float valor, desconto, valorfim;
    scanf("%f", &valor);
    if (valor < 1499.15) {
        printf("Não tem desconto");
    }
    else if (1499.15 <= valor && valor <= 2246.75) {
        desconto = ((7.5 / 100.0) * valor) - 112.44;
    }
    else if (2246.76 <= valor && valor <= 2995.7) {
        desconto = ((15.0 / 100.0) * valor) - 280.94;
    }
    else if (2995.71 <= valor && valor <= 3743.19) {
        desconto = ((22.5 / 100.0) * valor) - 505.62;
    }
    else {
        desconto = ((27.5 / 100.0) * valor) - 692.78;
    }
    valorfim = valor - desconto;
    printf("O valor fica %.2f", valorfim);
    return 0;
}