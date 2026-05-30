/* Contagem condicional em uma matriz

Contar elementos que atendem a determinadas condições dentro de uma matriz é importante; no terceiro exemplo, contamos quantos elementos são pares e quantos são ímpares. */

#include <stdio.h>
 
int main() {
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int numeroPar = 0, numeroImpar = 0;
 
    // Contagem de elementos pares e ímpares
    for (int i = 0; i < 3; i++) {      // Loop externo para as linhas
        for (int j = 0; j < 3; j++) {  // Loop interno para as colunas
            if (matriz[i][j] % 2 == 0) {
                numeroPar++; // Incrementa o contador de pares
            } else {
                numeroImpar++; // Incrementa o contador de ímpares
            }
        }
    }
 
    // Impressão dos resultados
    printf("Número de elementos pares: %d\n", numeroPar);
    printf("Número de elementos ímpares: %d\n", numeroImpar);
    printf("\n\n");
 
    return 0;
}

/* Explicação do código

Nesse exemplo, queremos contar quantos elementos são pares e quantos são ímpares. Confira para entender!

Declaração e inicialização da matriz

int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; declara e inicializa uma matriz de inteiros com 3 linhas e 3 colunas.

Declaração de contadores

int numeroPar =0, numeroImpar =0; declara e inicializa dois contadores, um para os elementos pares (numeroPar) e outro para os impares (numeroImpar), ambos iniciados em 0.

Contagem dos elementos

Utilizamos dois loops for aninhados para percorrer todas as posições da matriz. O loop externo (for (int i = 0; i < 3; i++)) itera sobre as linhas da matriz, enquanto o loop interno (for (int j = 0; j < 3; j++)) itera sobre as colunas.
Dentro do loop interno, usamos uma condicional if (matriz[i][j] % 2 == 0) para verificar se o valor do elemento atual é par. Se a condição for verdadeira, incrementamos o contador de elementos pares (numeroPar++). Caso contrário, incrementamos o contador de elementos ímpares (numeroImpar++).

Impressão dos resultados

Após percorrer toda a matriz e contar os elementos pares e ímpares, utilizamos printf para imprimir os resultados.
printf("Número de elementos pares: %d\n", numeroPar); imprime o número total de elementos pares.
printf("Número de elementos ímpares: %d\n", numeroImpar); imprime o número total de elementos ímpares. */