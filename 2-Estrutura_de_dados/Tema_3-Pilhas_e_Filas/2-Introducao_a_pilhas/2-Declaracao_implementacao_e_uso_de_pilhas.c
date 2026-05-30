#include <stdio.h>
#include <stdlib.h>

/* Declaração da estrutura
A pilha será implementada com uso de vetor fixo e uma variável que representa o índice do topo. Além disso, 
definimos um tipo Pessoa para armazenar elementos mais realistas, como podemos ver a seguir. */

// MAX: define a capacidade máxima da pilha.
#define MAX 5
 
// struct Pessoa: é um tipo personalizado contendo nome e idade.
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
/* struct Pilha: contém um vetor de Pessoa e um inteiro topo, que representa o índice do último elemento 
inserido. Quando a pilha está vazia, o topo é -1. */
typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

/* Inicialização e verificação
A pilha deve ser inicializada com o valor de topo = -1, indicando que está vazia. Veja! */
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}
/* Explicação:
Tal procedimento prepara a pilha para uso.
A atribuição de -1 ao topo é uma convenção que facilita a verificação de vazios e inserções futuras.
A seguir, verificamos se a pilha está vazia, ou seja, se não há elementos inseridos. Vamos lá! */
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}
/* Explicação:
O valor retorna verdadeiro (1) se o topo for igual a -1.
A verificação evitar remoções em uma pilha já vazia, o que causaria erro.
A seguir, buscamos se o número máximo de elementos já foi atingido. */
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}
/* Explicação:
O valor retorna verdadeiro (1) se o topo estiver no último índice possível do vetor.
A verificação evita inserções que ultrapassariam o tamanho permitido da pilha. */


/* Inserir (push)
Adiciona um novo elemento no topo da pilha. Confira! */
void push(Pilha *p, Pessoa nova) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;
    p->itens[p->topo] = nova;
    printf("\nInserido: %s, %d\n", nova.nome, nova.idade);
}
/* Explicação:
O método verifica se a pilha está cheia.
Em caso negativo, o método incrementa o topo e insere o novo elemento naquela posição.
Push é uma operação rápida e eficiente, com complexidade constante (O(1)). */


/* Remover (pop)
Retira o elemento do topo da pilha, como podemos ver adiante: */
void pop(Pilha *p, Pessoa *removida) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Não é possível remover.\n");
        return;
    }

    *removida = p->itens[p->topo];
    p->topo--;
    printf("\nRemovida: %s, %d\n", removida->nome, removida->idade);
}
/* Explicação:
O método verifica se a pilha está vazia antes de tentar remover.
A função copia o conteúdo do topo para o ponteiro removido, e então reduz o topo.
Isso simula bem o comportamento LIFO (Last In, First Out). */


/* Consulta (peek)
Veja, a seguir, como o método peek consulta o elemento no topo sem removê-lo. */
void peek(Pilha *p, Pessoa *visualizada) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }
    *visualizada = p->itens[p->topo];
    printf("\nTopo atual: %s, %d\n", visualizada->nome, visualizada->idade);
}
/* Explicação:
A função é muito útil quando queremos saber quem é o último elemento inserido, mas sem o alterar. 
O método evita mudanças na estrutura da pilha, mantendo o topo inalterado. */


/* Mostar pilha
Possibilita visualizar todos os elementos da pilha, do topo até a base. Acompanhe! */
void mostrarPilha(Pilha *p) {
    printf("\nPilha (topo até a base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}
/* Explicação:
A visualização começa do topo e vai até o primeiro elemento inserido. 
A função é útil para depuração ou apresentação dos dados empilhados. */


/* Função main e utilização
Neste exemplo, temos a utilização da função main() para executar toda a estrutura criada e apresentada 
nos tópicos anteriores. Caso queira, faça modificações para experimentar e trabalhar o entendimento 
sobre a estrutura. */
int main() {
    // Cria a instância da pilha, ou seja, a variável do tipo Pilha, que é o ponteiro 'p' para a estrutura da pilha.
    Pilha p;

    // Inicializa a pilha
    inicializarPilha(&p);
 
    // Cria variaveis do tipo Pessoa para inserir na pilha
    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};
    
    // Recebe o endereço (&) do ponteiro 'p' da pilha e o elemento a ser inserido
    push(&p, a);
    push(&p, b);
    push(&p, c);
 
    // Mostra a pilha após as inserções passando o endereço (&) do ponteiro 'p' da pilha
    mostrarPilha(&p);
 
    // Cria uma variável para armazenar o elemento removido do tipo Pessoa
    Pessoa removida;
    // Recebe o endereço do ponteiro da pilha e o endereço do elemento a ser removido
    pop(&p, &removida);
 
    mostrarPilha(&p);
    
    // Cria uma variável para armazenar o elemento do topo do tipo Pessoa
    Pessoa topo;
    // Recebe o endereço do ponteiro da pilha e o endereço do elemento a ser espiado
    peek(&p, &topo);
 
    return 0;
}
/* Explicação:
A função inicializa a pilha e empilha três pessoas. 
O método remove o elemento do topo e mostra novamente a pilha.
A função usa peek para inspecionar o novo topo sem o alterar.
Compreender e saber implementar pilhas é essencial para quem estuda estruturas de dados. 
Elas são utilizadas em problemas como:
Controle de chamadas de função (pilha de execução).
Navegação com desfazer/refazer. 
Conversão de expressões matemáticas (notação pós-fixada). 
Avaliação de expressões aritméticas. 
Backtracking (busca de soluções). 
Cada função (a saber: push, pop e peek) representa um passo importante na manipulação da pilha. 
Juntas, elas garantem o funcionamento correto da estrutura LIFO.
Manter a verificação de limites (cheia ou vazia) é indispensável para que o programa esteja muito 
bem estruturado e livre de erros de acesso inválido. */