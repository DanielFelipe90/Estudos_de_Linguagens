/* Inicialização condicional de uma matriz

Inicializar uma matriz com valores baseados em condições específicas é uma tarefa comum. No primeiro exemplo, criamos uma matriz 3x3 em que os elementos são definidos como 1 ou 0, dependendo se o índice da coluna é par ou ímpar. Confira o exemplo! */

#include <stdio.h>
 
int main() {
    int matriz[3][3];
 
    // Inicialização da matriz com base em condições simples
    for (int i = 0; i < 3; i++) {      // Loop externo para as linhas
        for (int j = 0; j < 3; j++) {  // Loop interno para as colunas
            if (j % 2 == 0) {
                matriz[i][j] = 1; // Se a coluna for par, atribui 1
            } else {
                matriz[i][j] = 0; // Se a coluna for ímpar, atribui 0
            }
        }
    }
 
    // Impressão da matriz
    for (int i = 0; i < 3; i++) {      // Loop para imprimir cada linha
        for (int j = 0; j < 3; j++) {  // Loop para imprimir cada coluna
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
 
    return 0;
}

/* Explicação do código

Nesse exemplo, queremos criar uma matriz 3x3 e inicializar seus elementos de acordo com a paridade do índice da coluna. Entenda melhor a seguir!

Declaração da matriz

int matriz[3][3]; declara uma matriz de inteiros com 3 linhas e 3 colunas.

Inicialização da matriz

Utilizamos dois loops for aninhados para percorrer todas as posiçōes da matriz. O loop externo (for (int i=0; i<3; i++ ) ) itera sobre as linhas da matriz, enquanto o loop interno (for (int j=0;j<3; j++ )) itera sobre as colunas.
Dentro do loop interno, usamos uma condicional if ( j%2=0 ) para verificar se o índice da coluna é par. Se a condição for verdadeira, atribuímos o valor 1 ao elemento atual da matriz (matriz [1][j]=1;). Caso contrário, atribuímos o valor 0 (matriz [i][j]=0;).

Impressão da matriz

Após inicializar todos os elementos da matriz, utilizamos outro par de loops for aninhados para percorrer a matriz novamente e imprimir seus valores.
No loop de impressäo, para cada linha, iteramos sobre suas colunas e utilizamos printf("\%d ", matriz[i][j]); para exibir o valor do elemento atual, seguido de um espaço.
Após imprimir todos os elementos de uma linha, utilizamos printf("\n"); para pular para a próxima linha, garantindo que a matriz seja exibida de forma organizada. */