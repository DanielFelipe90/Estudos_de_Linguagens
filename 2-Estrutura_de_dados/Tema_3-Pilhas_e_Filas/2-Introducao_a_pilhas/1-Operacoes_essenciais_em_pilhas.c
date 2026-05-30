#include <stdio.h>
#include <stdlib.h>

// Struct de dados
typedef struct {
    int valor;
} Elemento;

// Struct da pilha vetor/array
typedef struct {
    Elemento itens[100]; // Capacidade máxima da pilha
    int topo;            // Índice do elemento no topo
} Pilha;

// Struct de pilha encadeada
// Definição do Nó (apenas o conteúdo e o link)
typedef struct No {
    Elemento dado;
    struct No *prox;
} No;

// Definição da Pilha (o "p" que você passa na função)
typedef struct {
    No *topo; // O topo aponta para o primeiro Nó da lista
} pilhaEncadeada;

// Protótipos das funções auxiliares necessárias para o funcionamento do código
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == 99;
}



/* Inserir (push)
Significa colocar novo elemento no topo. No entanto, a função de inserção precisa verificar se há 
espaço disponível antes de prosseguir. Em implementações com arrays, o topo é representado por um 
índice incrementado a cada nova inserção. Veja! */
void push(Pilha *p, Elemento e) {
    if (pilhaCheia(p)) {
        printf("Erro: pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;              // Avança o topo
    p->itens[p->topo] = e;  // Insere o novo elemento
}
/* Push adiciona um novo item no topo da pilha, respeitando o limite máximo e mantendo o controle da 
ordem inversa. Em softwares, é adicionado um novo elemento a toda ação feita, para que ela 
possa ser recuperada/desfeita. */

/* Remover (pop)
Significa retirar o que está no topo. A função a seguir recebe um ponteiro no qual o valor removido 
será armazenado, caso a pilha não esteja vazia. Acompanhe! */
void pop(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos para remover.\n");
        e->valor = -1;  // Define um valor padrão para indicar falha
        return;
    }

    *e = p->itens[p->topo];  // Copia o valor do topo
    p->topo--;               // Decrementa o topo
}
/* Pop remove o item do topo da pilha e o armazena em e, desde que a pilha não esteja vazia. Em softwares, 
toda vez que o usuário precisa desfazer uma ação, isso é conhecido como removendo o item que está no 
topo da pilha ao desfazer a última ação feita. */


/* Consulta (peek)
Possibilita consultar o elemento no topo da pilha sem o remover. Isso é útil para inspecionar o último 
valor inserido. Veja! */
void peek(Pilha *p, Elemento *e) {
    if (pilhaVazia(p)) {
        printf("Erro: pilha vazia. Não há elementos no topo.\n");
        e->valor = -1;  // Valor padrão para indicar erro
        return;
    }

    *e = p->itens[p->topo];  // Copia o elemento do topo sem alterar a pilha
}
/* Portanto, peek é uma função que permite acessar informações sem alterar a estrutura.
Resumindo
Peek copia o valor do topo da pilha sem alterar o conteúdo dela, desde que não esteja vazia. 
Em geral, essa função é utilizada quando há necessidade de exibir o topo da pilha. Na prática, 
trata-se da ação que será desfeita caso o usuário execute o comando desfazer. */


/* Liberar (free)
Possibilita que você esvazie (ou libere) os dados da pilha inteira. No caso de uma pilha de tamanho 
fixo, é importante ter em mente que os elementos não são removidos do vetor de modo físico, mas a 
pilha perde a referência de onde o topo estava. Confira o código a seguir! */
// Esvazia a pilha: reinicia o topo
// Para vetores/arrays
void liberarPilha(Pilha *p) {
    p->topo = -1;  // Define a pilha como vazia novamente
}
// Em pilhas de tamanho dinâmico, liberar significa utilizar o free para desalocar da memória. Veja!
// Libera todos os nós da pilha dinâmica
void liberarPilhaEncadeada(pilhaEncadeada *p) {
    while (p->topo != NULL) {
        No *remover = p->topo;
        p->topo = p->topo->prox;
        free(remover);  // Libera a memória alocada
    }
}
/* No exemplo, o while percorre toda a pilha e depois libera toda a pilha alocada na memória.
Resumindo
A função free() só é necessária em pilhas implementadas com alocação dinâmica, em que cada elemento 
é criado com malloc. Nessas pilhas, é preciso liberar manualmente cada nó para evitar vazamentos de 
memória. Já nas pilhas com tamanho fixo (usando arrays), não se usa free, pois a memória é gerenciada 
de maneira automática. Para "limpar" a pilha estática, basta redefinir o topo para -1. 
Isso torna os elementos antigos inacessíveis pela lógica da pilha. */

/* Atenção
O uso correto das funções inserir, remover, consultar e liberar permite que a pilha se comporte de 
forma segura e previsível. Implementar pilhas de forma correta é fundamental para sistemas que exigem 
controle de histórico, processamento recursivo, análise de expressões ou controle de navegação. */

// --- FUNÇÕES DE INICIALIZAÇÃO ---
// --- FUNÇÃO DE INICIALIZAR PILHA COM VETOR/ARRAY ---
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// --- FUNÇÃO DE INICIALIZAR PILHA ENCADEADA ---
/* void inicializarPilhaEncadeada(Pilha *p) {
    p->topo = NULL;
} */

// --- FUNÇÃO PRINCIPAL ---
int main() {
    Pilha p;
    inicializarPilha(&p);

    Elemento pagina = {1};
    push(&p, pagina);
    printf("\n\nElemento inserido: %d\n\n", pagina.valor);

    Elemento pagina2 = {2};
    push(&p, pagina2);
    printf("Elemento inserido: %d\n\n", pagina2.valor);

    Elemento pagina3 = {3};
    push(&p, pagina3);
    printf("Elemento inserido: %d\n\n", pagina3.valor);

    peek(&p, &pagina);
    printf("Topo da pilha: %d\n\n", pagina.valor);

    pop(&p, &pagina);
    printf("Elemento removido: %d\n\n", pagina.valor);

    peek(&p, &pagina);
    printf("Topo da pilha: %d\n\n", pagina.valor);

    liberarPilha(&p);

    return 0;
}