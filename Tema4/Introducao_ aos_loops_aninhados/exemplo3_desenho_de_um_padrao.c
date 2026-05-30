/* Esse código imprime um triângulo de asteriscos, no qual o número de asteriscos em cada linha aumenta progressivamente de acordo com a altura especificada que, nesse caso, é 5. */
#include <stdio.h>

int main() {
    int n = 5; // altura do triângulo
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}