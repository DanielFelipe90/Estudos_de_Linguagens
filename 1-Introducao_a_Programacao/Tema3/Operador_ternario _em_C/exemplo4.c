#include <stdio.h>

int main() {
    int num1 = 40, num2 = 60;
    int maior;

    num1 > num2 ? (maior = num1) : (maior = num2);/* Operador ternário significa a mesma coisa que if e else, simplificando o código. */

    if (num1 > num2) {
        printf("O numero maior é %d\n", num1);
    } else {
        printf("O numero maior é %d\n", num2);
    }

    printf("O maior numero é: %d\n", maior);

    return 0;
}