/* Introdução às operações básicas


Filas são estruturas de dados que funcionam segundo o princípio FIFO, ou seja, o primeiro elemento inserido 
é o primeiro a ser retirado. Portanto, isso promove um comportamento ordenado e previsível, certo?

Para dominarmos o uso de filas, precisamos conhecer bem as operações básicas que controlam seu funcionamento: 
inserir, retirar e espiar. A seguir, detalharemos cada uma delas, abordando sua finalidade, seu comportamento 
e uso correto. Vamos lá! */

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
// Estrutura
typedef struct {
    int valor;
} Elemento;

// Vetor/array
typedef struct {
    Elemento itens[MAX];
    int inicio; // Índice do próximo elemento a ser removido
    int fim;    // Índice da próxima posição livre para inserção
    int total;  // Contador de elementos atuais na fila
} Fila;

// --- Protótipos das funções ---
void inserir(Fila *f, Elemento e);
Elemento retirar(Fila *f);
Elemento espiar(Fila *f);
void inicializarFila(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);

/* --- Função Inserir ---

Inserir (enqueue)

Significa colocar um novo elemento no final da fila. Porém, essa função precisa verificar se ainda há espaço 
disponível antes de prosseguir. Em implementações com arrays, isso é feito por meio de controle do total de 
elementos ou de um índice de fim, como podemos observar a seguir. */

void inserir(Fila *f, Elemento e) {
    if (filaCheia(f)) // Impede inserção se estiver cheia
        return;
    f->itens[f->fim] = e;            // Insere no final
    f->fim = (f->fim + 1) % MAX;     // Atualiza circularmente o índice
    f->total++;                      // Incrementa a contagem de elementos
}

/* --- Função Remover ---

Retirar (dequeue)

Significa eliminar o elemento mais antigo, localizado na frente. Mas atenção: antes de remover, é necessário 
verificar se a fila não está vazia, evitando acessar posições inválidas. Acompanhe! */

Elemento retirar(Fila *f) {
    Elemento vazio = {-1};               // Valor padrão caso a fila esteja vazia
    if (filaVazia(f)) 
        return vazio;      // Evita remoção se estiver vazia
    Elemento e = f->itens[f->inicio];    // Armazena o item a ser removido
    f->inicio = (f->inicio + 1) % MAX;   // Atualiza o índice de início
    f->total--;                          // Diminui o total
    return e;                            // Retorna o item removido
}

/* --- Função para verificar o primeiro elemento da fila ---

Verificar sem remoção (peek)

Em certas situações, é importante olhar o que está no início da fila sem removê-lo. Isso é feito pela operação 
de "espiar", também conhecida como peek. A função apenas retorna o elemento da frente sem alterar nenhum 
índice, como podemos ver no código a seguir. */

Elemento espiar(Fila *f) {
    Elemento vazio = {-1};              // Valor padrão se a fila estiver vazia
    if (filaVazia(f))
        return vazio;     // Impede acesso indevido
    return f->itens[f->inicio];         // Retorna o elemento da frente
}


// --- Função para inicializar a fila circular ---
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// --- Função para verificar se a fila está vazia ---
int filaVazia(Fila *f) {
    return f->total == 0;
}

// --- Função para verificar se a fila está cheia ---
int filaCheia(Fila *f) {
    return f->total == MAX;
}