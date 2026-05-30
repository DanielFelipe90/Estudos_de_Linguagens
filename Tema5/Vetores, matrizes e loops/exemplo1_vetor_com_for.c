/* Um vetor é uma coleção ordenada de elementos do mesmo tipo. Para manipular os elementos de um vetor, as estruturas de repetição são extremamente úteis. Veja um exemplo básico de como inicializar e exibir os elementos de um vetor. */

#include <stdio.h>
 
int main() {
    int vetor[5]; // Declaração de um vetor de 5 inteiros
 
    // Inicialização do vetor usando uma estrutura de repetição for
    for (int i = 0; i < 5; i++) {
        vetor[i] = i * 2; // Atribuindo valores ao vetor
        printf("vetor[%d] = %d\n", i, vetor[i]); // Exibindo os elementos do vetor
    }
    printf("\n\n");
 
    return 0;
}

/* Nesse exemplo, usamos um loop for para inicializar os elementos do vetor "vetor" e outro loop for para exibir os valores armazenados.
O programa demonstra como utilizar um vetor para armazenar múltiplos valores inteiros e como a estrutura de repetição for pode ser empregada de maneira eficiente tanto para inicializar os valores do vetor quanto para exibi-los.
No for, o vetor é preenchido com múltiplos de 2, começando de 0 até 8. E imprime na tela os valores de cada elemento do vetor, neste caso variando de 0 até 8. */