// Prática: Sistema de Biblioteca - Parte 3
// Objetivo desta parte:
// Modularizar o código com funções especializadas, aplicando boas práticas.
// - Passagempor valor(para exibição) e por referência (para modificação).
// - Funções para cada funcionalidade principal do sistema.
// - A função main() se torna um orquestrador, chamando as outras funções.

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

// --- Protótipos das funções ---
// Declar as funções aqui permite que a 'main()' as chame antes de suas definições completas.
void limparBufferEntrada();
void exibirMenu();
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros);
void listarLivros(const struct Livro *biblioteca, int totalLivros);
void realizarEmprestimo(struct Livro *biblioteca, struct Emprestimo *emprestimo, int totalLivros, int *totalEmprestimos);
void listarEmprestimos(struct Livro *biblioteca, struct Emprestimo *emprestimos, int totalEmprestimos);
void devolverLivro(struct Livro *biblioteca, struct Emprestimo *emprestimos, int totalLivros, int *totalEmprestimos);
void alocarMemoriaBiblioteca(struct Livro **livros, struct Emprestimo **emprestimos);
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos);

// Função Principal (main) ---
// Agora , amain é muito mais limpa. Ela aloca memória, controla o menu
// e delega as tarefas para as funções especializadas.
int main()
{

    struct Livro *biblioteca = NULL;
    struct Emprestimo *emprestimos = NULL;

    // Alocamos a memória para os arrays de livros e empréstimos usando uma função dedicada.
    // Passamos o endereço dos ponteiros usando '&'
    alocarMemoriaBiblioteca(&biblioteca, &emprestimos);

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    // --- Laço principal do menu ---
    do
    {
        exibirMenu();
        // Lê a opção do usuario
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        // --- Processamento da opção ---
        switch (opcao)
        {
        // Cadastro de livro
        case 1:
            // Passamos o endereço de 'totalLIvros' "&" para que a função possa modificar seu valor.
            cadastrarLivro(biblioteca, &totalLivros);
            break;

        // Listar livros
        case 2:
            // Passamos apenas o valor de 'totalLivros', pois a função só precisa ler
            listarLivros(biblioteca, totalLivros);
            break;

        // Realizar Emprétimos
        case 3:
            realizarEmprestimo(biblioteca, emprestimos, totalLivros, &totalEmprestimos);
            break;

        // Lista de empréstimos
        case 4:
            listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
            break;

        case 5:
            devolverLivro(biblioteca, emprestimos, totalLivros, &totalEmprestimos);
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

    // Chama a função dedicada para liberar a memória alocada antes de sair do programa.
    liberarMemoria(biblioteca, emprestimos);

    return 0;
}

// --- Implementação das funções ---

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- Função para exibir o menu ---
void exibirMenu()
{
    printf("=====================================================\n");
    printf("             BIBLIOTECA - PARTE 2\n");
    printf("=====================================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar Empréstimos\n");
    printf("4 - Lista Empréstimos\n");
    printf("5 - Devolver livros\n");
    printf("0 - Sair\n");
    printf("Escolha uma Opção:");
}

// --- Função para cadastrar livros ---
void cadastrarLivro(struct Livro *biblioteca, int *totalLivros)
{
    printf("\n--- Cadastro de novo livro ---\n");

    if (*totalLivros < MAX_LIVROS)
    {
        int indice = *totalLivros; // Usa o valor apontado pelo ponteiro para o indice.
        printf("Digite o nome do livro: ");
        fgets(biblioteca[indice].nome, TAM_STRING, stdin);

        printf("Digite o autor: ");
        fgets(biblioteca[indice].autor, TAM_STRING, stdin);

        printf("Digite a editora: ");
        fgets(biblioteca[indice].editora, TAM_STRING, stdin);

        biblioteca[indice].nome[strcspn(biblioteca[indice].nome, "\n")] = '\0';
        biblioteca[indice].autor[strcspn(biblioteca[indice].autor, "\n")] = '\0';
        biblioteca[indice].editora[strcspn(biblioteca[indice].editora, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d", &biblioteca[indice].edicao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        // Ao cadastrar, o livro automaticamente se torna disponível para empréstimo.
        biblioteca[indice].disponivel = 1;

        (*totalLivros)++; // Incrementa o valor da variavel original main.
        printf("Livro cadastrado com sucesso!\n");
    }
    else
    {
        printf("Capacidade máxima de livros atingida. Não é possível cadastrar mais livros.\n");
    }

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Aguarda o usuário pressionar Enter
}

// --- Função para listar livros ---
void listarLivros(const struct Livro *biblioteca, int totalLivros)
{
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
}

// --- Função para realizar emprestimo de livros ---
void realizarEmprestimo(struct Livro *biblioteca, struct Emprestimo *emprestimos, int totalLivros, int *totalEmprestimos)
{
    printf("--- Realizar Empréstimo ---\n\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS)
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
            printf("Nenhum livro disponivel para empréstimo.\n");
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
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0'; // Remove o

                // Registra o empréstimo
                emprestimos[*totalEmprestimos].indiceLivro = indice;

                // Atualiza o status do livro para emprestado.
                biblioteca[indice].disponivel = 0;

                (*totalEmprestimos)++;
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
}

// --- Função para listar emprestimo de livros ---
void listarEmprestimos(struct Livro *biblioteca, struct Emprestimo *emprestimos, int totalEmprestimos)
{
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
}

// --- Função para devolver livros ---
void devolverLivro(struct Livro *biblioteca, struct Emprestimo *emprestimos, int totalLivros, int *totalEmprestimos)
{
    printf("--- Devolver Livro ---\n\n");

    if (*totalEmprestimos == 0)
    {
        printf("Nenhum empréstimo registrado no sistema no momento.\n");
    }
    else
    {
        char nomeBusca[TAM_STRING];
        printf("Digite o nome do usuário que está devolvendo o livro: ");
        fgets(nomeBusca, TAM_STRING, stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Limpa o \n do teclado

        int encontrado = -1;

        // 1. Busca o empréstimo pelo nome do usuário
        for (int i = 0; i < *totalEmprestimos; i++)
        {
            if (strcmp(emprestimos[i].nomeUsuario, nomeBusca) == 0)
            {
                encontrado = i; // Guarda o índice do empréstimo encontrado
                break;          // Interrompe a busca ao achar o primeiro
            }
        }

        // 2. Verifica o resultado da busca
        if (encontrado == -1)
        {
            printf("\nNenhum empréstimo ativo encontrado para o usuário: %s\n", nomeBusca);
        }
        else
        {
            // Recupera qual livro está associado a esse empréstimo
            int idxLivro = emprestimos[encontrado].indiceLivro;

            // 3. Atualiza o status do Livro para Disponível
            biblioteca[idxLivro].disponivel = 1;

            // 4. Remove o registro do empréstimo deslocando os demais registros
            for (int j = encontrado; j < *totalEmprestimos - 1; j++)
            {
                emprestimos[j] = emprestimos[j + 1];
            }
            (*totalEmprestimos)--;

            printf("\nO livro %s do autor %s foi devolvido por %s!. Obrigado\n", biblioteca[idxLivro].nome, biblioteca[idxLivro].autor, nomeBusca);
        }
    }

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Aguarda o usuário pressionar Enter
}

// --- Função para alocar memoria para biblioteca ---
// Recebe o endereço dos ponteiros da main usando '**'
void alocarMemoriaBiblioteca(struct Livro **livros, struct Emprestimo **emprestimos)
{

    *livros = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
    *emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    if (*livros == NULL || *emprestimos == NULL)
    {
        printf("Erro: Falha crítica de alocação de memória.\n");
        exit(1); // Encerra o programa se faltar memória
    }
}

// --- Função para liberar memória alocada ---
void liberarMemoria(struct Livro *biblioteca, struct Emprestimo *emprestimos)
{
    free(biblioteca);
    free(emprestimos);
    printf("Memória liberada com sucesso!\n");
}