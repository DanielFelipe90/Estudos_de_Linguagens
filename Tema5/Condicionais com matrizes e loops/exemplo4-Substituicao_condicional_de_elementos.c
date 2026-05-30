/* Substituição condicional de elementos

Substituir elementos de uma matriz com base em condições específicas é útil; no quarto exemplo, os elementos múltiplos de 3 são substituídos por -1. Veja o exemplo! */

#include <stdio.h>
 
int main() {
    int matriz[3][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}};
 
    // Substituição condicional de elementos
    for (int i = 0; i < 3; i++) {      // Loop externo para as linhas
        for (int j = 0; j < 3; j++) {  // Loop interno para as colunas
            if (matriz[i][j] % 3 == 0) {
                matriz[i][j] = -1; // Substitui múltiplos de 3 por -1
            }
        }
    }
 
    // Impressão da matriz modificada
    for (int i = 0; i < 3; i++) {      // Loop para imprimir cada linha
        for (int j = 0; j < 3; j++) {  // Loop para imprimir cada coluna
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
 
    return 0;
}

/* Explicação do código

Nesse exemplo, modificamos uma matriz de forma que todos os elementos que são múltiplos de 3 sejam substituídos por -1. Confira para entender!

Declaração e inicialização da matriz

A matriz "matriz" é declarada e inicializada com valores predefinidos: 
{{1,2,3},
 {4,5,6},
 {7,8,9}}.

Substituição condicional dos elementos

Utilizamos dois loops for aninhados para percorrer todas as posições da matriz. O loop externo (for (int i = 0; i < 3; i++)) itera sobre as linhas da matriz, enquanto o loop interno (for (int j = 0; j < 3; j++)) itera sobre as colunas.
Dentro do loop interno, usamos uma condicional if (matriz[i][j] % 3 == 0) para verificar se o valor do elemento atual é múltiplo de 3 . Se a condição for verdadeira, substituímos o valor do elemento por −1 (matriz[i][j] = −1).

Impressão da matriz modificada

Após modificar os elementos da matriz, utilizamos outro par de loops for aninhados para percorrer a matriz novamente e imprimir seus valores.
No loop de impressão, para cada linha, iteramos sobre suas colunas e utilizamos printf("%2d ", matriz[j][j]) para exibir o valor do elemento atual, seguido de um espaço.
Após imprimir todos os elementos de uma linha, utilizamos printf("\n") para pular para a próxima linha, garantindo que a matriz seja exibida de forma organizada. */