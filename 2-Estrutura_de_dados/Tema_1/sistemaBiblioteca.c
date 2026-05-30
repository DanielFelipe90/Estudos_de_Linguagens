#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definição da estrutura (struct) ---
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// ---Função para limpar o buffer de entrada ---
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- Função Principal (main) ---
int main()
{
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laço principal do menu ---
    do
    {
        // --- Exibe o menu de opções ---
        printf("=====================================================\n");
        printf("             BIBLIOTECA - PARTE 1\n");
        printf("=====================================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
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

    // Fim do programa
    return 0;
}