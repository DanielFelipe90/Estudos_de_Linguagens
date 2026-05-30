#include <stdio.h>
#include <stdlib.h> // Necessário para rand() e srand()
#include <time.h>   // Necessário para time()

// Desafio Tetris Stack
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.
// 🧩 Nível Novato: Fila de Peças Futuras
//
// - Crie uma struct Peca com os campos: tipo (char) e id (int).
// - Implemente uma fila circular com capacidade para 5 peças.
// - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
// - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
// - Exiba a fila após cada ação com uma função mostrarFila().
// - Use um menu com opções como:
//      1 - Jogar peça (remover da frente)
//      0 - Sair
// - A cada remoção, insira uma nova peça ao final da fila.
/* Atributos das peças
Cada uma possui:
nome: caractere que representa o tipo da peça ('I', 'O', 'T', 'L').
id: número inteiro único que representa a ordem de criação da peça.
Lembre-se: as peças são geradas automaticamente por uma função chamada gerarPeca. */

#define MAX 5

// STRUCT DE DADOS DA PEÇA
typedef struct
{
    char tipo;
    int id;
} Peca;

// STRUCT DA FILA
typedef struct
{
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// --- PROTOTIPOS DAS FUNÇÕES --
void inicializarFila(Fila *f);
int filaCheia(Fila *f);
int filaVazia(Fila *f);
void jogarDequeue(Fila *f, Peca *p);
void inserirPeca(Fila *f, Peca p);
void mostrarFila(Fila *f);
Peca gerarPeca();
void gerarPecaRecursiva(Fila *f, int contador);
void limparBufferEntrada();
void limparTela();
void menu(Fila *f);

int main()
{
    // Declaração da fila
    Fila f;

    srand(time(NULL)); // Importante para aleatoriedade

    // Inicializa a fila
    inicializarFila(&f);

    gerarPecaRecursiva(&f, 0);

    // Mostra a fila antes da remoção
    mostrarFila(&f);

    int opcao;
    do
    {
        menu(&f);
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:
            Peca removida;
            jogarDequeue(&f, &removida);
            mostrarFila(&f);
            break;
        case 2:
            inserirPeca(&f, gerarPeca());
            printf("Pressione ENTER para continuar");
            getchar();
            break;
        case 0:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

// --- IMPLEMENTAÇÕES DAS FUNÇÕES ---

// --- FUNÇÃO INICIALIZAR FILA ---
void inicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// --- FUNÇÃO QUE VERIFICA SE A FILA ESTÁ CHEIA ---
int filaCheia(Fila *f)
{
    return f->total == MAX;
}

// --- FUNÇÃO QUE VERIFICA SE A FILA ESTÁ VAZIA ---
int filaVazia(Fila *f)
{
    return f->total == 0;
}

// --- FUNÇÃO DEQUEUE PARA REMOVER (SIMULAR A JOGADA DA PEÇA) PEÇAS DA FILA ---
void jogarDequeue(Fila *f, Peca *p)
{
    // Se a lista estiver vazia
    if (filaVazia(f))
    {
        limparTela();
        printf("Fila vazia. Não é possível jogar.\n\n");
        printf("Pressione ENTER para continuar");
        getchar();
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    limparTela();
    printf("\n>>> Peça jogada: [%c, %d]\n\n", p->tipo, p->id);
    printf("Pressione ENTER para continuar");
    getchar();
}

// --- FUNÇÃO ENQUEUE PARA INSERIR PEÇAS NA FILA ---
void inserirPeca(Fila *f, Peca p)
{
    // Se a lista estiver cheia
    if (filaCheia(f))
    {
        limparTela();
        printf("Fila cheia. Não é possível inserir.\n\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;

    limparTela();
    printf("Peça inserida com sucesso: [%c, %d]\n\n", p.tipo, p.id);
}

// --- FUNÇÃO MOSTRAR FILA ---
void mostrarFila(Fila *f)
{
    // Se a fila estiver vazia
    if (filaVazia(f))
    {
        printf("\nFila vazia. Não há peças para mostrar.");
    }
    else
    {
        printf("\nFila: ");
        for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX)
        {
            printf("[%c, %d] ", f->itens[idx].tipo, f->itens[idx].id);
        }
    }
    printf("\n");
}

// --- FUNÇÃO PARA GERAR PEÇAS ---
Peca gerarPeca()
{
    static int contadorId = 1; // Mantém o valor entre chamadas
    char tipos[] = {'I', 'O', 'T', 'L'};

    Peca pecaGerada;
    pecaGerada.id = contadorId++;
    pecaGerada.tipo = tipos[rand() % 4]; // Seleciona um índice aleatório de 0 a 3

    return pecaGerada;
}

// --- FUNÇÃO gerarPecaRecursiva() ---
void gerarPecaRecursiva(Fila *f, int contador)
{
    // Caso base: se o contador atingir MAX, paramos a recursão
    if (contador >= MAX)
    {
        return;
    }
    // Ação: insere uma peça
    inserirPeca(f, gerarPeca());
    // Chamada recursiva: passa o contador incrementado
    gerarPecaRecursiva(f, contador + 1);
}

// --- FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA --
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- FUNÇÃO PARA SIMULAR A LIMPEZA DA TELA ---
void limparTela()
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
    }
}

// --- FUNÇÃO PARA MOSTRAR O MENU ---
void menu(Fila *f)
{
    limparTela();
    printf("\n=========================================================\n");
    printf("     TETRIS - FILA DE PEÇAS FUTURAS (NIVEL NOVATO)\n");
    printf("=========================================================\n");
    // Mostra a fila no começo do jogo
    mostrarFila(f);
    printf("\n1. Jogar Peça (dequeue)\n");
    printf("2. Inserir nova Peça (enqueue)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}