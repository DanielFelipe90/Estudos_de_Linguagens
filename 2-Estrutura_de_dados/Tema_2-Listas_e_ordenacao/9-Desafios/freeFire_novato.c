/* Sua missÃ£o Ã© construir um sistema de inventÃ¡rio que simule a mochila de loot inicial do jogador.
Para isso, vocÃª criarÃ¡ uma struct chamada Item, que armazenarÃ¡ informaÃ§Ãµes essenciais de cada objeto coletado.
 O sistema permitirÃ¡ que o jogador cadastre, remova, liste e busque por itens dentro da mochila.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 30
#define TAM_MAX_TIPO 20
#define MAX_ITEM 10

/* Requisitos funcionais

 Confira as principais funcionalidades do sistema a serem implementadas:
1. CriaÃ§Ã£o da struct: definir uma struct chamada Item com os campos char nome[30], char tipo[20] e int quantidade. */
// Estrutura que representa uma estrutura estÃ¡tica de lista d strings.
typedef struct
{
    char nome[MAX_ITEM][TAM_MAX_NOME]; // Matriz: 10 linhas (itens), 30 colunas (caracteres por item).
    char tipo[MAX_ITEM][TAM_MAX_TIPO]; //
    int quantidadeItem[3];             //
    int quantidade;                    // Este Ã© nosso contador de controle. Ele informa quantos itens estÃ£o realmente armazenados na lista.
} Item;

// --- PROTOTIPOS DAS FUNÃÃES ---

// --- FunÃ§Ã£o de inicializaÃ§Ã£o da MOCHILA DO FREE FIRE ---
// FunÃ§Ãµes da lista estÃ¡tica
// Essa funÃ§Ã£o prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como zero, indicando que a lista estÃ¡ vazia.
// Recebemos um ponteiro (*item) para modificar a variÃ¡vel original passada para a funÃ§Ã£o.
void inicializarMochila(Item *mochila);

/* 2. Cadastro de itens: o sistema deve permitir que o jogador cadastre atÃ© 10 itens informando nome,
tipo (ex: arma, muniÃ§Ã£o e cura) e quantidade. */
// --- FunÃ§Ã£o de cadastro de itens ---
void inserirItemMochila(Item *mochila, const char *nome, const char *tipo, int quantidadeItem);

/* 3. RemoÃ§Ã£o de itens: permitir que o jogador exclua um item da mochila, informando seu nome. */
// --- FunÃ§Ã£o de remoÃ§Ã£o de itens ---
void removerItemMochila(Item *mochila, const char *nome);

/* 4. Listagem dos itens registrados com seus dados: o que deve ocorrer apÃ³s cada operaÃ§Ã£o. */
void listarItensMochila(const Item *mochila);

/* 5. Busca sequencial: implementar uma funÃ§Ã£o de busca sequencial que localize um item na mochila com
base no nome e exiba seus dados. */
void buscarItemMochila(Item *mochila, const char *nome);

// 6. FunÃ§Ã£o que exibe o menu da MOCHILA DO FREE FIRE
void menuMochila(Item *mochila);

// 7. FunÃ§Ã£o limpar buffer de entrada
void limparBufferEntrada();

// FunÃ§Ã£o principal (main)
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
        printf("4. Buscar Item\n");
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
            char nome[TAM_MAX_NOME];
            printf("\n--- Remover Item ---");
            printf("\nDigite o nome do item a ser removido: ");
            fgets(nome, TAM_MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';
            removerItemMochila(&mochila, nome);
            break;
        }
        case 3:
            listarItensMochila(&mochila);
            break;
        case 4:
            char nomeBusca[TAM_MAX_NOME];
            printf("Digite o nome do item a ser buscado: ");
            fgets(nomeBusca, TAM_MAX_NOME, stdin);
            nomeBusca[strcspn(nomeBusca, "\n")] = 0; // Remove o \n do enter
            // Chama a funÃ§Ã£o passando o que foi lido
            buscarItemMochila(&mochila, nomeBusca);
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

// --- FunÃ§Ã£o para inicializaÃ§Ã£o da lista de itens - MOCHILA FREE FIRE ---
void inicializarMochila(Item *mochila)
{
    mochila->quantidade = 0;
}

