/* Modificação condicional de uma matriz

Modificar elementos de uma matriz com base em condições específicas é útil; por exemplo, transformar em negativos os elementos maiores que 5. Confira! */

#include <stdio.h>
 
int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
 
    // Modificação condicional dos elementos da matriz
    for (int i = 0; i < 3; i++) {      // Loop externo para as linhas
        for (int j = 0; j < 3; j++) {  // Loop interno para as colunas
            if (matriz[i][j] > 5) {
                matriz[i][j] = -matriz[i][j]; // Se o elemento for maior que 5, torna-o negativo
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

Nesse exemplo, modificamos uma matriz de forma que todos os elementos maiores que 5 sejam transformados em seus valores negativos. Confira para entender!

Declaração e inicialização da matriz

int matriz[3][3] = {{1, 2, 3}, 
                    {4, 5, 6}, 
                    {7, 8, 9}}; declara e inicializa uma matriz de inteiros com 3 linhas e 3 colunas.

Modificação condicional dos elementos

Utilizamos dois loops for aninhados para percorrer as posições da matriz. O loop externo (for (int i = 0; i < 3; i++)) itera sobre as linhas da matriz, enquanto o loop interno (for (int j = 0; j < 3; j++)) itera sobre as colunas.
Dentro do loop interno, usamos uma condicional if (matriz[i][j] > 5) para verificar se o valor do elemento atual é maior que 5. Se a condição for verdadeira, transformamos o valor do elemento em seu valor negativo (matriz[i][j] = -matriz[i][j];). */