/* Você está criando o protótipo de um sistema para armazenar e consultar os jogadores de um campeonato
on-line. Os jogadores são organizados em um ranking baseado em pontuação (ordem decrescente).
O objetivo é desenvolver um sistema que gerencie pontuações de jogadores em um ranking, permitindo:
Inserção e remoção de jogadores.
Visualização do ranking.
Busca por jogador (nome).
Comparação entre vetores e listas encadeadas.
Teste prático entre busca sequencial e binária (iterativa e recursiva).
O sistema deve aceitar:
Cadastro e remoção de jogadores.
Visualização do ranking.
Busca por nome (com diferentes algoritmos).
Análise comparativa do desempenho das estruturas. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para armazenar os dados do jogador
typedef struct
{
    char nickname[30];
    int score;
} Jogador;

// Estrututa de uma lista encadeada para usar no ranking
typedef struct No
{
    Jogador player;
    struct No *proximo;
} No;

// --- PROTÓTIPOS ---
void inicializarRanking(No **ranking);
void inserirJogador(No **ranking, char *nome, int pontos);
void removerJogador(No **ranking, const char *nomeBusca);
void exibirRanking(const No *ranking);
void buscarJogador(const No *ranking, const char *nomeBusca);
int rankingVazio(const No *ranking);
void liberarMemoria(No *ranking);
void limparBufferEntrada();

// --- MAIN ---
int main()
{
    No *ranking = NULL;
    int opcao;

    do
    {
        printf("\n=========================================================\n");
        printf("        RANKING DE PONTUAÇÃO - FREE FIRE\n");
        printf("=========================================================\n");
        printf("1. Adicionar Player ao ranking\n");
        printf("2. Remover Player do ranking\n");
        printf("3. Exibir Ranking de Pontuação\n");
        printf("4. Buscar Player por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
        {
            char nickname[30];
            int pontos;
            printf("\n--- Insira os dados do Player ---\n");
            printf("Digite o Nome: ");
            fgets(nickname, 30, stdin);
            nickname[strcspn(nickname, "\n")] = '\0';
            printf("Digite a Pontuação: ");
            scanf("%d", &pontos);
            limparBufferEntrada();
            inserirJogador(&ranking, nickname, pontos);
            break;
        }
        case 2:
        {
            if (rankingVazio(ranking) == 0)
            {
                char nickname[30];
                printf("\n--- Remove os dados do jogador ---\n");
                printf("Digite o Nome:");
                fgets(nickname, 30, stdin);
                nickname[strcspn(nickname, "\n")] = '\0';
                removerJogador(&ranking, nickname);
            }
            break;
        }
        case 3:
            if (rankingVazio(ranking) == 0)
            {
                exibirRanking(ranking);
            }
            break;
        case 4:
        {
            if (rankingVazio(ranking) == 0)
            {
                char nomeBusca[30];
                printf("\n--- Buscando player no ranking ---\n");
                printf("Digite o Nome: ");
                fgets(nomeBusca, 30, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = 0;
                buscarJogador(ranking, nomeBusca);
            }
            break;
        }
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(ranking);
    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// --- Função de inicialização do ranking ---
void inicializarRanking(No **ranking)
{
    *ranking = NULL;
}

// --- FUNÇÃO DE INSERIR JOGADOR ---
// USA SELECTION SORT PARA IR INSERINDO EM ORDEM

void inserirJogador(No **ranking, char *nome, int pontos)
{
    // 1. Criar o novo nó
    No *novoNo = (No *)malloc(sizeof(No));
    strcpy(novoNo->player.nickname, nome);
    novoNo->player.score = pontos;

    // 2. Lógica para ORDEM DECRESCENTE (O MAIOR FICA NO TOPO)
    // Se a lista estiver vazia OU o novo score for MAIOR que o primeiro
    if (*ranking == NULL || pontos > (*ranking)->player.score)
    {
        novoNo->proximo = *ranking;
        *ranking = novoNo;
        return;
    }

    // 3. Percorrer a lista para encontrar a posição correta
    No *atual = *ranking;
    while (atual->proximo != NULL && atual->proximo->player.score > pontos)
    {
        atual = atual->proximo;
    }

    // 4. Inserir o novo nó entre 'atual' e 'atual->proximo'
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;

    printf("Jogador '%s' inserido com sucesso.\n", nome);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// --- FUNÇÃO PARA REMOVER JOGADOR DA LISTA ENCADEADA RANKING ---
void removerJogador(No **ranking, const char *nomeBusca)
{
    No *atual = *ranking;
    No *anterior = NULL;

    // 1. Procurar o nó que contém o nome
    while (atual != NULL && strcmp(atual->player.nickname, nomeBusca) != 0)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    // 2. Se o nó não foi encontrado
    if (atual == NULL)
    {
        printf("Jogador '%s' não encontrado.\n", nomeBusca);
        return;
    }

    // 3. Remover o nó:
    // Se for o primeiro (anterior é NULL)
    if (anterior == NULL)
    {
        *ranking = atual->proximo;
    }
    else
    {
        // Se for no meio ou no fim, o anterior aponta para o próximo do atual
        anterior->proximo = atual->proximo;
    }

    free(atual); // Libera a memória!
    printf("\nJogador '%s' removido com sucesso.\n", nomeBusca);
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// --- FUNÇÃO PARA EXIBIR RANKING ---
void exibirRanking(const No *ranking)
{
    No *atual = (No *)ranking;
    int posicao = 1;

    printf("\n             --- Ranking de Pontuação ---\n");
    printf("--------------------------------------------------------------\n");
    printf("| %-22s | %-22s | %-10s |\n", "POSIÇÃO", "PLAYER", "SCORE");
    printf("--------------------------------------------------------------\n");

    while (atual != NULL)
    {
        printf("| %-20d | %-22s | %-10d |\n", posicao, atual->player.nickname, atual->player.score);
        atual = atual->proximo;
        posicao++;
    }
    printf("--------------------------------------------------------------\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// --- FUNÇÃO PARA BUSCAR POR NOME ---
void buscarJogador(const No *ranking, const char *nomeBusca)
{

    No *atual = (No *)ranking;
    int p = 1;
    while (atual)
    {
        if (strcmp(atual->player.nickname, nomeBusca) == 0)
        {
            printf("\n--- Player encontrado ---\n%s está na posição %d com %d pontos.\n", atual->player.nickname, p, atual->player.score);
            printf("\nPressione ENTER para continuar...");
            getchar();
            return;
        }
        atual = atual->proximo;
        p++;
    }
    printf("Jogador não encontrado.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// --- FUNÇÃO DE RANKING VAZIO ---
int rankingVazio(const No *ranking)
{
    if (ranking == NULL)
    {
        printf("\nO ranking está vazia.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 1;
    }
    return 0;
}

// --- FUNÇÃO PARA LIBERAR MEMÓRIA ---
void liberarMemoria(No *ranking)
{
    No *atual = ranking;
    while (atual != NULL)
    {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

// --- FUNÇÃO PARA LIBERAR BUFFER DE ENTRADA ---
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}