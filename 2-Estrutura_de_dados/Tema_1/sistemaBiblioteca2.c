// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 2

// OBJETIVO DESTA PARTE:
// Adicionar a funcionalidade de empréstimo e introduzir alocação dinâmica.
// - Os arrays de livros e empréstimos são alocados com malloc/calloc.
// - Nova struct para emprétimo.
// - Liberação de memória com free() ao final do programa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// --- Constantes globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100
#define MAX_EMPRESTIMOS 100 // Definimos uma capacidade para empréstimos

// --- Definição das estruturas (structs) ---
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponível, 0 para emprestado
};

struct Emprestimo
{
    int indiceLivro; // Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função Principal (main) ---
int main()
{
    // 1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // Agora, em vez de arrays estáticos, vamos usar ponteiros
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    // Usamos calloc para array de livros. calloc (num_elementos, tamanho_de_cada_elemento)
    // Vantagem: inicializa toda a memória com zeros. Isso significa que 'disponivel' já
    // começará como 0 (falso), e precisamos definir como 1 (verdadeiro) para os livros disponíveis.
    biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para array de empréstimos. malloc (tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // Verificação: É crucial verificar se a alocação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL)
    {
        printf("Erro: Falha ao alocar memória./n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    // --- Laço principal do menu ---
    do
    {
        // --- Exibe o menu de opções ---
        printf("=====================================================\n");
        printf("             BIBLIOTECA - PARTE 2\n");
        printf("=====================================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar emprétimo\n");
        printf("4 - Lista Empréstimos\n");
        printf("0 - Sair\n");
        printf("Escolha uma Opção:");

        // Lê a opção do usuario
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        // --- Processamento da opção ---
        switch (opcao)
        {
        // Cadastro de livro
        case 1:
            printf("\n--- Cadastro de novo livro ---\n");

            if (totalLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite a edição: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

                // Ao cadastrar, o livro automaticamente se torna disponível para empréstimo.
                biblioteca[totalLivros].disponivel = 1;

                totalLivros++;
                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Capacidade máxima de livros atingida. Não é possível cadastrar mais livros.\n");
            }

            printf("\nPressione Enter para continuar...\n");
            getchar(); // Aguarda o usuário pressionar Enter

            break;

        // Listar livros
        case 2:
            printf("\n\n--- Lista de Livros Cadastrados ---\n\n");
            if (totalLivros == 0)
            {
                printf("Nenhum livro cadastrado.\n");
                printf("\nPressione Enter para continuar...\n");
                getchar(); // Aguarda o usuário pressionar Enter
            }
            else
            {
                for (int i = 0; i < totalLivros; i++)
                {
                    printf("Livro %d:\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n\n", biblioteca[i].edicao);
                }

                // A pausa é crucial para que o usuário tenha tempo de ler a lista antes de voltar ao menu
                printf("\nPressione Enter para continuar...\n");
                getchar(); // Aguarda o usuário pressionar Enter
            }
            break;

        // Realizar Emprétimos
        case 3:
            printf("--- Realizar Empréstimo ---\n\n");

            if (totalEmprestimos >= MAX_EMPRESTIMOS)
            {
                printf("Limite de empréstimos atingido!\n");
            }
            else
            {
                printf("Livros disponiveis:\n");
                int disponiveis = 0;
                for (int i = 0; i < totalLivros; i++)
                {
                    if (biblioteca[i].disponivel)
                    {
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        disponiveis++;
                    }
                }

                if (disponiveis == 0)
                {
                    printf("Nenhum livro disponivel para emprétimo.\n");
                }
                else
                {
                    printf("\nDigite o número do livro que deseja pegar emprestado: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limparBufferEntrada();

                    int indice = numLivro - 1; // Converte para o indice do array (a a N-1).

                    // Validação da escolha do usuário.
                    if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel)
                    {
                        printf("Digite o nome do usuário que está pegando o livro: ");
                        fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0'; // Remove o

                        // Registra o empréstimo
                        emprestimos[totalEmprestimos].indiceLivro = indice;

                        // Atualiza o status do livro para emprestado.
                        biblioteca[indice].disponivel = 0;

                        totalEmprestimos++;
                        printf("Empréstimo realizado com sucesso!\n");
                    }
                    else
                    {
                        printf("\nNúmero de livro inválido ou livro indisponivel.\n");
                    }
                }
            }

            printf("\nPressione Enter para continuar...\n");
            getchar(); // Aguarda o usuário pressionar Enter

            break;

        // Lista de empréstimos
        case 4:
            printf("--- Lista de Emprétimos ---\n\n");
            if (totalEmprestimos == 0)
            {
                printf("Nenhum empréstimo realizado.\n");
            }
            else
            {
                for (int i = 0; i < totalEmprestimos; i++)
                {
                    int indiceLivro = emprestimos[i].indiceLivro;
                    printf("------------------------------------\n");
                    printf("Empréstimo %d\n", i + 1);
                    printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                }
                printf("------------------------------------\n");
            }

            printf("\nPressione Enter para continuar...\n");
            getchar(); // Aguarda o usuário pressionar Enter
            break;

        // Opção de sair
        case 0:
            printf("Saindo do sistema. Até logo!\n");
            break;

        // Opção inválida
        default:
            printf("Opção inválida. Por favor, escolha uma opção válida.\n");
            printf("\nPressione Enter para continuar...\n");
            getchar(); // Aguarda o usuário pressionar Enter
            break;
        }

    } while (opcao != 0);

    // 2. LIBERAÇÃO DA MEMÓRIA
    // Antes de terminar, é essencial liberar a memória que foi alocada dinamicamente.
    // Isso evita "memory leaks" vazamentos de memória.
    free(biblioteca);
    free(emprestimos);

    printf("Memória liberada com sucesso.\n");

    return 0;
}