#include <stdio.h>

int main()
{

    printf("*** Desafio Aventureiro ***\n");

    // Movimento do cavalo: 2 casas para baixo e uma esquerda (Usando FOT e WHILE)
    printf("\nMovimento do Cavalo:\n");
    int cavalo = 1;
    for (cavalo = 1; cavalo <= 1; cavalo++)
    {
        int i = 1;
        while (i <= 2)
        {
            printf("Baixo.\n");
            i++;
        }
        printf("Esquerda.\n");
    }

    // Movimento da Torre: 5 casas para a direita (usando FOR)
    int torre = 5;
    printf("\nMovimento da Torre:\n");
    for (int i = 0; i < torre; i++)
    {
        printf("Direita\n");
    }

    // Movimento do Bispo: 5 casas na diagonal para cima e à direita (usando WHILE)
    int bispo = 5;
    int a = 0;
    printf("\nMovimento do Bispo:\n");
    while (a < bispo)
    {
        printf("Cima - Direita\n");
        a++;
    }

    // Movimento da Rainha: 8 casas para a esquerda (usando DO-WHILE)
    int rainha = 8;
    int b = 0;
    printf("\nMovimento da Rainha:\n");
    do
    {
        printf("Esquerda\n");
        b++;
    } while (b < rainha);

    return 0;
}
