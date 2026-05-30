/* Sua missão é construir um sistema de inventário que simule a mochila de loot inicial do jogador.
Para isso, você criará uma struct chamada Item, que armazenará informações essenciais de cada objeto coletado.
 O sistema permitirá que o jogador cadastre, remova, liste e busque por itens dentro da mochila.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 30
#define TAM_MAX_TIPO 20
#define MAX_ITEM 10

/* Requisitos funcionais

 Confira as principais funcionalidades do sistema a serem implementadas:
1. Criação da struct: definir uma struct chamada Item com os campos char nome[30], char tipo[20] e int quantidade. */
// Estrutura que representa uma estrutura estática de lista d strings.
typedef struct
{
    char nome[MAX_ITEM][TAM_MAX_NOME]; // Matriz: 10 linhas (itens), 30 colunas (caracteres por item).
    char tipo[MAX_ITEM][TAM_MAX_TIPO];
    int quantidadeItem[MAX_ITEM];
    int quantidade; // Este é nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista.
} Item;

// --- PROTOTIPOS DAS FUNÇÕES ---

// 1. --- Função de inicialização da MOCHILA DO FREE FIRE ---
// Funções da lista estática
// Essa função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como zero, indicando que a lista está vazia.
// Recebemos um ponteiro (*item) para modificar a variável original passada para a função.
void inicializarMochila(Item *mochila);

/* 2. Cadastro de itens: o sistema deve permitir que o jogador cadastre até 10 itens informando nome,
tipo (ex: arma, munição e cura) e quantidade. */
// --- Função de cadastro de itens ---
void inserirItemMochila(Item *mochila, const char *nome, const char *tipo, int quantidadeItem);

/* 3. Remoção de itens: permitir que o jogador exclua um item da mochila, informando seu nome. */
// --- Função de remoção de itens ---
void removerItemMochila(Item *mochila, const char *nome);

/* 4. Listagem dos itens registrados com seus dados: o que deve ocorrer após cada operação. */
void listarItensMochila(const Item *mochila);

// 5. Busca Binária Recursiva
int buscaBinariaRecursiva(Item *mochila, const char *nomeBuscaBinariaRecursiva, int inicio, int fim);

// 6. Verifica se a mochila está vazia
int mochilaVazia(Item *mochila);

// 7. Função limpar buffer de entrada
void limparBufferEntrada();

