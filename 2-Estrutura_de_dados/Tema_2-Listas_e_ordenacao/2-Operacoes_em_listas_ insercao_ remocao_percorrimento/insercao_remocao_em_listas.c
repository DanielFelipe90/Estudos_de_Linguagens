#include <stdio.h>
#include <stdlib.h>

// Estrutura básica de um nó da lista circular duplamente encadeada.
struct No
{
    int dado;
    struct No *proximo;
};

void exibirListaCompleta(struct No *primeiro);
void inserirNoInicio(struct No **primeiro, int valor);
void removerDoInicio(struct No **primeiro);

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
    terceiro->proximo = NULL;

    // Exibindo a lista completa
    printf("\n--- Varredura completa da lista Inicial: ---\n");
    exibirListaCompleta(primeiro);

    // Inserindo um novo nó no início da lista com valor 5.
    inserirNoInicio(&primeiro, 5);

    // Exibindo a lista completa após a inserção do novo nó de valor 5 na primeira posição.
    printf("\n--- Varredura completa da lista depois da inserção de um novo valor: ---\n");
    exibirListaCompleta(primeiro);

    // Removendo o nó do início da lista de valor 5.
    removerDoInicio(&primeiro);

    // Exibindo a lista completa após a remoção do nó de valor 5 da primeira posição.
    printf("\n--- Varredura completa da lista depois da remoção do primeiro valor: ---\n");
    exibirListaCompleta(primeiro);

    printf("\n");

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}


// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// Percorrimento
// Exibe os elementos da lista do início para o fim
void exibirListaCompleta(struct No *primeiro)
{
    // 1. Criamos um ponteiro "viajante" que começa no início da lista.
    struct No *atual = primeiro;

    // Se a lista estiver vazia, informamos ao usuário e saímos da função.
    if (primeiro == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos da lista do início para o fim:\n");
    // 2. Enquanto nosso ponteiro "viajante" não chegar ao fim (NULL)
    while (atual != NULL)
    {
        // 3. ... mostramos o dado do nó onde ele está
        printf("%d\n", atual->dado);
        // 4. ...e fazemos ele pular para o próximo nó.
        atual = atual->proximo;
    }
}

// Inserção
// Insere um novo nó no início da lista
void inserirNoInicio(struct No **primeiro, int valor)
{
    // 1. Primeiro criamos um novo nó alocando memória para ele
    struct No *novo = (struct No *)malloc(sizeof(struct No));

    // Verificação para o caso de falha na alocação de memória
    if (novo == NULL)
    {
        printf("Erro ao alocar memória para o novo nó.\n");
        return;
    }

    // 2. Atribuírmos o valor ao novo nó.
    novo->dado = valor;

    // 3. O "próximo" do noso nó será o antigo início da lista.
    // o ponteiro 'primeiro' é um ponteiro para um ponteiro, então '*primeiro' nos dá
    // o ponteiro para o primeiro nó atual da lista.
    novo->proximo = *primeiro;

    // 4.  Agora , o início da lista passa a ser o nosso novo nó.
    // Modificamos o ponteiro original para que ele aponte para o novo nó.
    *primeiro = novo;
}

// Remoção
// Remove o nó do início da lista.
void removerDoInicio(struct No **primeiro) {
    // 1. Primeiro, checamos se alista não está vazia.
    // Se 'primeiro' for NULL ou apontar para NULL, nao há nada a remover.
    if(primeiro == NULL || *primeiro == NULL){
        printf("Lista vazia, nada a remover.\n");
        return;
    }

    // 2. Guardamos o endereço do nó que vamos remover (o primeiro nó).
    struct No* noParaRemover = *primeiro;

    // 3. O início da lista agora passa a ser o segundo nó,
    // o ponteiro 'primeiro' passa a apontar para o nó seguinte ao que será removido.
    *primeiro = (*primeiro)->proximo;

    // 4. Liberamos a memória do nó que foi guardado e removido da lista.
    free(noParaRemover);
}