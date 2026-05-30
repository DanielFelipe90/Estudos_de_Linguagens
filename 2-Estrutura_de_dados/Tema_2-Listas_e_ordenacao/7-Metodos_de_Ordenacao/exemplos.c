#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- FUNÇÃO "trocar() ---"
// Descrição: Recebe o endereço de duas variáveis inteiras e troca os valores entre elas.
// Por usar ponteiros(int*), a função modifica as variáveis originais que foram passadas para ela
void trocar(int* a, int* b) {
    // 1. Guarda o valor apontado por "a" em uma variável temporária.
    // O asteristico (*) é o operador de "desreferência", que acessa o valor no endereço.
    int temp = *a;

    // 2. O valor apontado por "b" é copiado para o local apontado por "a".
    *a = *b;

    // 3. O valor que guardamos (original de "a") é copiado para o local apontado por "b".
    *b = temp;
} 

// --- FUNÇÃO BUBBLESORT ---
// Descrição: Ordena um vetor de inteiros em ordem crescente usando o algoritmos bubblesort
void bubbleSort(int vetor[], int tamanho) {
    // Laço externo: controla o número de passadas pelo vetor.
    // A cada passada "i", o i-ésimo maior elemento "borbulha" para o lugar certo.
    for (int i = 0; i < tamanho - 1; i++) {
        // Laço interno: percorre o vetor comparando pares de vizinhos.
        /* O limite (tamanho -1 - i) é uma otimização: ele diminui a cada
        passada, pois os maiores elementos já estão fixos no final. */
        for (int j = 0; j < tamanho - 1 - i; j++) {
            // A condição de comparação: se o elemento da esquerda for maior que o da direita ...
            if (vetor[j] > vetor[j + 1]) {
                // ...troca! Passamos os endereços dos elemntos para a função "trocar()"
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

// --- FUNÇÃO "insertionSort()" ---
// Descrição: Ordena um vetor de inteiros em ordem crescente usando o
// algoritmo de ordenação por inserção 'Insertion Sort'.
// Esse algoritmo é bom ser usado em lista que já está quase ordenada.
// ESSE EXEMPLO FAZ ANALOGIA A UM JOGO DE CARTAS 
void insertionSort(int vetor[], int tamanho) {
    // Começamos do segundo elemento (indice 1), pois o primeiro(indice 0) já está ordenado.
    for (int i = 1; i < tamanho; i++) {
        // 1. Pegamos a "carta da vez"  e guardamos na nossa "chave".
        int chave = vetor[i];
        int j = i - 1;

        // 2. Agora, olhamos para a "mão" (a parte ordenada à esquerda).
         /* Enquanto houver elementos para trás (j >= 0) e o elemento da mão 
         for maior que a nossa chave ... */
        while (j >= 0 && vetor[j] > chave) {
            // ...empurramos o elemento da mão uma posição para a direita.
            vetor[j + 1] = vetor[j];
            j--; // E olhamos para a próxima "carta" na mão, para trás.
        }

        // 3. O loop "while" parou. Encontramos o lugar certo!
        // Inserimos a nossa chave no espaço que foi aberto.
        vetor[j + 1] = chave;
    }
} 

// --- FUNÇÃO "selectionSort()" ---
/* Descrição: Ordena um vetor de inteiro em ordem crescente usando o
algoritmo de ordenação por seleção 'Selection Sort'. */
void selectionSort(int vetor[], int tamanho) {
    /* Laço externo: percorre as posições que precisam se preenchidas,
    uma de cada vez, da esquerda para a direita. */
    for (int i = 0; i < tamanho - 1; i++) {
        // Assume que o menor, por enquanto, é o elemento na posição "i".
        int indiceMenor = i;
        // Laço interno: busca pelo menor elemento no resto do vetor (à direita de "i").
        for (int j = i + 1; j < tamanho; j++) {
            // Se enconcontrar um elemento ainda menor...
            if (vetor[j] < vetor[indiceMenor]) {
                // ...atualiza o nosso índice do menor
                indiceMenor = j;
            }
        }
        // Após o laço interno, "indiceMenor" contém a posição do menor elemento.
        // Se o meneor não for o próprio elemento da posição "i" (uma pequena otimização), realiza a troca
        if (indiceMenor != i) {
            trocar(&vetor[i], &vetor[indiceMenor]);
        }
    }
}