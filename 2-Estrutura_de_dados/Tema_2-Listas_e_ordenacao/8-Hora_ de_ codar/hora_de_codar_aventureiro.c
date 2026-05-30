#include <stdio.h>
#include <stdlib.h> // Para a função exit(), caso a lista não esteja ordenada para a busca binária
#include <string.h> // Biblioteca necessária para funções de string (strcpy, strcmp)

// --- Declarações de funcões (PROTÓTIPOS)
/* Isso informa ao compilador que essas funções existem e como elas são,
mesmo que suas implementações estejam mais abaixo do código */

// 1. Busca sequencial
int buscaSequencialIterativa(const char *lista[], int tamanho, const char *item);
int buscaSequencialRecursiva(const char *lista[], int tamanho, const char *item);
int buscaSequencialRecursiva_aux(const char *lista[], int tamanho, const char *item, int indice);

// 2. Busca binária
int buscaBinariaIterativa(const char *lista[], int tamanho, const char *item);
int buscaBinariaRecursiva(const char *lista[], int tamanho, const char *item);
int buscaBinariaRecursiva_aux(const char *lista[], const char *item, int inicio, int fim);

// Função auxiliar para imprimir os resultados de forma organizada
void imprimirResultado(const char *nomeBusca, const char *item, int resultado);

// --- Função Principal (main)
int main()
{
    // IMPORTANTE: Para a busca binária funcionar, a lista DEVE estar ordenada alfabeticamente.
    // Nossa lista de compras já está ordenada para o exemplo.
    const char *listaDeCompras[] = {
        "arroz",
        "batata",
        "cebola",
        "detergente",
        "feijão",
        "leite",
        "macarrão",
        "oleo",
        "sal",
        "tomate"};

    // Calcula a númerode itens n a lista.
    // sizeof(listaDeCompras) -> tamanho total do array em bytes.
    // sizeof(listaDeCompras[0]) -> tamanho de elemento (um ponteiro char*) em bytes.
    // A divisão nos dá o número de elementos.
    int tamanhoLista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);

    // Itens que vamos procurar para demosntrar os algoritmos.
    const char *itemExistente = "leite";
    const char *itemInexistente = "queijo";

    printf("\n                  --- DEMOSTRAÇÃO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTO ---                 \n");
    printf("Lista utilizada: [%s, %s, %s, %s, %s, %s, %s, %s, %s, %s]\n", 
       listaDeCompras[0], 
       listaDeCompras[1], 
       listaDeCompras[2], 
       listaDeCompras[3], 
       listaDeCompras[4], 
       listaDeCompras[5], 
       listaDeCompras[6], 
       listaDeCompras[7], 
       listaDeCompras[8],
       listaDeCompras[9]);

    printf("-------------------------------------------------------------------------------------------------\n\n");

    // --- Testando a busca sequencial ---
    printf("--- 1. BUSCA SEQUENCIAL ---\n");
    // a. Versão Iterativa
    int resultado1 = buscaSequencialIterativa(listaDeCompras, tamanhoLista, itemExistente);
    imprimirResultado("Sequencial Iterativa", itemExistente, resultado1);

    int resultado2 = buscaSequencialIterativa(listaDeCompras, tamanhoLista, itemInexistente);
    imprimirResultado("Sequencial Iterativa", itemInexistente, resultado2);

    // b. Versão Recursiva
    int resultado3 = buscaSequencialRecursiva(listaDeCompras, tamanhoLista, itemExistente);
    imprimirResultado("Sequencial Recursiva", itemExistente, resultado3);

    int resultado4 = buscaSequencialRecursiva(listaDeCompras, tamanhoLista, itemInexistente);
    imprimirResultado("Sequencial Recursiva", itemInexistente, resultado4);

    // --- TESTANDO A BUSCA BINÁRIA ---
    printf("\n--- 2. BUSCA BINÁRIA (requer lista ordenada)---\n");
    // a. Versão Iterativa
    int resultado5 = buscaBinariaIterativa(listaDeCompras, tamanhoLista, itemExistente);
    imprimirResultado("Busca Binária Iterativa", itemExistente, resultado5);

    int resultado6 = buscaBinariaIterativa(listaDeCompras, tamanhoLista, itemInexistente);
    imprimirResultado("Binária Iterativa", itemInexistente, resultado6);

    // b. Versão Recursiva
    int resultado7 = buscaBinariaRecursiva(listaDeCompras, tamanhoLista, itemExistente);
    imprimirResultado("Binária Recursiva", itemExistente, resultado7);

    int resultado8 = buscaBinariaRecursiva(listaDeCompras, tamanhoLista, itemInexistente);
    imprimirResultado("Binária Recursiva", itemInexistente, resultado8);

    printf("\n");
    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// --- 1. BUSCA SEQUENCIAL ---
/*  Percorre a lista elemento por elemento, do inicio ao fim,
 até encontrar o item ou chegar ao final da lista. */
// Não requer que a lista esteja ordenada.

/**
 * @brief Busca sequencial usando um laço (iteração/repetição).
 * @param lista O array de strings onde a busca será feita.
 * @param tamanho O número de lementos na lista.
 * @param item A string que está sendo procurada.
 * @return O índice do item se encontrado, ou -1 caso não seja encontrado.
 */
int buscaSequencialIterativa(const char *lista[], int tamanho, const char *item)
{
    // Um laço 'for' percorre cada índice da lista, de 0 até 'tamanho -1'.
    for (int i = 0; i < tamanho; i++)
    {
        // strcmp (string1, string2) compara dus strings.
        // Retorna zero se leas forem idênticas.
        if (strcmp(lista[i], item) == 0)
        {
            // Se as strings forem iguais, encontramos o item!
            return i; // Retornamos o índice atual.
        }
    }
    /* Se o laço terminar e não tivermos retornado nada,
       significa que o item não foi encontrado. */
    return -1;
}

