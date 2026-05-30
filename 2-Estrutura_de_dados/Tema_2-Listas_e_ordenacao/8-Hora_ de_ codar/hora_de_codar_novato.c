#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para funções de string (strcpy, strcmp)

// Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_STR_LEN 50 // Tamanho máximo de cada string/texto

// PARTE 1: LISTA ESTÁTICA (VETOR DE STRINGS)
// Uma lista estática é uma estrutura de dados de tamanho fixo,
// implementada usando um vetor (ou array).
// Toda memória necessária é alocada de uma só vez, quando a variável é declarada.

// Define uma constante para número máximo de itens que nossa lista pode conter.
#define TAM_MAX 10 //Define o número máximo de itens na ista estática.

// Estrutura que representa uma estrutura estática de lista d strings.
typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas (itens), 50 colunas (caracteres por item).
    int quantidade; // Este é nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista.
} ListaEstatica;

// Funções da lista estática
// Essa função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como zero, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variável original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

// Função que adiciona um novo item (texto/string) à lista.
void inserirListaEstatica(ListaEstatica *lista, const char *texto);

// Função que remove um item da lista estática
void removerListaEstatica(ListaEstatica *lista, const char *texto);

// Função que exibe os itens da lista estática
void listarListaEstatica(const ListaEstatica *lista);

// PARTE 2: LISTA ENCADEADA (DE STRINGS/TEXTOS)
// Uma lista encadeada é uma estrutura de dados de tamanho dinâmico
// Ela composta por nós separados na memória,
// onde cada nó contém um dado e um ponteiro que aponta para o próximo nó da sequência.

// EStrutura do nó (cada elemento da lista encadeada)
// - char* dado: Este é o ponteiro. Ele não armazena o texto em si,
// mas sim o endereço de meória onde está armazenado o texto.
// Isso é muito flexível, pois cada texto pode ter um tamanho diferente, e alocamos apenas
// a memória necessária para cada um.
// - struct No *proximo: Este é o ponteiro que cria a "ligação". Ele armazena o endereço do próximo nó na lista.
// O último nó da lista terá este ponteiro apontando para NULL.
typedef struct No {
    char *dado;
    struct No *proximo;
} No;

// Isso é um atalho. Em vez de escrever No* sempre que quisermos nos referir à nossa lista, podemos usar ListaEncadeada.
typedef No* ListaEncadeada;

// Funções da lista encadeada
// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta pata NULL.
// Está função simplesmente atribui NULL ao ponteiro que representa nosa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

// Função que adiciona um novo item (texto/string) à lista encadeada
void inserirListaEncadeada(ListaEncadeada *lista, const char *texto);

// Função que remove um item da lista encadeada
void removerListaEncadeada(ListaEncadeada *lista, const char *texto);

// Função que exibe os itens da lista encadeada
void listarListaEncadeada( const ListaEncadeada lista);

// Função que libera a memória alocada para a lista encadeada.
void liberarListaEncadeada(ListaEncadeada *lista);

// Funções de Menus
// Exibe o menu principal do programa
void menuPrincipal();

// Exibe o menu da lista estática
void menuListaEstatica();

// Exibe o menu da lista encadeada
void menuListaEncadeada();

// Limpa o buffer de entrada
void limparBufferEntrada();

// FUNÇÃO PRINCIPAL (MAIN)

