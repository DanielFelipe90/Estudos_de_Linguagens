/* Exemplo prático em C

Veja a implementação da versão iterativa da busca binária, um algoritmo eficiente para encontrar um
elemento em um vetor já ordenado em ordem crescente.

A função recebe três parâmetros:
1. O vetor onde será feita a busca.
2. O tamanho do vetor.
3. O valor procurado.

Utilizando duas variáveis (inicio e fim) para definir os limites da busca e uma variável meio para dividir
 o vetor ao meio a cada iteração, o algoritmo compara progressivamente o valor do meio com o desejado,
 descartando metade do vetor a cada passo. Caso o valor seja encontrado, a função retorna sua posição;
 caso contrário, retorna −1, indicando que o elemento não está presente no vetor. */

int buscaBinaria(int vetor[], int tamanho, int valor)
{
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1; // não encontrado
}