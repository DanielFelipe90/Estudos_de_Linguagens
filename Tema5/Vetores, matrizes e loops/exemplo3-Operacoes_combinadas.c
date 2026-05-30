/* Operações combinadas

Podemos realizar operações mais complexas com vetores e matrizes usando estruturas de repetição. Por exemplo, podemos somar duas matrizes ou calcular a soma dos elementos de um vetor.

Soma de matrizes

É uma operação fundamental em programação, especialmente em álgebra linear e computação científica. Consiste em somar os elementos correspondentes de duas matrizes para formar uma nova matriz. Aqui está um exemplo para ilustrar o processo: Vamos somar duas matrizes 2x2. Primeiro, declaramos e inicializamos duas matrizes chamadas matriz1 e matriz2. Em seguida, criamos uma matriz chamada matrizSoma para armazenar os resultados. */

#include <stdio.h>
 
int main() {
    int matriz1[2][2] = {{1, 2}, {3, 4}};
    int matriz2[2][2] = {{5, 6}, {7, 8}};
    int matrizSoma[2][2];
 
    // Somando as duas matrizes
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
 
    // Exibindo a matriz resultante
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("matrizSoma[%d][%d] = %d\n", i, j, matrizSoma[i][j]);
        }
    }
    printf("\n\n");
 
    return 0;
}

/* Vamos entender o que o código faz:
1. Declaração e inicialização: As matrizes matriz1 e matriz2 são declaradas e inicializadas com valores.
2. Soma das matrizes: Usamos dois loops for aninhados para percorrer cada elemento das matrizes. Para cada posição [i][j], somamos os valores correspondentes de matriz1 e matriz2, armazenando o resultado em matrizSoma.
3. Exibição da matriz resultante: Por fim, usamos outro conjunto de loops for aninhado para percorrer matrizSoma e imprimir seus elementos, mostrando a matriz resultante da soma. */