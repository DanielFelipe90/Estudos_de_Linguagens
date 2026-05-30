#include <stdio.h>

int main(){

    /* É uma das mais utilizadas na programação devido à sua capacidade de simplificar a execução de loops com um número específico de iterações. Diferentemente dos loops while e do-while, que se baseiam exclusivamente em uma condição, o for é especialmente útil quando se sabe de antemão quantas vezes o loop deve ser executado. */

    for (int i = 1; i <=5; i++)/* A variaével int i pode ser declarada dentro da condição for,mas se ela estiver declarada somente aqui não funcionara em outras funcões. */
    {
        printf("%d\n", i);
    }

    /* Nesse caso, a variável i é inicializada com 1. A condição i <= 5 é verificada antes de cada iteração. Se a condição for verdadeira, o bloco de código que imprime i é executado. Após a execução do bloco, a variável i é incrementada em 1. O loop continua até que a condição se torne falsa. */

    return 0;
}