// Função principal (main)
int main()
{
    Item mochila;
    inicializarMochila(&mochila);
    int opcao;
    do
    {
        printf("\n=========================================================\n");
        printf("        MOCHILA DE SOBREVIVENCIA DO FREE FIRE\n");
        printf("=========================================================\n");
        printf("       Itens na mochila: %d/%d\n\n", mochila.quantidade, MAX_ITEM);
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Itens\n");
        printf("4. Busca Binária Recursiva de Item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
        {
            char nome[TAM_MAX_NOME], tipo[TAM_MAX_TIPO];
            int quantidadeItem = 0;
            printf("\nDigite o nome do item:\n");
            fgets(nome, TAM_MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            printf("Digite o tipo do item (arma, munição, cura, etc):\n");
            fgets(tipo, TAM_MAX_TIPO, stdin);
            tipo[strcspn(tipo, "\n")] = '\0';
            printf("Digite a quantidade do item:\n");
            scanf("%d", &quantidadeItem);
            limparBufferEntrada();
            inserirItemMochila(&mochila, nome, tipo, quantidadeItem);
            break;
        }
        case 2:
        {
            if (mochilaVazia(&mochila) == 0)
            {
                char nome[TAM_MAX_NOME];
                printf("\n--- Remover Item ---");
                printf("\nDigite o nome do item a ser removido: ");
                fgets(nome, TAM_MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItemMochila(&mochila, nome);
            }
            break;
        }
        case 3:
            listarItensMochila(&mochila);
            break;
        case 4:
            if (mochilaVazia(&mochila) == 0)
            {
                char nomeBuscaBinariaRecursiva[TAM_MAX_NOME];
                printf("\n--- Busca Binária Recursiva de Itens ---\n");
                printf("Digite o nome do item a ser buscado: ");
                fgets(nomeBuscaBinariaRecursiva, TAM_MAX_NOME, stdin);
                nomeBuscaBinariaRecursiva[strcspn(nomeBuscaBinariaRecursiva, "\n")] = 0; // Remove o \n do enter
                buscaBinariaRecursiva(&mochila, nomeBuscaBinariaRecursiva, 0, mochila.quantidade - 1);
            }
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// --- Função para inicialização da lista de itens - MOCHILA FREE FIRE ---
void inicializarMochila(Item *mochila)
{
    mochila->quantidade = 0;
}

// --- Função para inserir um novo item na lista estática ---
void inserirItemMochila(Item *mochila, const char *nome, const char *tipo, int quantidadeItem)
{
    // 1. Primeiro, tenta buscar se o item já existe
    for (int i = 0; i < mochila->quantidade; i++)
    {
        if (strcmp(mochila->nome[i], nome) == 0)
        {
            mochila->quantidadeItem[i] += quantidadeItem; // Apenas atualiza a quantidade existente
            printf("Quantidade de %s atualizada!\n", nome);
            return;
        }
    }
    // Primeiro, ela verifica se lista->quantidade já atingiu TAM_MAX.
    // Se sim, a lista está cheia e a função retorna.
    if (mochila->quantidade >= MAX_ITEM)
    {
        printf("\nLista está cheia. Não é possível inserir mais itens.\n");
        return;
    }
    // A inserção ocorre na primeira "linha" livre da matriz
    // Para strings, não podemos fazer "lista->[i] = texto;", porque em c não se pode atribuir vetores/strings
    // diretamente; por isso, utilizamos a função strcpy() para copiar os caracteres para a posição correta.
    strcpy(mochila->nome[mochila->quantidade], nome);
    strcpy(mochila->tipo[mochila->quantidade], tipo);

    // Adiciona a quantidade
    mochila->quantidadeItem[mochila->quantidade] = quantidadeItem;

    // Após a inserção bem-sucedida, incrementamos o contador de itens da lista.
    mochila->quantidade++;
    printf("\nItem \"%s\" adicionado com sucesso.\n", nome);

    listarItensMochila(mochila);
}

// --- Função para remover um item da lista estática) ---
void removerItemMochila(Item *mochila, const char *nome)
{
    int i, pos = -1;

    // Para comparar strings usamos strcmp(). Retorna 0 se forem iguais.
    // A função percorre os itens em uso na lista (de zero até quantidade).
    // Para comparar strings, usamos strcmp(string1, string2).
    // Essa função retorna zero se as strings forem idênticas. Se encontrar, guarda a posição (pos)  e para o loop.
    for (i = 0; i < mochila->quantidade; i++)
    {
        if (strcmp(mochila->nome[i], nome) == 0)
        {
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: se o loop terminar e pos continuar -1, o item não foi encontrado.
    if (pos == -1)
    {
        printf("\nItem \"%s\" não encontrado na Mochila.\n", nome);
        return;
    }

    // Fechar a lacuna: Se removemos um item do meio da lista, criamos um 'buraco'.
    // Para preenchê-lo, movemos todos os itens subsequentes uma posição para a esquerda.
    // O loop for começa na posição do item removido e copia cada item i+1 para a posição i.
    // Deslocar os elemntos posteriores para a esquerda usando strcpy.
    for (i = pos; i < mochila->quantidade - 1; i++)
    {
        strcpy(mochila->nome[i], mochila->nome[i + 1]);
        strcpy(mochila->tipo[i], mochila->tipo[i + 1]);
    }

    // Atualização do contador: Finalmente, quantidade é decrementado para refletir que a lista tem um item a menos.
    mochila->quantidade--;
    printf("\nItem %s removido com sucesso da mochila.\n", nome);

    listarItensMochila(mochila);
}

// --- Função para listar itens da MOCHILA DO FREE FIRE ---
void listarItensMochila(const Item *mochila)
{
    if (mochila->quantidade == 0)
    {
        printf("\nA mochila está vazia.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }
    printf("\n            --- Itens na Mochila (%d/10) ---\n", mochila->quantidade);
    printf("----------------------------------------------------------------\n");
    printf("%-20s | %-22s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < mochila->quantidade; i++)
    {
        printf("%-20s | %-22s | %-10d\n", mochila->nome[i], mochila->tipo[i], mochila->quantidadeItem[i]);
    }
    printf("----------------------------------------------------------------\n");

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// =====================================================================================
//                   --- FUNÇÃO DE BUSCA BINÁRIA RECURSIVA ---
// =====================================================================================
// Descrição: Procura por um "valor" em uma fatia de um "vetor/mochila" ORDENADO, definida por 'inicio' e 'fim'
// Pré-requisitos: o Vetor de estar em ordem CRESCENTE.
// Retorno: O índice do valor se encontrado; -1 caso não encontre o valor/nomeBuscaBinariaRecursiva
int buscaBinariaRecursiva(Item *mochila, const char *nomeBuscaBinariaRecursiva, int inicio, int fim) {
    // CASO BASE: Se área de busca se torna inválida (inicio > fim),
    // o elemnto não existe ma lista. O trabalho da recursão para aqui
    if (inicio > fim) {
        printf("\nItem \"%s\" não encontrado na mochila.\n", nomeBuscaBinariaRecursiva);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return -1;
    }

    // Calcula a posição do meio
    // Usar "inicio + (fim - inicio) / 2" é mais seguro contra overflow
    // em vetores extremamente grandes
    int meio = inicio + (fim - inicio) / 2;

    // Criamos uma variavel "resultado" que armazena a comparação das strings usando a função 'strcmp'
    int resultado = strcmp(mochila->nome[meio], nomeBuscaBinariaRecursiva);

    // 1. Se o valor estiver exatamente no meio, encontramos!
    // Este é o CASO BASE 'de sucesso'
    if (resultado == 0){
        printf("\nItem \"%s\" encontrado na posicao %d.\n", mochila->nome[meio], meio);
        printf("\nPressione ENTER para continuar...");
        getchar();
        return meio;
    } 
    // PASSO RECURSIVO (DELEGAÇÃO)
    // Se o elemento do meio for memor que o valor/nomeBuscaBinariaRecursiva, delegamos a busca
    // para a metade direita do vetor/mochila
    else if (resultado < 0) {
        return buscaBinariaRecursiva(mochila, nomeBuscaBinariaRecursiva, meio + 1, fim);
    } 
    // Caso contrário, delegamos a busca para a metade da esquerda
    else {
        return buscaBinariaRecursiva(mochila, nomeBuscaBinariaRecursiva, inicio, meio - 1);
    }
} 

// Função que verifica se a mochila está vazia se tiver retorna para o menu principal
int mochilaVazia(Item *mochila)
{
    if (mochila->quantidade == 0)
    {
        printf("\nA mochila está vazia.");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 1;
    }
    return 0;
}

// Função limpar buffer de entrada
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}