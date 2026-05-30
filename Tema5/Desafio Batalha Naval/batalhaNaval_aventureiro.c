#include <stdio.h>

#define linhaTabuleiro 10
#define colunaTabuleiro 10

int main()
{
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[linhaTabuleiro][colunaTabuleiro];

    // Inicializa o tabuleiro com água = 0.
    for (int i = 0; i < linhaTabuleiro; i++)
    {
        for (int j = 0; j < colunaTabuleiro; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas de posição Navio 1.
    int navio1[3] = {3, 3, 3};
    int navio1_i = 0; // Posição da Linha = i.
    int navio1_j = 3; // Posição  da Coluna = j.

    // Coordenadas de posição Navio 2.
    int navio2[3] = {3, 3, 3};
    int navio2_i = 7; // Posição da Linha = i.
    int navio2_j = 9; // Posição  da Coluna = j.

    // Coodernadas de posição Navio 3.
    int navio3[3] = {3, 3, 3};
    int navio3_i = 5;
    int navio3_j = 1;

    // Coodernadas de posição Navio 4.
    int navio4[3] = {3, 3, 3};
    int navio4_i = 7;
    int navio4_j = 6;

    // Validação de limites.
    if (navio1_j + 3 > colunaTabuleiro || navio2_i + 3 > linhaTabuleiro ||
        navio3_i + 3 < linhaTabuleiro || navio3_j + 3 > colunaTabuleiro ||
        navio4_i + 3 > linhaTabuleiro || navio4_j + 3 > colunaTabuleiro)
    {
        printf("Erro: Um ou mais navios estão fora dos limites do tabuleiro.\n");
        return 1;
    }

    // Verificação sobreposição antes de posicionar os navios.
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[navio1_i][navio1_j + i] != 0)
        {
            printf("Erro: sobreposição do navio 1.\n");
            return 1;
        }
        if (tabuleiro[navio2_i - i][navio2_j] != 0)
        {
            printf("Erro: sobreposição do navio 2.\n");
            return 1;
        }
        if (tabuleiro[navio3_i - i][navio3_j + i] != 0)
        {
            printf("Erro: sobreposição do navio 3.\n");
            return 1;
        }
        if (tabuleiro[navio4_i - i][navio4_j - i] != 0)
        {
            printf("Erro: sobreposição do navio 4.\n");
            return 1;
        }
    }

    // Posiciona os  navios.
    for (int i = 0; i < 3; i++)
    {
        // Posiona o navio 1 na horizontal da esquerda para direita.
        tabuleiro[navio1_i][navio1_j + i] = navio1[i];
        // Posiona o navio 2 na vertical de cima para baixo.
        tabuleiro[navio2_i + i][navio2_j] = navio2[i];
        // Posiona o navio 3 na diagonal de baixo para cima para direita.
        tabuleiro[navio3_i - i][navio3_j + i] = navio3[i];
        // Posiona o navio 4 na diagonal de baixo para cima para esquerda.
        tabuleiro[navio4_i - i][navio4_j - i] = navio4[i];
    }

    // Exibe o cabeçalho.
    printf("\n\n*** Batalha Naval - Desafio Novato ***\n");

    // Exibe o tabuleiro.
    printf("\nTabuleiro:\n");
    printf("0 = agua/espaço vazio\n");
    printf("3 = espaço ocupado pelos navios\n\n");

    // Imprime letras das colunas.
    printf("   "); // Espaço para alinhar com os números da linha.
    for (int j = 0; j < colunaTabuleiro; j++)
    {
        printf(" %c", linha[j]);
    }
    printf("\n");

    // Exibe o tabuleiro.
    for (int i = 0; i < linhaTabuleiro; i++)
    {
        printf("%2d ", coluna[i]);
        for (int j = 0; j < colunaTabuleiro; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;

}
