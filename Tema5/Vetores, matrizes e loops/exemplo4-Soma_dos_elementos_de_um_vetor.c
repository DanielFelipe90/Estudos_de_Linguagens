/* Soma dos elementos de um vetor
É uma operação simples e comum, utilizada para calcular a soma total de todos os elementos presentes em um vetor.
 Primeiramente, declaramos e inicializamos um vetor chamado vetor com cinco elementos. Criamos uma variável soma para armazenar o total. Este exemplo mostra como percorrer um vetor e somar seus elementos. Veja! */

 #include <stdio.h>
 
int main() {
    int vetor[5] = {1, 2, 3, 4, 5};
    int soma = 0;
 
    // Calculando a soma dos elementos do vetor
    for (int i = 0; i < 5; i++) {
        soma += vetor[i];
    }
 
    printf("A soma dos elementos do vetor é: %d\n", soma);
    printf("\n\n");
 
    return 0;
}

/* Vamos entender o que o código faz!

1. Declaração e inicialização: O vetor chamado vetor é declarado e inicializado com cinco valores. A variável soma é inicializada com zero.
2. Soma dos elementos: Usamos um loop for para percorrer cada elemento do vetor. Em cada iteração, o valor do elemento atual é adicionado à variável soma.
3. Exibição do resultado: Por fim, usamos printf para imprimir a soma total dos elementos do vetor. */