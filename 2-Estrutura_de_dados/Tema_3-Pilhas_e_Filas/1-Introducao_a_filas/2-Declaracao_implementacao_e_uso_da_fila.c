#include <stdio.h>
#include <stdlib.h>

// Define o tamanho maximo da fila
#define MAX 5

/* Struct do elemento
O primeiro passo para utilizar uma fila com mais significado é definir o tipo de dado que será armazenado. 
No nosso exemplo, cada item da fila representa uma pessoa. */
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
/* Lembre-se: esse tipo estruturado facilita a organização dos dados e resulta no uso de informações mais 
completas nos elementos da fila. */


/* Struct da fila
A fila em si precisa de um array para armazenar os elementos e as variáveis de controle para saber onde 
inserir e remover. */
typedef struct {
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;
// A struct Fila guarda os dados e controla o estado da fila com índices e contador de elementos.


/* Inicializar fila
Antes de usar a fila, seus índices e contador precisam ser configurados, como podemos ver a seguir. */
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}
// A inicialização define o ponto de partida da fila, visando ao seu funcionamento correto desde o início.


/* Verificar fila cheia e/ou vazia
É importante para sabermos se a fila atingiu a capacidade máxima. Confira a seguir! */
int filaCheia(Fila *f) {
    return f->total == MAX;
}
//Fazer tal verificação também confirma se há elementos disponíveis para remoção. Veja!
int filaVazia(Fila *f) {
    return f->total == 0;
}
/* Fila cheia impede novas inserções. Logo, essa verificação evita sobreposição de dados. 
Fila vazia, por sua vez, impede remoções, o que é importante para evitar acesso a posições inválidas.  */


/* Inserir (enqueue) e remover (dequeue)
Enqueue e dequeue são as funções que trazem a característica FIFO para a estrutura de dados fila. 
A primeira adiciona novo item no final da fila, enquanto a outra remove o item que representa o início da fila.
Portanto, inserções e remoções não seriam possíveis sem essas duas implementações.
Enqueue adiciona um novo item ao final da fila, se houver espaço. Observe o código adiante! */
void inserir(Fila *f, Pessoa p) {
    if (f->total == MAX) {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }
 
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}
// Confira agora como dequeue remove o elemento da frente da fila:
void remover(Fila *f, Pessoa *p) {
    if (filaVazia(f)) {
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = f->itens[f->inicio];             
    f->inicio = (f->inicio + 1) % MAX;     
    f->total--;                        
}
/* Dequeue insere no final e atualiza os controles da fila, e o uso do módulo mantém a circularidade.  
A remoção retorna o primeiro elemento e ajusta a posição de início da fila. */


/* Mostrar fila
Exibe todos os elementos na ordem em que foram inseridos, como podemos ver adiante. */
void mostrarFila(Fila *f) {
    printf("\nFila: ");
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%s, %d] ", f->itens[idx].nome, f->itens[idx].idade);
    }
    printf("\n");
}
// Essa função percorre a fila desde o início até o total visto atualmente, respeitando a ordem dos dados.


// --- Função para limpar tela ---
void limparTela() {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
}


/* Declaração e exibição no main()
A fila pode ser usada no main após ser inicializada, inserindo pessoas e mostrando o conteúdo. Acompanhe! */
int main() {

    // Declaração da fila
    Fila f;

    // Inicializa a fila
    inicializarFila(&f);  
    
    // Variaveis para a inserção do tipo Pessoa/struct
    Pessoa p1 = {"João", 25};
    Pessoa p2 = {"Maria", 30};
    Pessoa p3 = {"Pedro", 28};

    // Insere algumas pessoas na fila
    inserir(&f, p1);
    inserir(&f, p2);
    inserir(&f, p3);
 
    limparTela();

    // Mostra a fila antes da remoção
    mostrarFila(&f);  
 
    // Remove uma pessoa da fila
    // Declaramos um objeto/variavel do tipo Pessoa
    Pessoa removida;

    // Aqui usamos a função de remoção
    remover(&f, &removida);  
 
    printf("\nPessoa removida: %s, %d\n", removida.nome, removida.idade);
 
    // Mostra a fila após a remoção
    mostrarFila(&f);  

    printf("\n");
 
    return 0;
}
// Por fim, a sequência que declara, inicializa, insere e exibe mostra o uso prático da fila com clareza.


/* Atenção
Compreender como declarar, inicializar e manipular filas é necessário para manter a organização dos dados 
sequencial e controlada, sendo os conceitos de fila cheia, vazia, inserção e remoção a base de seu 
funcionamento. Mostrar a fila no console facilita o entendimento visual e a depuração de erros. Utilizar estruturas bem 
definidas e funções organizadas favorece o reuso e a escalabilidade da estrutura, seja em projetos simples 
ou em complexos. */