// --- FunÃ§Ã£o para inserir um novo item na lista estÃ¡tica ---
void inserirItemMochila(Item *mochila, const char *nome, const char *tipo, int quantidadeItem)
{
    // 1. Primeiro, tenta buscar se o item jÃ¡ existe
    for (int i = 0; i < mochila->quantidade; i++)
    {
        if (strcmp(mochila->nome[i], nome) == 0)
        {
            mochila->quantidadeItem[i] += quantidadeItem; // Apenas atualiza a quantidade existente
            printf("Quantidade de %s atualizada!\n", nome);
            return;
        }
    }
    // Primeiro, ela verifica se lista->quantidade jÃ¡ atingiu TAM_MAX.
    // Se sim, a lista estÃ¡ cheia e a funÃ§Ã£o retorna.
    if (mochila->quantidade >= MAX_ITEM)
    {
        printf("\nLista está cheia. Não é possívelinserir mais itens.\n");
        return;
    }
    // A inserÃ§Ã£o ocorre na primeira "linha" livre da matriz
    // Para strings, nÃ£o podemos fazer "lista->[i] = texto;", porque em c nÃ£o se pode atribuir vetores/strings
    // diretamente; por isso, utilizamos a funÃ§Ã£o strcpy() para copiar os caracteres para a posiÃ§Ã£o correta.
    strcpy(mochila->nome[mochila->quantidade], nome);
    strcpy(mochila->tipo[mochila->quantidade], tipo);

    //Adiciona a quantidade
    mochila->quantidadeItem[mochila->quantidade] = quantidadeItem;

    // ApÃ³s a inserÃ§Ã£o bem-sucedida, incrementamos o contador de itens da lista.
    mochila->quantidade++;
    printf("\nItem \"%s\" adicionado com sucesso.\n", nome);

    listarItensMochila(mochila);
}

// --- FunÃ§Ã£o para remover um item da lista estÃ¡tica) ---
void removerItemMochila(Item *mochila, const char *nome)
{
    int i, pos = -1;
    // Para comparar strings usamos strcmp(). Retorna 0 se forem iguais.
    // A funÃ§Ã£o percorre os itens em uso na lista (de zero atÃ© quantidade).
    // Para comparar strings, usamos strcmp(string1, string2).
    // Essa funÃ§Ã£o retorna zero se as strings forem idÃªnticas. Se encontrar, guarda a posiÃ§Ã£o (pos)  e para o loop.
    for (i = 0; i < mochila->quantidade; i++)
    {
        if (strcmp(mochila->nome[i], nome) == 0)
        {
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: se o loop terminar e pos continuar -1, o item nÃ£o foi encontrado.
    if (pos == -1)
    {
        printf("\nItem \"%s\" não encontrado na Mochila.\n", nome);
        return;
    }

    // Fechar a lacuna: Se removemos um item do meio da lista, criamos um 'buraco'.
    // Para preenchÃª-lo, movemos todos os itens subsequentes uma posiÃ§Ã£o para a esquerda.
    // O loop for comeÃ§a na posiÃ§Ã£o do item removido e copia cada item i+1 para a posiÃ§Ã£o i.
    // Deslocar os elemntos posteriores para a esquerda usando strcpy.
    for (i = pos; i < mochila->quantidade - 1; i++)
    {
        strcpy(mochila->nome[i], mochila->nome[i + 1]);
        strcpy(mochila->tipo[i], mochila->tipo[i + 1]);
    }

    // AtualizaÃ§Ã£o do contador: Finalmente, quantidade Ã© decrementado para refletir que a lista tem um item a menos.
    mochila->quantidade--;
    printf("\nItem %s removido com sucesso da mochila.\n", nome);

    listarItensMochila(mochila);
}

// --- FunÃ§Ã£o para listar itens da MOCHILA DO FREE FIRE ---
void listarItensMochila(const Item *mochila)
{
    if (mochila->quantidade == 0)
    {
        printf("\nA mochila está vazia.\n");
        return;
    }
    printf("\n            --- Itens na Mochila (%d/10) ---\n", mochila->quantidade);
    printf("----------------------------------------------------------------\n");
    printf("%-20s | %-22s | %-10s\n","NOME", "TIPO", "QUANTIDADE");
    printf("----------------------------------------------------------------\n");
    
    for (int i = 0; i < mochila->quantidade; i++)
    {
        printf("%-20s | %-22s | %-10d\n", mochila->nome[i], mochila->tipo[i], mochila->quantidadeItem[i]);
    }
    printf("----------------------------------------------------------------\n");

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// --- FunÃ§Ã£o para buscar itens na MOCHILA DO FREE FIRE ---
void buscarItemMochila(Item *mochila, const char *nome)
{
    int i;
    int encontrado = 0; // Usar int para flags Ã© mais comum em C

    // ComeÃ§amos um loop do inÃ­cio (Ã­ndice 0) atÃ© o fim da lista
    for (i = 0; i < mochila->quantidade; i++)
    {
        // Comparamos o nome buscado com o nome guardado na posiÃ§Ã£o i
        if (strcmp(mochila->nome[i], nome) == 0)
        {
            printf("\nItem \"%s\" encontrado na posição %d.\n", mochila->nome[i], i);
            printf("Tipo: %s | Quantidade: %d\n", mochila->tipo[i], mochila->quantidadeItem[i]);
            encontrado = 1;
            break; 
        }
    }

    // Caso o loop termine e o item nÃ£o tenha sido encontrado
    if (!encontrado)
    {
        printf("\nItem \"%s\" nao encontrado na mochila.\n", nome);
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// FunÃ§Ã£o limpar buffer de entrada
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}