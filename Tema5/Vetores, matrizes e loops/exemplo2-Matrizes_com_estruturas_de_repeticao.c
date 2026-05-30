/* Matrizes com estruturas de repetição

Uma matriz é uma coleção bidimensional (ou multidimensional) de elementos do mesmo tipo. As estruturas de repetição são essenciais para percorrer e manipular matrizes. Veja um exemplo de como inicializar e exibir os elementos de uma matriz. */

#include <stdio.h>
 
int main() {
    int matriz[3][3]; // Declaração de uma matriz 3x3 de inteiros
 
    // Inicialização da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = i + j; // Atribuindo valores à matriz
        }
    }
    printf("\n\n");
 
    // Exibindo os elementos da matriz usando estruturas de repetição for aninhadas
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }
    printf("\n\n");
 
    return 0;
}
/* 
Aqui, utilizamos dois loops for aninhados: o primeiro for começa a varredura pela primeira linha, e a cada passo do loop, a segunda estrutura for é ativada, iniciando a varredura das colunas dessa linha.
Dentro deste segundo for, um simples cálculo é feito: a soma do número da linha com o número da coluna (i + j). Esse valor é atribuído à posição correspondente na matriz, como se você estivesse anotando a soma de duas coordenadas em cada célula do tabuleiro.
Assim, ao final dessa dupla varredura, toda a matriz estará preenchida. Cada elemento terá um valor que corresponde à soma de seu índice de linha com seu índice de coluna. Por exemplo, na posição [0][0], a soma será 0 + 0, resultando em 0. Já na posição [1][2], a soma será 1 + 2, resultando em 3.
Mas preencher a matriz é apenas metade da tarefa. Agora, você precisa exibir esses valores para confirmar que a tabela foi preenchida corretamente. Para isso, você recorre novamente às estruturas for aninhadas.
Desta vez, em vez de atribuir valores, você acessa cada elemento da matriz e o imprime na tela. O programa percorre novamente cada linha e coluna, exibindo os números que foram calculados anteriormente. */