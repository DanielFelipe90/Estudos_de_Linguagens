#include <stdio.h>
#include <stdlib.h>


// Estrutura básica de um nó da lista circular duplamente encadeada.
struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
};

void exibirListaCompleta(struct No* primeiro, struct No* terceiro);

int main() {
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;
    primeiro->anterior = terceiro; // o primeiro nó aponta para o terceiro, formando um ciclo

    segundo->dado = 20;
    segundo->proximo = terceiro;
    segundo->anterior = primeiro;

    terceiro->dado = 30;
    terceiro->proximo = primeiro; // o último nó aponta para o primeiro, formando um ciclo
    terceiro->anterior = segundo;

    // Exibindo a lista completa
    exibirListaCompleta(primeiro, terceiro);


    printf("\n");

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}

void exibirListaCompleta(struct No* primeiro, struct No* terceiro) {
    if (primeiro == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* atual = primeiro;
    struct No* atual_reverso = terceiro;

    printf("\n--- Varredura circular completa: ---\n");
    printf("Do início para o fim:\n");
    do {
        printf("Dado: %d\n", atual->dado);
        atual = atual->proximo; // Avança
        
    } while (atual != primeiro); // "Fique no loop APENAS SE eu não tiver voltado ao início"

    printf("\n");

    printf("Do fim para o início:\n");
    do {
        printf("Dado: %d\n", atual_reverso->dado);
        atual_reverso = atual_reverso->anterior; // Avança
        
    } while (atual_reverso != terceiro); // "Fique no loop APENAS SE eu não tiver voltado ao fim"
}