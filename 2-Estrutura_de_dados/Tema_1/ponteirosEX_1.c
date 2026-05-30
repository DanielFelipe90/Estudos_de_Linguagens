#include <stdio.h>

int main()
{
    int x = 10;
    int *p = &x; // p é um ponteiro para a variável x

    printf("Ponteiros em C - Exemplo 1\n");
    printf("Valor de x: %d\n", x);                             // Imprime o valor de x
    printf("Endereço de x: %p\n", &x);                         // Imprime o endereço de x
    printf("Conteudo de p (o endereço na memoria), %p \n", p); // Imprime o valor do ponteiro (endereço de a)
    printf("Valor apontado por p: %d\n", *p);                  // Imprime o valor apontado por p (valor de x)

    printf("\nPressione Enter para continuar...\n");
    getchar(); // Aguarda o usuário pressionar Enter

    printf("\nModificando o valor de x através do ponteiro *p = 20\n");
    *p = 20;                              // Modificando o valor através do ponteiro
    printf("Novo valor de x: %d\n\n", x); // Imprime o novo valor de x, que agora é 20

    return 0;
}