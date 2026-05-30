#include <stdio.h>
#include <stdlib.h>

/* A estrutura da lista estudada permite que a navegação na lista seja feita 
tanto do início para o fim como do fim para o início. Ao contrário da lista 
encadeada simples, que só permite avançar, a lista duplamente encadeada oferece 
mais flexibilidade, facilitando operações como inserção e remoção de elementos 
em qualquer posição da lista. */

// Estrutura básica de um nó da lista duplamente encadeada.
struct No {
    int dado;
    struct No* proximo;
    struct No* anterior;
};

int main() {
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    primeiro->dado = 10;
    primeiro->proximo = segundo;
    primeiro->anterior = NULL;

    segundo->dado = 20;
    segundo->proximo = terceiro;
    segundo->anterior = primeiro;

    terceiro->dado = 30;
    terceiro->proximo = NULL;
    terceiro->anterior = segundo;

    // Percorrendo a lista do início para o fim
    struct No* atual = primeiro;
    printf("\nPercorrendo a lista duplamente encadeada do início para o fim:\n");
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->proximo;
    }

    printf("\n");

    // Percorrendo a lista do fim para o início
    struct No* atual_reverso = terceiro;
    printf("Percorrendo a lista duplamente encadeada do fim para o início:\n");
    while(atual_reverso != NULL){
        printf("%d\n", atual_reverso->dado);
        atual_reverso = atual_reverso->anterior;
    }

    printf("\n");

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}