int main(){
    int opcao;
    do{
        menuPrincipal();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
            menuListaEstatica();
            break;
        case 2:
            menuListaEncadeada();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!");
        }
    } while(opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ESTÁTICA ---

// --- Função de inicialização da lista estática ---
void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

// --- Função para inserir um novo item na lista estática ---
void inserirListaEstatica(ListaEstatica *lista, const char *texto) {
    // Primeiro, ela verifica se lista->quantidade já atingiu TAM_MAX.
    // Se sim, a lista está cheia e a função retorna.
    if (lista->quantidade >= TAM_MAX) {
        printf("\nLista está cheia. Não é possível inserir mais itens.\n");
        return;
    }
    // A inserção ocorre na primeira "linha" livre da matriz
    // Para strings, não podemos fazer "lista->[i] = texto;", porque em c não se pode atribuir vetores/strings
    // diretamente; por isso, utilizamos a função strcpy() para copiar os caracteres para a posição correta.
    strcpy(lista->dados[lista->quantidade], texto);

    // Após a inserção bem-sucedida, incrementamos o contador de itens da lista.
    lista->quantidade++;
    printf("\nTexto \"%s\" inserido com sucesso.\n", texto);
}

// --- Função para remover um item da lista estática) ---
void removerListaEstatica(ListaEstatica *lista, const char *texto){
    int i, pos = -1;
    // Para comparar strings usamos strcmp(). Retorna 0 se forem iguais.
    // A função percorre os itens em uso na lista (de zero até quantidade).
    // Para comparar strings, usamos strcmp(string1, string2).
    // Essa função retorna zero se as strings forem idênticas. Se encontrar, guarda a posição (pos)  e para o loop.
    for(i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: se o loop terminar e pos continuar -1, o item não foi encontrado.
    if(pos == -1){
        printf("\nTexto \"%s\" não encontrado na lista.\n", texto);
        return;
    }

    // Fechar a lacuna: Se removemos um item do meio da lista, criamos um 'buraco'.
    // Para preenchê-lo, movemos todos os itens subsequentes uma posição para a esquerda.
    // O loop for começa na posição do item removido e copia cada item i+1 para a posição i.
    // Deslocar os elemntos posteriores para a esquerda usando strcpy.
    for(i = pos; i < lista->quantidade - 1; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    // Atualização do contador: Finalmente, quantidade é decrementado para refletir que a lista tem um item a menos.
    lista->quantidade--;
    printf("\nTexto \"%s\" removido com sucesso.\n", texto);
}

// --- Função para listar os itens da lista estática ---
void listarListaEstatica(const ListaEstatica *lista){
    if(lista->quantidade == 0){
        printf("\nA lista estática está vazia.\n");
        return;
    }
    printf("\nItens na lista estática: [ ");
    for(int i = 0; i < lista->quantidade; i++){
        printf("\"%s\" ", lista->dados[i]); // Usar %s para imprimir strings
    }
    printf("]\n");
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ENCADEADA ---

// --- Função que inicializa a lista encadeada ---
// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Essa função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista) {
    *lista = NULL;
}

// --- Função que inseri itens a lista encadeada
void inserirListaEncadeada(ListaEncadeada *lista, const char *texto) {
    // 1. Alocar memória para o NOVO NÓ
    // Alocação do Nó: malloc(sizeof(No)) pede ao sistema operacional memória suficiente para o nó.
    // novoNo agora aponta para essa memória.
    No *novoNo = (No *)malloc(sizeof(No));

    // Verificação
    if (novoNo == NULL) {
        printf("\nErro ao alocar memória para o novo nó.\n");
        return;
    }

    // 2. Alocar memória para o TEXTO/STRING DE NTRO DO NÓ
    // strlen(texto) + 1 para incluir o caractere nulo '\0' no final
    // Alocação da string: malloc (strlen(texto) + 1) aloca memória para o texto.
    // strlen conta os caracteres, e o +1 é vital para caractere nulo (\0) que finaliza toda string em C.
    // novoNo->dado agora aponta para este espaço.
    novoNo->dado = (char *)malloc(strlen(texto) + 1);

    // Verificação
    if (novoNo->dado == NULL) {
        printf("Erro ao alocar memória para o texto do novo nó.\n");
        free(novoNo);
        return;
    }

    // 3. Copiar o texto para a memória recém-alocada
    // Cópia do texto: strcpy copia o texto de entrada para a área de memóriarecém-alocada aponatada por novoNo->dado.
    strcpy(novoNo->dado, texto);

    // 4. Ligar o novo nó à lista
    // O ponteiro próximo do novo nó passa a apontar para o que era antigo primeiro nó da lista
    novoNo->proximo = *lista;
    // A cabeça da lista (*lista) é atualizada para apontar para o novoNo. O novoNo é agora o primeiro item.
    *lista = novoNo;

    printf("\nTexto \"%s\" inserido com sucesso.\n", texto);
}

// --- Função que remove itens a lista encadeada
void removerListaEncadeada(ListaEncadeada *lista, const char *texto) {
    No *anterior = NULL;
    No *atual = *lista;

    while (atual != NULL && strcmp(atual->dado, texto) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    // Verificação
    if (atual == NULL) {
        printf("\nErro: Texto \"%s\" não encontrado na lista.\n", texto);
        return;
    }

    // Se o nó a ser removido for o primeiro (anterior == NULL), a cabeça da lista (*lista) passa a ser o segundo
    // Se 'anterior' é NULL, significa que o nó a ser removido é o primeiro da lista
    if (anterior == NULL) {
        // O novo primeiro nó é o próximo do nó atual
        *lista = atual->proximo;
    } else {
        // Se o nó a ser removido não é o primeiro,
        // o nó anterior aponta para o próximo do nó atual, "pulando" o nó atual.
        anterior->proximo = atual->proximo;
    }

    // Libera a memória alocada para a string (dado) dentro do nó.
    // É importante liberar primeiro o dado, pois ele foi alocado separadamente.
    free(atual->dado);

    // Libera a memória alocada para o próprio nó.
    free(atual);

    printf("\nTexto \"%s\" removido com sucesso.\n", texto);
}

// --- Função que lista os itens da lista encadeada ---
void listarListaEncadeada(const ListaEncadeada lista) {
    No *temp = lista;
    if (temp == NULL) {
        printf("\nA lista encadeada está vazia.\n");
        return;
    }
    printf("\nItens na lista encadeada: [ ");
    while (temp != NULL) {
        printf("\"%s\" ", temp->dado);
        temp = temp->proximo;
    }
    printf("]\n");
}

// --- Função que libera a memória alocada para a lista encadeada ---
// Ela percorre todos os nós da lista, um por um, e aplica a mesma lógica de liberação de memória dupla (free(dado))
// e depois free(nó) para cada um deles, garantindo que nehuma memória alocada seja deixada para trás quando o programa terminar.
void liberarListaEncadeada(ListaEncadeada *lista) {
    No *atual = *lista;
    No *proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual->dado); // Libera a string
        free(atual); // Libera o nó
        atual = proximo;
    }
    *lista = NULL;
}

// --- FUNÇÕES DE EXIBIÇÃO DE MENUS ---
void menuPrincipal(){
    printf("\n--- Exemplo de inserção, remoção e busca linear em listas estáticas e encadeadas ---\n");
    printf("\nEscolha uma opção:\n");
    printf("1 - Lista estática\n");
    printf("2 - Lista encadeada\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}

// Exibe o menu da lista estática
void menuListaEstatica(){
    ListaEstatica lista;
    inicializarListaEstatica(&lista);
    int opcao;
    do{
        printf("\n--- Ferramenta de lista estática funcionando como fila---\n");
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir texto\n");
        printf("2 - Remover texto\n");
        printf("3 - Listar itens\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:{
            char texto[MAX_STR_LEN];
            printf("\nDigite o texto a ser inserido: ");
            fgets(texto, MAX_STR_LEN, stdin);
            texto[strcspn(texto, "\n")] = '\0';
            inserirListaEstatica(&lista, texto);
            break;
        }
        case 2:{
            char texto[MAX_STR_LEN];
            printf("\nDigite o texto a ser removido: ");
            fgets(texto, MAX_STR_LEN, stdin);
            texto[strcspn(texto, "\n")] = '\0';
            removerListaEstatica(&lista, texto);
            break;
        }
        case 3:
            listarListaEstatica(&lista);
            break;
        case 0:
            printf("\nVoltando ao menu principal...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);
}

// Exibe o menu da lista encadeada
void menuListaEncadeada(){
    ListaEncadeada lista;
    inicializarListaEncadeada(&lista);
    int opcao;
    do{
        printf("\n--- Ferramenta de lista encadeada funcionando como pilha ---\n");
        printf("\nEscolha uma opção:\n");
        printf("1 - Inserir texto\n");
        printf("2 - Remover texto\n");
        printf("3 - Listar itens\n");
        printf("0 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();


        switch (opcao)
        {
        case 1:{
            char texto[MAX_STR_LEN];
            printf("\nDigite o texto a ser inserido: ");
            fgets(texto, MAX_STR_LEN, stdin);
            texto[strcspn(texto, "\n")] = '\0';
            inserirListaEncadeada(&lista, texto);
            break;
        }
        case 2:{
            char texto[MAX_STR_LEN];
            printf("\nDigite o texto a ser removido: ");
            fgets(texto, MAX_STR_LEN, stdin);
            texto[strcspn(texto, "\n")] = '\0';
            removerListaEncadeada(&lista, texto);
            break;
        }
        case 3:
            listarListaEncadeada(lista);
            break;
        case 0:
            printf("\nVoltando ao menu principal...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);
}

// --- Função de limpeza do buffer de entrada
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}