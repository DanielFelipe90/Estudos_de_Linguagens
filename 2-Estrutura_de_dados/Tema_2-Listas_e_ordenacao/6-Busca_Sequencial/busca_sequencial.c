/* Busca sequencial

Percorre os elementos de uma lista um a um, do início ao fim, até encontrar o valor desejado ou 
atingir o final da estrutura.

Exemplo prático em C

A seguir, temos a implementação da busca sequencial em linguagem C. 
Note que se o valor não for encontrado, o resultado retornado será −1, indicando ausência no vetor. 
Veja como isso é feito na prática: */

int buscaSequencial(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
} 