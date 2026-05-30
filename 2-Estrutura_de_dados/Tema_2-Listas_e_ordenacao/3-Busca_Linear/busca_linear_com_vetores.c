#include <stdio.h>

void exibirLista(int lista[], int tamanho);
int buscaLinear(int lista[], int tamanho, int valor);

int main()
{
    // Inicia o vetor(array) com 5 valores inteiros
    int lista[5] = {10, 20, 30, 40, 50};

    // Titulo
    printf("\nBuscar Linear com vetores:\n");
    
    // Exibi os valores do vetor usando a função exibirLista().
    exibirLista(lista, 5);

    //Exibindo o item da lista na posição 2 (terceira posição, pois o índice começa em 0)
    printf("\nO item da lista no índice 2 tem o valor: %d\n", lista[2]);

    // Chamada da função de busca linear, busca o índice do valor 30 na lista e exibe o resultado.
    buscaLinear(lista, 5, 30); // Exemplo: buscando o valor 30

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES EM VETORES ---

// --- Função para exibir os valores do vetor (array) ---
void exibirLista(int lista[], int tamanho) {
    printf("\nLista:");
    // Loop para percorrer o vetor (array) e exibir cada valor
    for(int i = 0; i < tamanho; i++) {
        printf(" %d", lista[i]);
    }
    printf("\n\n");
}

// --- Função de busca Linear ---
// Descrição: Procura por um 'valor' em vetor (array) 'lista' de um determinado 'tamanho'.
// O índice (posição) da primeira ocorrência do valor, se encontrado.
// - -1, se o valor não estiver na lista
int buscaLinear(int lista[], int tamanho, int valor) {
    // Começamos um loop do início (índice 0) até o fim da lista
    for (int i = 0; i < tamanho; i++) {
        // Em cada passo, comparamos o elemnto atual com o valor que buscamos
        if (lista[i] == valor) {
            printf("O item da lista que tem o valor 30 é: %d\n\n", i);
            // Se encontramos. retornaremos a posição (índice) onde ele está!
            return i;
        }
    }
    // Se o loop terminar e não encontrarmos nada, retornamos -1.
    return -1;
} 