#include <stdio.h>

// Movimento da Rainha com recursividade
void moverRainha(int casas)
{
    if (casas > 0)
    {
        printf("Esquerda.\n");
        moverRainha(casas - 1);
    }
}

// Movimento do Bispo com recursividade e loops aninhados(FOR)
void moverBispo(int casas)
{
    // Loop externo para a linha vertical
    for (int cima = 0; cima < casas; cima++)
    {
        // Loop interno para a linha horizontal
        for (int direita = 0; direita < casas; direita++)
        {
            if (cima == direita)
            {
                printf("Cima - Direita.\n");
            }
        }
    }
}

// Movimento da torre recursividade
void moverTorre(int casas)
{
    if (casas > 0)
    {
        printf("Direita.\n");
        moverTorre(casas - 1);
    }
}

int main()
{

    printf("*** Desafio Mestre ***\n");

    // Movimento do cavalo: 2 casas para cima e 1 para direita usando loops aninhados (FOR)
    printf("\nMovimento do Cavalo:\n");
    // Loop externo para 1 casa para direita
    for (int j = 0; j < 1; j++)
    {
        // Loop interno para 2 casas para cima
        for (int i = 0; i < 2; i++)
        {
            printf("Cima\n");
            continue;
        }

        printf("Direita\n");
        break;
    }

    printf("\nMovimento da Rainha:\n");
    // 8 casas para a esquerda
    moverRainha(8);
    printf("\nMovimento do Bispo:\n");
    // 5 casas na diagonal para cima e à direita
    moverBispo(5);
    printf("\nMovimento da Torre:\n");
    // 5 casas para a direita
    moverTorre(5);

    return 0;
}