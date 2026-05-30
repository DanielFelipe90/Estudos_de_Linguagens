/* Exemplo prático em C

Vamos agora conferir a implementação da versão recursiva da busca binária, um algoritmo utilizado 
para localizar um valor específico em um vetor ordenado. 

A função recebe como parâmetros: 
1. O vetor.
2. Os índices que delimitam o intervalo de busca (inicio e fim).
3. O valor a ser procurado.
 
O algoritmo compara o valor do meio do intervalo com o desejado e, com base no resultado, 
faz uma chamada recursiva para continuar a busca na metade inferior ou superior do vetor. 
Esse processo se repete até que o valor seja encontrado ou que o intervalo se torne inválido 
(quando inicio ultrapassa fim), o que indica que o elemento não está presente. 
A recursão torna o código conciso e elegante, facilitando a compreensão da lógica de divisão do vetor. 
Veja! */

int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor) {
    if (inicio > fim)
        return -1;

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == valor)
        return meio;
    else if (vetor[meio] < valor)
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
    else
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
} 