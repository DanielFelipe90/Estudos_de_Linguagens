/* Acessando elementos de um array
Cada elemento de um array pode ser acessado diretamente pelo seu índice. Os índices dos arrays começam em 0. Vamos ver como acessar e imprimir elementos específicos de um array. Observe! */

#include <stdio.h>
 
int main() {
    int numeros[5] = {10, 20, 30, 40, 50};  // Inicialização do array com valores
 
    // Acessando e imprimindo elementos específicos do array
    printf("O primeiro elemento é %d\n", numeros[0]);
    printf("O segundo elemento é %d\n", numeros[1]);
    printf("O terceiro elemento é %d\n", numeros[2]);
    printf("O quarto elemento é %d\n", numeros[3]);
    printf("O quinto elemento é %d\n", numeros[4]);
 
    return 0;
}
/* 
Explicação do código

Vamos analisar cada linha desse programa.

Declaração e inicialização
“int numeros[5] = {10, 20, 30, 40, 50};” declara um array de inteiros chamado numeros com cinco elementos e os inicializa com os valores fornecidos.


Acesso aos elementos
numeros[0] acessa o primeiro elemento do array, que é 10. 
numeros[2] acessa o terceiro elemento do array, que é 30 . 
numeros[4] acessa o quinto elemento do array, que é 50 .


Impressão dos elementos
“printf("O primeiro elemento é %d\n", numeros[0]);” imprime o valor do primeiro elemento.

“printf("O terceiro elemento é %d\n", numeros[2]);” imprime o valor do terceiro elemento.

“printf("O quinto elemento é %d\n", numeros[4]);” imprime o valor do quinto elemento. */

