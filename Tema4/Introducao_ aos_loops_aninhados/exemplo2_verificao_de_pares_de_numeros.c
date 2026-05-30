/* Considere verificar todos os pares de números em um intervalo e imprimir apenas os pares em que a soma é par. O objetivo é imprimir os pares de números (i, j) em que a soma i + j é par, dentro do intervalo de 1 a 5. As partes mais importantes são: */

#include <stdio.h>
int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if ((i + j) % 2 == 0) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
    return 0;
}