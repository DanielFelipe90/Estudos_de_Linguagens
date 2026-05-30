#include <stdio.h>

int main() {
    int numero = 10;
    float resultado = 10.0;

    int comparacao = (float)numero == resultado;

    printf("numero == resultado: %d\n", comparacao);
    /* A comparação entre num e result retorna 1, indicando que são iguais após a conversão explícita de num para float. */
    
    return 0;
}