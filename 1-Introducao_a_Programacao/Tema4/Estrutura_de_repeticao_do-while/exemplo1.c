#include <stdio.h>

int main()
{
    int i = 1;
    /* Do-While executa pelo menos uma vez o printf, após verificar a condição while se for verdadeira o loop continua, quando for falsa ele encerra. */
    do {

        printf("&d\n", i);
        i++;//Incrementa +1 a variável i até chegar a condição i <= 5.

    } while (i <= 5);

    return 0;
}