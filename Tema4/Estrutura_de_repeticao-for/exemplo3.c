/* Uso de for com incrementos e decrementos diferentes

Embora o incremento em um loop for geralmente seja um simples incremento de 1, ele pode ser adaptado para diferentes necessidades. Por exemplo, podemos iterar de 10 em 10, veja! */

#include <stdio.h>
 
int main() 
{
    for (int i = 0; i <= 100; i += 10) {
        printf("%d\n", i);
    }
    /* Nesse caso, a variável i é incrementada em 10 a cada iteração, permitindo imprimir múltiplos de 10 de 0 a 100. */

     printf("\n"); // Adiciona uma linha em branco para separar as saídas dos exemplos

    /* Para fazer um decremento utilizando a estrutura de um loop for, você pode adaptar o exemplo fornecido acima para que a variável seja decrementada a cada iteração. Veja agora um exemplo em que a variável i é decrementada em 10 a cada iteração, começando de 100 e indo até 0. */

    for (int i = 100; i >= 0; i -= 10) {
        printf("%d\n", i);
    }
    return 0;
}



