#include <stdio.h>
 
int main() {

    /* Veja agora o loop for sendo usado para imprimir todos os números pares de 1 a 20. */

    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    /* Nesse caso, a condição if (i % 2 == 0) verifica se i é par. Se for, o valor de i é impresso. */
   
    return 0;
}