/* Arrays utilizando string

Arrays podem armazenar strings, permitindo a manipulação de conjuntos de palavras ou frases. Veja o exemplo! */

#include <stdio.h>
 
int main() {
    char *nomes[] = {"Alice", "Bob", "Carol"};
    int i;
    for(i = 0; i < 3; i++) {
        printf("%s\n", nomes[i]);
    }
    return 0;
}

/* Nesse exemplo, criamos um array de strings com três nomes e os imprimimos usando um loop for. Cada elemento do array é acessado e exibido com printf.

Dois pontos importantes a destacar nesse exemplo. Primeiro, você deve ter percebido que na declaração do array nomes não foi especificado o tamanho do array. Isso não é problema, porque como ele foi inicializado com três nomes, automaticamente ele é definido com tamanho 3.

O segundo ponto é que você deve ter percebido que aparece um asterisco (*) antes da palavra nomes. Isso é uma indicação de ponteiros e é necessário quando você quiser criar um array de strings. Ponteiros é um assunto que está fora do escopo deste conteúdo, mas foi apresentado como são criados array de strings. */