/**
 * @brief Função "invólucro" (wrapper) para a busca sequencial recursiva.
 *        Ela esconde a complexidade do parâmetro 'índice' do usuário.
 */
int buscaSequencialRecursiva(const char *lista[], int tamanho, const char *item)
{
    return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
}

/**
 * @brief Função auxiliar que implementa a lógica recursiva da busca sequencial.
 * @param indice O índice do elemento atual a ser verificado.
 * @return O índice do item se encontrado, ou -1 caso não seja encontrado.
 */
int buscaSequencialRecursiva_aux(const char *lista[], int tamanho, const char *item, int indice)
{
    /* CASO BASE 1: FALHA (Fim da lista)
    Se o índice atual for igual ou maior que o tamnho da lista,
    significa que já percorremos todos os elementos sem sucesso. */
    if (indice >= tamanho)
    {
        return -1; // Item não encontrado.
    }

    // CASO BASE 2: SUCESSO
    // Compara o item na posição 'indice' atual com o item procurado.
    if (strcmp(lista[indice], item) == 0)
    {
        return indice; // Item encontrado! Retorna o índice.
    }

    // PASSO RECURSIVO
    // Se não for nenhum dos casos base, o item ainda pode estar no resto da lista
    // Chamamos a função novamente, mas agora para o próximo indice (indice + 1).
    // O retorno desta chamada será propagado para a chamada anterior.
    return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
}

// 2. BUSCA BINÁRIA
// Algoritmo de "dividir para conquistar".
// A cada passo, ele olha para o elemento do meio da lista (ou sub-lista).
// Se o item do meio for o procurado, a busca termina.
// Se o item procurado for menor, ele descarta a metade da direita e busca na esquerda.
// Se o item procurado for maior, ele descarta a metade da esquerda e busca na direita.
// Requer que a lista esteja ORDENADA.

/**
 * @brief Busca binária usando um laço (iteração/repetição)
 * @return O indice do item se encontrado, ou -1 caso contrário.
 */
int buscaBinariaIterativa(const char *lista[], int tamanho, const char *item)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    // O laço continua enquanto a sub-lista for válida (inicio não ultrapassou o fim).
    while (inicio <= fim)
    {
        // Calcula o índice do meio.
        // Usar inicio + (fim - inicio) / 2 evita overflow para lista muito grandes
        int meio = inicio + (fim - inicio) / 2;

        // Compara a string do meio com o item procurado.
        int comparacao = strcmp(lista[meio], item);

        // CASO BASE 1: SUCESSO
        if (comparacao == 0)
        {
            return meio; // Item encontrado! Retorna o índice.
        }
        else if (comparacao > 0)
        {
            // O item do meio vem DEPOIS do item procurado (ex: "leite" > "feijao").
            // Portanto, o item só pode estar na metade esquerda.
            // Descartamos a metade direita, ajustando o "fim".
            fim = meio - 1;
        }
        else // (comparacao < 0)
        {
            // O item do meio vem ANTES do item procurado (ex: "leite" < "sal").
            // Portanto, o item só pode estar na ametade da direita.
            // Descartamos a metade esquerda, ajustando o "inicio".
            inicio = meio + 1;
        }
    }

    /* Se o laço "while" terminar, significa que "inicio" ultrapassou "fim",
    o espaço de busca se esgotou e o itme não foi encontrado */
    return -1;
}

/**
 * @brief Função "invólucro" (wrapper) para a busca binária recursiva.
 */
int buscaBinariaRecursiva(const char *lista[], int tamanho, const char *item)
{
    return buscaBinariaRecursiva_aux(lista, item, 0, tamanho - 1);
}

/**
 * @brief Função auxiliar qie implementa a lógica recursiva da busca binária.
 * @param inicio O indice inicial da sub-lista atual.
 * @param fim O indice final da sub-lista atual.
 * @return O indice do item se encontrado, ou -1 caso não encontrado.
 */
int buscaBinariaRecursiva_aux(const char *lista[], const char *item, int inicio, int fim)
{
    // CASO BASE 1: FALHA (Espaço de busca inválida)
    // Se o "inicio" ultrapassar a fim "fim", a sub-lista é vazia, o item não está aqui.
    if (inicio > fim)
    {
        return -1; // Item não encontrado.
    }

    // PASSO RECURSIVO E CASO BASE DE SUCESSO
    // Calcula o índice do meio.
    int meio = inicio + (fim - inicio) / 2;

    // Compara a string do meio com o item procurado.
    int comparacao = strcmp(lista[meio], item);

    if (comparacao == 0)
    {
        // CASO BASE 2: SUCESSO
        return meio; // Item encontrado! Retorna o índice.
    }
    else if (comparacao > 0)
    {
        // O item está na metade esquerda.
        // Chamamos a função novamente, mas com um novo "fim"
        return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);
    }
    else // comparacao < 0
    {
        // O item está na metade direita.
        // Chamamos a função novamente, mas com um novo "inicio"
        return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
    }

}

// --- FUNÇÃO AUXILIAR PARA IMPRIMIR OS RESULTADOS ---

/**
 * @brief Formata e imprime o resultado de uma busca.
 * @param nomeBusca O nome do algoritmo utilizado
 * @param item O item que foi procurado.
 * @param resultado O resultado da busca (indice ou -1)
 */

void imprimirResultado(const char *nomeBusca, const char *item, int resultado)
{
    printf("[%s] Buscando por \"%s\"... \n", nomeBusca, item);
    if (resultado != -1)
    {
        printf("   -> Resultado: Item encontrado no índice %d.\n", resultado);
    }
    else
    {
        printf("   -> Resultado: Item não encontrado.\n");
    }
}