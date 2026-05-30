/* Nesse exemplo, o código faz uma contagem regressiva de 10 até 0, simulando fogos de artifício. Um loop aninhado é utilizado para criar um pequeno atraso entre cada contagem, dando a sensação de suspense antes dos fogos de artifício. */

#include <stdio.h>
 
int main() {
    int segundos;
   
    for (segundos = 10; segundos >= 0; segundos--) {
        printf("%d\n", segundos);
       
        // Loop aninhado para simular um atraso
        for (int i = 0; i < 100000000; i++) {
            // Apenas para simular um atraso
        }
    }
 
    printf("Fogos de artifício!\n");
   
    return 0;
}