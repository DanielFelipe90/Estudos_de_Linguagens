/* Armazenamento de caracteres

Arrays também podem ser usados para armazenar caracteres, como letras ou palavras. Esse exemplo demonstra como criar e acessar um array de caracteres. Confira! */

#include <stdio.h>
 
int main() {
    char letras[4] = {'A', 'B', 'C', 'D'};  // Array de caracteres
 
    printf("Primeira letra: %c\n", letras[0]);
    printf("Segunda letra: %c\n", letras[1]);
    printf("Terceira letra: %c\n", letras[2]);
    printf("Quarta letra: %c\n", letras[3]);
 
    return 0;
}

/* Aqui, um array letras armazena quatro caracteres e os imprime. */