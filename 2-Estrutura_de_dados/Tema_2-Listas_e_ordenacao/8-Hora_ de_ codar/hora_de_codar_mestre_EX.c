#include <stdio.h>
#include <stdlib.h> // Para funções rand(), srand().
#include <time.h>   // Para a função time(), usada para semear o gerador de números aleatórios.
#include <windows.h> // Necessário para medir tempo real no Windows

// Define o tamanho da lista que serão ordenadas.
// Facilita a alteração apra testes com mais ou menos elementos.
#define TAMANHO 10

// --- Declaração da Funções (PROTÓTIPOS) ---
/* Informa ao compilador sobre a existência e a 'assinatura' da funções
que serão implementadas após o main(). */

// --- Funções para gerar os diferentes tipos de listas. ---
void gerarListaOrdenada(int lista[], int tamanho);
void gerarListaInversa(int lista[], int tamanho);
void gerarListaAleatoria(int lista[], int tamanho);

// --- Funções de ordenação. ---
void bubbleSort(int lista[], int tamanho);
void insertionSort(int lista[], int tamanho);
void selectionSort(int lista[], int tamanho);

// --- Funções auxiliares. ---
void imprimirLista(const char *titulo, int lista[], int tamanho);
void copiarLista(int destino[], const int origem[], int tamanho);

