#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define TAM_MAX_NOME 30
#define TAM_MAX_TIPO 20
#define MAX_ITEM 10

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).
enum CriterioOrdenacao
{
    NOME,
    TIPO,
    PRIORIDADE
};

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.
typedef struct
{
    char nome[TAM_MAX_NOME]; // Matriz: 10 linhas (itens), 30 colunas (caracteres por item).
    char tipo[TAM_MAX_TIPO];
    int quantidade;
    int prioridade;
} Componente;

void limparTela();
void exibirMenu(Componente mochila[], int numItens, int ordenadaPorNome);
void inicializarMochila(Componente mochila[], int numItens);
void inserirItemMochila(Componente mochila[], const char *nome, const char *tipo, int prioridade, int quantidade, int *numItens);
void removerItemMochila(Componente mochila[], const char *nome, int *numItens);
void listarItensMochila(const Componente mochila[], int numItens);
void menuDeOrdenacao(Componente mochila[], int numItens, int *ordenadaPorNome, int *comparacoes);
int ordenarMochila(Componente mochila[], int numItens, enum CriterioOrdenacao criterio, int *comparacoes, LARGE_INTEGER *frequencia, LARGE_INTEGER *inicio, LARGE_INTEGER *fim, double *tempo);
void buscarBinaria(Componente mochila[], const char *nomeBusca, int numItens, int ordenadaPorNome);
int verificarItensFuga(Componente mochila[], int numItens, int ordenadaPorNome);
int verificaVazia(Componente mochila[], int numItens);

void limparBufferEntrada();

