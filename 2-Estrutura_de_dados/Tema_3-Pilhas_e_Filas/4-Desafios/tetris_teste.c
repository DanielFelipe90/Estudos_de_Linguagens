#include <stdio.h>
#include <stdlib.h> // Necessário para rand() e srand()
#include <time.h>   // Necessário para time()
// ----------------------------------------------------------------------------------------------------------
// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.
// 🧠 Nível Aventureiro: Adição da Pilha de Reserva
//
// - Implemente uma pilha linear com capacidade para 3 peças.
// - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
// - Permita enviar uma peça da fila para a pilha (reserva).
// - Crie um menu com opção:
//      2 - Enviar peça da fila para a reserva (pilha)
//      3 - Usar peça da reserva (remover do topo da pilha)
// - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
// - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).

/* Requisitos funcionais
Seu programa em C deverá:
Inicializar a fila de peças com um número fixo de elementos (por exemplo, 5).
Inicializar uma pilha de peças reservadas com capacidade limitada (por exemplo, 3).
Seu programa em C também deverá permitir as seguintes ações:
Jogar uma peça: remove a peça da frente da fila (dequeue).
Reservar uma peça: move a peça da frente da fila para o topo da pilha, se houver espaço.
Usar uma peça reservada: remove a peça do topo da pilha, simulando seu uso.
Exibir o estado atual: mostra as peças na fila e na pilha após cada ação.
Atenção: as peças removidas da fila ou da pilha não voltam para o jogo.
A cada ação, uma nova peça é automaticamente gerada e adicionada ao final da fila, mantendo-a sempre cheia. */

// ------------------------- DEFINIÇÃO DO TAMANHO DA FILA E PILHA -----------------------------------------
#define TAM_MAX_FILA 5
#define TAM_MAX_PILHA 3

// --------------------------------- DECLARAÇÃO DAS STRUTS -------------------------------------------------
// STRUCT DE DADOS DA PEÇA
typedef struct
{
    char tipo;
    int id;
} Peca;

// STRUCT DA FILA
typedef struct
{
    Peca itens[TAM_MAX_FILA];
    int inicio;
    int fim;
    int total;
} Fila;

// STRUCT DA PILHA
typedef struct
{
    Peca itens[TAM_MAX_PILHA];
    int topo;
} PilhaPecaReservada;

