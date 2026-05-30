#include <stdio.h>
#include <stdlib.h>

// Estrutura básica de um nó da lista circular simples
struct No
{
    int dado;
    struct No *proximo;
};

int main()
{
    struct No *primeiro = (struct No *)malloc(sizeof(struct No));
    struct No *segundo = (struct No *)malloc(sizeof(struct No));
    struct No *terceiro = (struct No *)malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = primeiro; // o último nó aponta para o primeiro, formando um ciclo

    struct No *atual = primeiro;
    
    printf("\n--- Varredura circular completa: ---\n");
    printf("Do início para o fim:\n");
    do
    {
        printf("Dado: %d\n", atual->dado);
        atual = atual->proximo; // Avança

    } while (atual != primeiro); // "Fique no loop APENAS SE eu não tiver voltado ao início"

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}