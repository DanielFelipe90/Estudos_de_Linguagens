/* Busca binária

Características principais
A seguir, listamos as mais importantes; confira!
Não exige que os dados estejam ordenados.
É simples de implementar e entender.
Funciona para qualquer tipo de estrutura linear (vetores, e listas)
Mas atenção: a busca binária só pode ser utilizada em estruturas ordenadas. Ela funciona dividindo o espaço de busca ao meio a cada iteração (ou chamada recursiva), comparando o valor do meio com o procurado e descartando metade dos dados a cada passo.

Exemplo prático em C

Veja a seguir a implementação da função de busca binária em linguagem C: */

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
} 