// ------------------------------------ PROTOTIPOS DAS FUNÇÕES ---------------------------------------------
// Funções de Inicialização da fila e pilha
// Fila
void inicializarFila(Fila *f);
// Pilha
void inicializarPilha(PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Funções de verificação de fila e pilha para ver se estão cheias
// Lista
int filaCheia(Fila *f);
// Pilha
int pilhaCheia(PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Funções de verificação de fila e pilha para ver se estão vazias
// Lista
int filaVazia(Fila *f);
// Pilha
int pilhaVazia(PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Funções de inserção de fila e pilha
// Lista
void inserirPeca(Fila *f, Peca p);
// Pilha
void push(PilhaPecaReservada *p, Peca nova);
// ----------------------------------------------------------------------------------------------------------
// Funções de remoção de fila e pilha
// Lista
void jogarDequeue(Fila *f, Peca *p);
// Pilha
void pop(PilhaPecaReservada *p, Peca *removida);
// ----------------------------------------------------------------------------------------------------------
// Funções para mostrar as fila e pilhas
// Lista
void mostrarFila(Fila *f);
// Pilha
void mostrarPilha(PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Função para reservar Peças
void reservarPeca(Fila *f, PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Função para exibir o menu principal
void menu(Fila *f, PilhaPecaReservada *p);
// ----------------------------------------------------------------------------------------------------------
// Função para gerar peça aleatoria
Peca gerarPeca();
// ----------------------------------------------------------------------------------------------------------
// Função recursiva gerar peça para preencher a lista
void gerarPecaRecursiva(Fila *f, int contador);
// ----------------------------------------------------------------------------------------------------------
// Função Limpar buffer de entrada
void limparBufferEntrada();
// ----------------------------------------------------------------------------------------------------------
// Função limpar tela, simula a limpeza do terminal
void limparTela();
// ----------------------------------------------------------------------------------------------------------
//---------------------------------- FUNÇÃO PRINCIPAL (MAIN) ------------------------------------------------
int main()
{
    // Declaração da fila
    Fila f;
    /* Cria a instância da pilha, ou seja, a variável do tipo Pilha,
    que é o ponteiro 'p' para a estrutura da pilha. */
    PilhaPecaReservada p;
    // Inicializa a fila
    inicializarFila(&f);
    // Inicializa a pilha
    inicializarPilha(&p);
    srand(time(NULL)); // Importante para aleatoriedade
    gerarPecaRecursiva(&f, 0);
    int opcao;
    Peca removida;
    do
    {
        menu(&f, &p);
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao)
        {
        case 1:
            jogarDequeue(&f, &removida);
            printf("\nPeça jogada: [%c, %d]\n\n", removida.tipo, removida.id);
            printf("Pressione ENTER para continuar");
            getchar();
            break;
        case 2:
            reservarPeca(&f, &p);
            break;
        case 3:
            pop(&p, &removida);
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
// ==========================================================================================================
//                           --- IMPLEMENTAÇÕES DAS FUNÇÕES ---
// ==========================================================================================================
// Funções de Inicialização da fila e pilha
// Fila
void inicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}
// Pilha
void inicializarPilha(PilhaPecaReservada *p)
{
    p->topo = -1;
}
// ----------------------------------------------------------------------------------------------------------
// Funções de verificação de fila e pilha para ver se estão cheias
// Lista
int filaCheia(Fila *f)
{
    return f->total == TAM_MAX_FILA;
}
// Pilha
int pilhaCheia(PilhaPecaReservada *p)
{
    return p->topo == TAM_MAX_PILHA - 1;
}
// ----------------------------------------------------------------------------------------------------------
// Funções de verificação de fila e pilha para ver se estão vazias
// Lista
int filaVazia(Fila *f)
{
    return f->total == 0;
}
// Pilha
int pilhaVazia(PilhaPecaReservada *p)
{
    return p->topo == -1;
}
// ----------------------------------------------------------------------------------------------------------
// Funções de inserção de fila e pilha
// Lista
// --- FUNÇÃO ENQUEUE PARA INSERIR PEÇAS NA FILA ---
void inserirPeca(Fila *f, Peca p)
{
    // Se a lista estiver cheia
    if (filaCheia(f))
    {
        // limparTela();
        printf("Fila cheia. Não é possível inserir.\n\n");
        return;
    }
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % TAM_MAX_FILA;
    f->total++;
}
// Pilha
void push(PilhaPecaReservada *p, Peca nova)
{
    if (pilhaCheia(p))
    {
        printf("\nAtingiu o maximo de peças reservadas.\n\n");
        printf("Pressione ENTER para continuar");
        getchar();
        return;
    }
    p->topo++;
    p->itens[p->topo] = nova;
    printf("\nPeça Reservada: [ %c, %d ]\n\n", nova.tipo, nova.id);
    printf("Pressione ENTER para continuar");
    getchar();
}
// ----------------------------------------------------------------------------------------------------------
// Funções de remoção de fila e pilha
// Fila
// --- FUNÇÃO DEQUEUE PARA REMOVER (SIMULAR A JOGADA DA PEÇA) PEÇAS DA FILA ---
void jogarDequeue(Fila *f, Peca *p)
{
    if (filaVazia(f))
    {
        printf("Fila vazia. Não é possível jogar.\n\n");
        printf("Pressione ENTER para continuar");
        getchar();
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_MAX_FILA;
    f->total--;
    inserirPeca(f, gerarPeca());
}
// Pilha
void pop(PilhaPecaReservada *p, Peca *removida)
{
    if (pilhaVazia(p))
    {
        printf("\nNão há peças Reservadas para jogar.\n\n");
        printf("Pressione ENTER para continuar");
        getchar();
        return;
    }
    *removida = p->itens[p->topo];
    p->topo--;
    printf("\nPeça reservada Jogada: [ %c, %d ]\n\n", removida->tipo, removida->id);
    printf("Pressione ENTER para continuar");
    getchar();
}
// ----------------------------------------------------------------------------------------------------------
// Funções para mostrar as fila e pilhas
// Fila
void mostrarFila(Fila *f)
{
    // Se a fila estiver vazia
    if (filaVazia(f))
    {
        printf("\nFila vazia. Não há peças para mostrar.");
    }
    else
    {
        printf("\nFila de Peças: ");
        for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % TAM_MAX_FILA)
        {
            printf("[%c, %d] ", f->itens[idx].tipo, f->itens[idx].id);
        }
    }
    printf("\n");
}
// Pilha
void mostrarPilha(PilhaPecaReservada *p)
{
    // Se a Pilha estiver vazia
    if (pilhaVazia(p))
    {
        printf("\nNão há peças Reservadas.\n");
    }
    else
    {
        printf("\nPilha de Peças Reservadas (topo até a base):\n");
        for (int i = p->topo; i >= 0; i--)
        {
            printf("[%c, %d]\n", p->itens[i].tipo, p->itens[i].id);
        }
    }
    printf("\n");
}
// ----------------------------------------------------------------------------------------------------------
// Função para reservar peças
void reservarPeca(Fila *f, PilhaPecaReservada *p)
{
    if (filaVazia(f))
    {
        printf("\nFila vazia! Não há peça para reservar.\n");
        return;
    }
    Peca pecaReservada;
    // 1. Pega da fila (já gera uma nova peça automaticamente conforme seu jogarDequeue faz)
    jogarDequeue(f, &pecaReservada);
    // 2. Tenta colocar na pilha
    push(p, pecaReservada);
}
// ----------------------------------------------------------------------------------------------------------
// Função para exibir o menu principal
void menu(Fila *f, PilhaPecaReservada *p)
{
    // limparTela();
    printf("\n============================================================\n");
    printf("  ----------- TETRIS STACK (NIVEL AVENTUREIRO) -----------\n");
    printf("============================================================\n");
    mostrarFila(f);
    mostrarPilha(p);
    printf("1. Jogar Peça (dequeue)\n");
    printf("2. Reservar Peça (push)\n");
    printf("3. Jogar Peça Reservada (pop)\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
}
// ----------------------------------------------------------------------------------------------------------
// Função para gerar peça aleatoria
Peca gerarPeca()
{
    static int contadorId = 1; // Mantém o valor entre chamadas
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca pecaGerada;
    pecaGerada.id = contadorId++;
    pecaGerada.tipo = tipos[rand() % 4]; // Seleciona um índice aleatório de 0 a 3
    return pecaGerada;
}
// ----------------------------------------------------------------------------------------------------------
// Função recursiva gerar peça para preencher a lista
void gerarPecaRecursiva(Fila *f, int contador)
{
    // Caso base: se o contador atingir MAX, paramos a recursão
    if (contador >= TAM_MAX_FILA)
    {
        return;
    }
    // Ação: insere uma peça
    inserirPeca(f, gerarPeca());
    // Chamada recursiva: passa o contador incrementado
    gerarPecaRecursiva(f, contador + 1);
}
// ----------------------------------------------------------------------------------------------------------
// Função Limpar buffer de entrada
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
// ----------------------------------------------------------------------------------------------------------
// Função limpar tela, simula a limpeza do terminal
void limparTela()
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
    }
}
// ----------------------------------------------------------------------------------------------------------