// --- Função Principal (main) ---
int main()
{
    LARGE_INTEGER frequencia, inicio, fim;
    double tempo;

    // Semeia o gerador de números aleatórios com a hora atual.
    // Isso garante que alista aleatória seja diferente a cada execução do programa.
    // Deve ser chamado apenas UMA VEZ.
    srand(time(NULL));

    // Declara os três tipos de listas que servirão como nossos casos de teste.
    int listaOrdenada[TAMANHO];
    int listaInversa[TAMANHO];
    int listaAleatoria[TAMANHO];
    

    // Preenche as listas com os padrões desejados.
    printf("--- GERANDO LISTAS DE ENTRADA ---\n");
    gerarListaOrdenada(listaOrdenada, TAMANHO);
    gerarListaInversa(listaInversa, TAMANHO);
    gerarListaAleatoria(listaAleatoria, TAMANHO);
    printf("-----------------------------------------------\n\n");

    /* Declara uma lista temporária que será usada para receber um CÓPIA
    dos dados antes de cada ordenação. Isso é crucial para garantir que
    cada algoritmo receba a mesma lista de entrada original. */
    int listaTemp[TAMANHO];

    // 1. --- TESTANDO O BUBBLE SORT ---
    printf("--- BUBBLE SORT ---\n");

    // a. Melhor Caso: Lista á ordenada
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort | Melhor Caso (lista ordenada): ", listaTemp, TAMANHO);

    // b. Pior Caso: Lista em ordem inversa
    copiarLista(listaTemp, listaInversa, TAMANHO);

    QueryPerformanceFrequency(&frequencia); // Pega a velocidade do contador
    QueryPerformanceCounter(&inicio);       // Pega tempo inicial

    bubbleSort(listaTemp, TAMANHO);
    
    QueryPerformanceCounter(&fim);          // Pega tempo final
    tempo = (double)(fim.QuadPart - inicio.QuadPart) / frequencia.QuadPart;
    printf("Tempo de execucao: %.8f segundos\n", tempo);

    imprimirLista("Bubble Sort | Pior Caso (lista inversa): ", listaTemp, TAMANHO);

    // c. Caso Médio: Lista aleatóra
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    bubbleSort(listaTemp, TAMANHO);
    imprimirLista("Bubble Sort | Caso Médio (lista aleatória):", listaTemp, TAMANHO);

    // 2. --- TESTANDO O INSERTION SORT ---
    printf("\n--- INSERTION SORT ---\n");

    // a. Melhor Caso: Lista á ordenada
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Melhor Caso (lista ordenada): ", listaTemp, TAMANHO);

    // b. Pior Caso: Lista em ordem inversa
    copiarLista(listaTemp, listaInversa, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Pior Caso (lista inversa): ", listaTemp, TAMANHO);

    // c. Caso Médio: Lista aleatóra
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    insertionSort(listaTemp, TAMANHO);
    imprimirLista("Insertion Sort | Caso Médio (lista aleatória):", listaTemp, TAMANHO);

    // 3. --- TESTANDO O SELECTION SORT ---
    printf("\n--- SELECTION SORT ---\n");

    // a. Melhor Caso: Lista á ordenada
    copiarLista(listaTemp, listaOrdenada, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort | Melhor Caso (lista ordenada): ", listaTemp, TAMANHO);

    // b. Pior Caso: Lista em ordem inversa
    copiarLista(listaTemp, listaInversa, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("Selection Sort | Pior Caso (lista inversa): ", listaTemp, TAMANHO);

    // c. Caso Médio: Lista aleatóra
    copiarLista(listaTemp, listaAleatoria, TAMANHO);
    selectionSort(listaTemp, TAMANHO);
    imprimirLista("selection Sort | Caso Médio (lista aleatória):", listaTemp, TAMANHO);

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// --- FUNÇÃO BUBBLE SORT ---
/**
 * @brief Ordena uma lista usando o algoritmo Bubble Sort.
 * @details Lógica: Compara pares de lementos adjacentes e os troca se estiverem
 *          na ordem errada. Repete esse processo até que a lista esteja ordenada.
 *          Elementos maiores "borbulham"  para o final da lista.
 *          - Melhor Caso: Com otimização, faz apenas uma passagem.
 *          - Pior Caso: Lista em ordem inversa.
 */

void bubbleSort(int lista[], int tamanho)
{
    int i, j, temp;
    int trocou; //
    // Laço externo: controla o número de passadas pelo vetor.
    // A cada passada "i", o i-ésimo maior elemento "borbulha" para o lugar certo.
    for (i = 0; i < tamanho - 1; i++)
    {
        trocou = 0; // No ínicio de cada passagem, assumimos que não haverá trocas

        // Laço interno: percorre o vetor comparando pares de vizinhos.
        /* O limite (tamanho -1 - i) é uma otimização: ele diminui a cada
        passada, pois os maiores elementos já estão fixos no final. */
        for (j = 0; j < tamanho - i - 1; j++)
        {
            // A condição de comparação: se o elemento da esquerda for maior que o da direita ...
            if (lista[j] > lista[j + 1])
            {
                // Caso queira ir vendo a ordenação passo a passo Adicione esse printf abaixo
                // printf("Trocando %d com %d\n", lista[j], lista[j+1]);
                // ...troca eles de lugar!
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                trocou = 1; // Marca que uma troca ocorre.
            }
        }

        /* OTIMIZAÇÃO: Se após uma passagem completa nehuma troca foi aberta,
        a lista já está ordenada e podemos parar o algoritmo. */
        if (trocou == 0)
        {
            break;
        }
    }
}

// --- FUNÇÃO INSERTION SORT ---

/**
 * @brief Ordena uma lista usando o algoritmo Insertion Sort.
 * @details Lógica: Percorre a lista, continua, construindo uma sub-lista ordenada à esquerda
 *          A cada passo, pega o próximo elemento e o insere na posição correta
 *          dentro da sub-lista já ordenada, "empurrando" os elementos maiores para a direita.
 *          - Melhor Caso: Lista á ordenada, só percorre a lista uma vezcom o laço externo.
 *          - Pior Caso: Lista em ordem inversa.
 */

void insertionSort(int lista[], int tamanho)
{
    int i, j, chave;
    // Começamos do segundo elemento (indice 1), pois o primeiro(indice 0) já está ordenado.
    for (i = 1; i < tamanho; i++)
    {
        // "chave" é elemento que queremos inserir na parte ordenada
        chave = lista[i];

        // "j" aponta para o ultimo elemento da parte ordenada.
        j = i - 1;

        /* Move os elementos da parte ordenada que são maiores que a "chave"
        uma posição para a direita, para abrir espaço para a inserção. */
        while (j >= 0 && lista[j] > chave)
        {
            lista[j + 1] = lista[j];
            j = j - 1;
        }

        // Insere a "chave" na posição correta (o "buraco" aberto na lista).
        lista[j + 1] = chave;
        // Caso queira ir vendo a ordenação passo a passo Adicione esse printf abaixo
        // printf("Trocando %d com %d\n", lista[j], lista[j+1]);
    }
}

// --- FUNÇÃO SELECTION SORT ---
/**
 * @brief Ordena uma lista usando o algoritmo Selection Sort.
 * @details Lógica: Divide a lista em duas partes: ordenada (à esquerda)
 *          e não ordenada (à direita). A cada passo, encontra o menor elemento
 *          na parte não ordenada e o troca com o primeiro elemento da parte não ordenada.
 *
 *          O número de comparações é o mesmo independentemente da ordem inicial da lista.
 */
void selectionSort(int lista[], int tamanho)
{
    int i, j, indiceMenor, temp;
    /* Laço externo percorre a lista para definir a fronteira entre
    a parte ordenada e a não ordenada. */
    for (i = 0; i < tamanho - 1; i++)
    {
        // Assume que o primeiro elemento da parte não ordenada é o menor.
        indiceMenor = i;
        // Laço interno: busca pelo menor elemento na parte não ordenada.
        for (j = i + 1; j < tamanho; j++)
        {
            // Se encontrar um elemento menor que o minimo atual..
            if (lista[j] < lista[indiceMenor])
            {
                // Atualiza o indice do menor.
                indiceMenor = j;
            }
        }

        // Se o menor elemento não for o priemiro da parte não ordenada.
        if (indiceMenor != i)
        {
            // Guarda o valor que está na posição i para a troca
            int valorAntigo = lista[i];
            // Troca eles de lugar
            temp = lista[i];
            lista[i] = lista[indiceMenor];
            lista[indiceMenor] = temp;
            // Exibe apenas o que foi trocado
            // Caso queira ir vendo a ordenação passo a passo Adicione esse printf abaixo
            // printf("Troca realizada: o Valor %d que está no índice %d vai para o índice %d de valor %d.\n", valorAntigo, i, indiceMenor, lista[i]);
        }
    }
}

// --- FUNÇÃO PARA gerarListaOrdenada() ---
/**
 * @brief Gera uma lista de "quantidade" elementos em ordem crescente
 */
void gerarListaOrdenada(int lista[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        lista[i] = i + 1;
    }
    imprimirLista("Original - Ordenada: ", lista, tamanho);
}

// --- FUNÇÃO PARA gerarListaInversa() ---
/**
 * @brief Gera uma lista de "quantidade" elementos em ordem decrescente
 */
void gerarListaInversa(int lista[], int tamanho)
{
    // Pega o valor da variavel listaTempe e inverte do maior para o menor
    for (int i = 0; i < tamanho; i++)
    {
        lista[i] = tamanho - i;
    }
    imprimirLista("Original - Inversa: ", lista, tamanho);
}

// --- FUNÇÃO PARA gerarListaAleatoria() ---
/**
 * @brief Gera uma lista de "quantidade" elementos com valore aleatórios entre 1 e 100
 * sendo todos diferentes uns dos outros
 */

void gerarListaAleatoria(int lista[], int tamanho) {
    int i, j, novoNumero, repetido;

    for (i = 0; i < tamanho; i++) {
        do {
            repetido = 0;
            novoNumero = rand() % 100 + 1; // Gera número entre 1 e 100

            // Verifica se o novoNumero já existe nos elementos anteriores
            for (j = 0; j < i; j++) {
                if (lista[j] == novoNumero) {
                    repetido = 1; // Marca como repetido
                    break;
                }
            }
        } while (repetido); // Repete o 'do' se for repetido

        lista[i] = novoNumero;
    }
    imprimirLista("Original - Aleatória (sem repetição): ", lista, tamanho);
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES AUXILIARES ---
void imprimirLista(const char *titulo, int lista[], int tamanho)
{
    printf("%s [ ", titulo);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", lista[i]);
    }
    printf("]\n");
}

//
void copiarLista(int destino[], const int origem[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        destino[i] = origem[i];
    }
}