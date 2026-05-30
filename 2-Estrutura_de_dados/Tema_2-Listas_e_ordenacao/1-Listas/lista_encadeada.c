#include <stdio.h>
#include <stdlib.h>

/* Vamos criar manualmente uma lista com três nós com os valores 10, 20 e 30. 
Cada nó aponta para o próximo até que o último (terceiro) aponte para NULL, 
indicando o fim da lista encadeada. Veja! */


// Estrutura básica de um nó da lista encadeada
struct No {
    int dado;
    struct No* proximo;
};

int main() {
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;

    // Percorrendo a lista
    struct No* atual = primeiro;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}