int main()
{
    LARGE_INTEGER frequencia, inicio, fim;
    double tempo;

    // Vetor mochila:
    // Armazena até 10 itens coletados.
    Componente mochila[MAX_ITEM];

    // Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho),
    // ordenadaPorNome (para controle da busca binária).
    int numItens = 0;
    int comparacoes = 0;
    int ordenadaPorNome = 0;

    inicializarMochila(mochila, numItens);

    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    int opcao;
    do
    {
        limparTela();
        exibirMenu(mochila, numItens, ordenadaPorNome);
        scanf("%d", &opcao);
        limparBufferEntrada();

        // A estrutura switch trata cada opção chamando a função correspondente.
        switch (opcao)
        {
        case 1:
            char nome[TAM_MAX_NOME], tipo[TAM_MAX_TIPO];
            int prioridade, quantidade;

            limparTela();
            printf("--- Coletando novo componente ---\n");
            printf("\nAdicionar Componente: ");
            fgets(nome, TAM_MAX_NOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("Tipo (Estrutural, Eletrônica, Energia): ");
            fgets(tipo, TAM_MAX_TIPO, stdin);
            tipo[strcspn(tipo, "\n")] = '\0';

            printf("Prioridade de Montagem (1 a 5): ");
            scanf("%d", &prioridade);

            printf("Quantidade: ");
            scanf("%d", &quantidade);
            limparBufferEntrada();

            inserirItemMochila(mochila, nome, tipo, prioridade, quantidade, &numItens);
            break;
        case 2:
            if (verificaVazia(mochila, numItens) == 1)
            {
                limparTela();
                char nome[TAM_MAX_NOME];
                printf("\n--- Remover Item ---");
                printf("\nDigite o nome do Componente a ser removido: ");
                fgets(nome, TAM_MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItemMochila(mochila, nome, &numItens);
            }
            break;
        case 3:
            if (verificaVazia(mochila, numItens) == 1)
            {
                limparTela();
                listarItensMochila(mochila, numItens);
            }
            break;
        case 4:
            if (verificaVazia(mochila, numItens) == 1)
            {
                limparTela();
                menuDeOrdenacao(mochila, numItens, &ordenadaPorNome, &comparacoes);
            }
            break;
        case 5:
            if (verificaVazia(mochila, numItens) == 1)
            {
                limparTela();
                // A ordenação e busca binária exigem que os dados estejam bem organizados.
                char nomeBusca[TAM_MAX_NOME];
                limparTela();
                printf("--- Busca Binária por Nome ---\n");
                printf("\nDigite o nome do componente para busca: ");
                fgets(nomeBusca, TAM_MAX_NOME, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarBinaria(mochila, nomeBusca, numItens, ordenadaPorNome);
            }
            break;

        case 6:
            // Chama a função e verifica o retorno
            if (verificarItensFuga(mochila, numItens, ordenadaPorNome))
            {
                limparTela();
                printf("\nOperação de fuga iniciada com sucesso. Saindo do sistema...\n");
                // O programa prosseguirá para fechar o do-while
            }
            else
            {
                limparTela();
                // Se retornar 0, ele mantém o programa aberto
                printf("\nVoltando ao menu principal...\n");
                opcao = -1; // "Engana" a condição do do-while para não fechar
            }
            break;
        case 0:
            limparTela();
            printf("\nSaindo do programa...\n");
            break;
        default:
            limparTela();
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// inicializarMochila():
void inicializarMochila(Componente mochila[], int numItens)
{
    for (int i = 0; i < MAX_ITEM; i++)
    {
        mochila[i].nome[0] = '\0';
        mochila[i].tipo[0] = '\0';
        mochila[i].prioridade = 0;
    }
}

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.
void limparTela()
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
    }
    printf("\n");
}

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.
void exibirMenu(Componente mochila[], int numItens, int ordenadaPorNome)
{
    printf("\n=========================================================\n");
    printf("     PLANO DE FUGA  - CÓDIGO DA ILHA (NIVEL MESTRE)\n");
    printf("=========================================================\n");
    printf("            Componentes na mochila: %d/%d\n", numItens, MAX_ITEM);
    printf("          Status da ordenação por nome: %s\n\n", ordenadaPorNome ? "Sim" : "Não");
    printf("1. Adicionar Componente\n");
    printf("2. Descartar Componente\n");
    printf("3. Listar Componentes (Invetário)\n");
    printf("4. Organizar Mochila (Ordenar Componentes)\n");
    printf("5. Buscar Binária por Componente-chave (Nome)\n");
    printf("6. Ativar torre de fuga (Sair)\n");
    printf("0. Sair\n");
    printf("=========================================================\n");
    printf("Escolha uma opção: ");
}

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserirItemMochila(Componente mochila[], const char *nome, const char *tipo, int prioridade, int quantidade, int *numItens)
{

    int i = *numItens;

    // Copia os dados
    strncpy(mochila[i].nome, nome, TAM_MAX_NOME - 1);
    mochila[i].nome[TAM_MAX_NOME - 1] = '\0';

    strncpy(mochila[i].tipo, tipo, TAM_MAX_TIPO - 1);
    mochila[i].tipo[TAM_MAX_TIPO - 1] = '\0';

    mochila[i].prioridade = prioridade;
    mochila[i].quantidade = quantidade; // Armazena a quantidade do item

    (*numItens)++;
    limparTela();
    printf("\nComponente %s adicionado\n", mochila[i].nome);

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void removerItemMochila(Componente mochila[], const char *nome, int *numItens)
{
    int i, pos = -1;

    for (i = 0; i < MAX_ITEM; i++)
    {
        if (strcmp(mochila[i].nome, nome) == 0)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
    {
        printf("\nErro: Item não encontrado na mochila!\n");
        return;
    }

    // Fechar a lacuna
    for (i = pos; i < *numItens - 1; i++)
    {
        // Em C, você pode copiar a struct inteira com '='
        // mochila[i] = mochila[i + 1];
        strcpy(mochila[i].nome, mochila[i + 1].nome);
        strcpy(mochila[i].tipo, mochila[i + 1].tipo);
        mochila[i].quantidade = mochila[i + 1].quantidade;
        mochila[i].prioridade = mochila[i + 1].prioridade;
    }

    (*numItens)--;
    printf("\nItem removido: %s\n", nome);
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.
void listarItensMochila(const Componente mochila[], int numItens)
{
    if (numItens == 0)
    {
        printf("\nA mochila está vazia.\n");
        return;
    }
    printf("\n              --- Itens na Mochila (%d/%d) ---\n", numItens, MAX_ITEM);
    printf("-----------------------------------------------------------------------\n");
    printf("%-20s | %-22s | %-10s | %-10s\n", "NOME", "TIPO", "QUANTIDADE", "PRIORIDADE");
    printf("-----------------------------------------------------------------------\n");
    for (int i = 0; i < numItens; i++)
    {
        printf("%-20s | %-22s | %-10d | %-10d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
    printf("-----------------------------------------------------------------------\n");

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).
void menuDeOrdenacao(Componente mochila[], int numItens, int *ordenadaPorNome, int *comparacoes)
{
    int opcao;

    printf("\n--- Estrategia de Organização ---\n");
    printf("1. Por Nome\n");
    printf("2. Por Tipo\n");
    printf("3. Por Prioridade de montagem\n");
    printf("0. Cancelar\n");
    printf("Escolha o critério de ordenação: ");

    if (scanf("%d", &opcao) != 1)
    {
        limparBufferEntrada();
        printf("\nEntrada inválida!\n");
        return;
    }
    limparBufferEntrada();

    // Declaramos as variáveis necessárias para o tempo AQUI, fora do switch
    LARGE_INTEGER frequencia, inicio, fim;
    double tempo;

    switch (opcao)
    {
    case 1:
    case 2:
    case 3:
    {
        enum CriterioOrdenacao criterio = (enum CriterioOrdenacao)(opcao - 1);

        // Chama a função passando os endereços das variáveis de tempo e comparacoes
        int sucesso = ordenarMochila(mochila, numItens, criterio, comparacoes, &frequencia, &inicio, &fim, &tempo);

        if (sucesso)
        {
            limparTela();
            *ordenadaPorNome = (criterio == NOME) ? 1 : 0;

            // Determina o nome do critério para exibição
            const char *nomeCriterio;
            switch (criterio)
            {
            case NOME:
                nomeCriterio = "Nome";
                break;
            case TIPO:
                nomeCriterio = "Tipo";
                break;
            case PRIORIDADE:
                nomeCriterio = "Prioridade";
                break;
            default:
                nomeCriterio = "Desconhecido";
                break;
            }

            printf("Mochila organizada com sucesso por: %s\n", nomeCriterio);
            printf("\nQuantidade de comparações: %d\n", *comparacoes);
            printf("\nTempo de execucao: %.8f segundos\n", tempo);
        }
        else
        {
            limparTela();
            printf("\nNão foi possível ordenar (itens insuficientes).\n");
        }
        break;
    }

    case 0:
        printf("\nVoltando ao menu principal...\n");
        break;

    default:
        limparTela();
        printf("\nOpção inválida! Tente novamente.\n");
        break;
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)
// - Por prioridade (da mais alta para a mais baixa)
// Altere o protótipo para receber um ponteiro de int
int ordenarMochila(Componente mochila[], int numItens, enum CriterioOrdenacao criterio, int *comparacoes, LARGE_INTEGER *frequencia, LARGE_INTEGER *inicio, LARGE_INTEGER *fim, double *tempo)
{
    if (numItens <= 1)
        return 0;

    QueryPerformanceFrequency(frequencia); // Sem '&', pois já é um ponteiro
    QueryPerformanceCounter(inicio);       // Sem '&'

    *comparacoes = 0;
    int i, j;
    Componente chave;

    for (i = 1; i < numItens; i++)
    {
        chave = mochila[i];
        j = i - 1;

        while (j >= 0)
        {
            (*comparacoes)++;
            int condicao = 0;
            if (criterio == NOME && strcmp(mochila[j].nome, chave.nome) > 0)
                condicao = 1;
            else if (criterio == TIPO && strcmp(mochila[j].tipo, chave.tipo) > 0)
                condicao = 1;
            else if (criterio == PRIORIDADE && mochila[j].prioridade < chave.prioridade)
                condicao = 1; // O item anterior é menor, então trazemos a chave para trás

            if (condicao)
            {
                mochila[j + 1] = mochila[j];
                j--;
            }
            else
            {
                break;
            }
        }
        mochila[j + 1] = chave;
    }

    QueryPerformanceCounter(fim); // Sem '&'

    // Calcula o tempo usando a aritmética de ponteiros correta
    *tempo = (double)(fim->QuadPart - inicio->QuadPart) / frequencia->QuadPart;

    return 1;
}

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
void buscarBinaria(Componente mochila[], const char *nomeBusca, int numItens, int ordenadaPorNome)
{
    if (!ordenadaPorNome)
    {
        limparTela();
        printf("\nErro: A mochila precisa estar ordenada por NOME para a busca binária!\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    int inicio = 0, fim = numItens - 1;
    int encontrado = -1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        // Armazena a comparação das strings na variavel resultado
        int resultado = strcmp(mochila[meio].nome, nomeBusca);

        if (resultado == 0)
        {
            encontrado = meio;
            break;
        }
        if (resultado < 0)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    if (encontrado != -1)
    {
        limparTela();
        printf("\nItem encontrado: %s | Quantidade: %d\n", mochila[encontrado].nome, mochila[encontrado].quantidade);
        printf("\nPressione ENTER para continuar...");
        getchar();
    }
    else
    {
        limparTela();
        printf("\nItem não encontrado.\n");
    }
}

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- FUNÇÃO verificarItensFuga(); ---
int verificarItensFuga(Componente mochila[], int numItens, int ordenadaPorNome)
{
    if (verificaVazia(mochila, numItens) == 1)
    {

        // 1. Validação da ordenação (Regra de Negócio)
        if (!ordenadaPorNome)
        {
            limparTela();
            printf("\n[ERRO DE SEGURANÇA]: A mochila não está ordenada por NOME!\n");
            printf("\nA ordenação é um protocolo obrigatório antes da fuga.\n");
            printf("\nPressione ENTER para voltar e realizar a ordenação...");
            getchar();
            return 0; // Fuga negada
        }
    }

    // 2. Lista de itens essenciais (facilitando a manutenção)
    char *essenciais[] = {"Chave Mestre", "Placa Mae", "Radio Transmissor", "Gerador Portatil", "Mapa de Rotas"};
    int itensEncontrados = 0;

    // 3. Verificação dos itens
    for (int i = 0; i < 5; i++) // Para cada item da lista essencial
    {
        int itemAchado = 0;
        for (int j = 0; j < numItens; j++) // Percorre a mochila
        {
            if (strcmp(mochila[j].nome, essenciais[i]) == 0 && mochila[j].prioridade == 5)
            {
                itemAchado = 1;
                break;
            }
        }
        if (itemAchado)
            itensEncontrados++;
    }

    // 4. Retorno do status
    if (itensEncontrados == 5)
    {
        limparTela();
        printf("\nSTATUS: TODOS OS 5 ITENS ESSENCIAIS COLETADOS!\n");
        printf("Protocolo de fuga validado com sucesso. O helicóptero está a caminho!\n");
        return 1; // Fuga autorizada
    }
    else
    {
        limparTela();
        printf("\nSTATUS: FUGA NEGADA! Faltam %d item(ns) essenciais na mochila.\n", 5 - itensEncontrados);
        printf("Certifique-se de que os itens possuem prioridade 5.\n");
        printf("Pressione ENTER para voltar ao menu...");
        getchar();
        return 0; // Fuga negada
    }
}

int verificaVazia(Componente mochila[], int numItens)
{
    if (numItens == 0)
    {
        limparTela();
        printf("\nA mochila está vazia.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return 0;
    }
    return 1;
}