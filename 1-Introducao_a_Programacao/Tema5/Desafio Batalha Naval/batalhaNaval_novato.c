#include <stdio.h>

int main()
{
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[10][10]; // Matriz do tabuleiro 10x10
    int i, j;              /* i = Linha de cima para baixo e j = Coluna da esquerda para direita, no tabuleiro */

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas de posição Navio 1 na horizontal (tamanho 3)
    int navio1[3] = {3, 3, 3};
    int navio1_i = 1; // Posição da Linha = i
    int navio1_j = 3; // Posição  da Coluna = j

    // Coordenadas de posição Navio 2 na vertical (tamanho 3)
    int navio2[3] = {3, 3, 3};
    int navio2_i = 7; // Posição da Linha = i
    int navio2_j = 7; // Posição  da Coluna = j

    // Verificar/validar se os navios estão dentro do tabuleiro
    if (navio1_j + 3 > 10 || navio2_i + 3 > 10)
    {
        printf("Erro: Navios fora dos limites do tabuleiro.\n");
        return 1; // Encerra o programa com código de erro
    }

    // Posiciona o navio 1 na horizontal
    for (i = 0; i < 3; i++)
    {
        tabuleiro[navio1_i][navio1_j + i] = navio1[i];
        /* { tabuleiro[1][3];
             tabuleiro[1][4];
             tabuleiro[1][5] } = navio1[i];
        */
    }

    // Verifica se a posição do navio 2 está livre antes de posicioná-lo
    for (i = 0; i < 3; i++)
    {
        // Se a célula não for 0 (água), significa que já está ocupada
        if (tabuleiro[navio2_i + i][navio2_j] != 0)
        {
            printf("Erro: sobreposição de navios.\n");
            return 1; // Encerra o programa com código de erro
        }
    }

    // Se não houve erro  de sobreposição, posiciona navio 2 na vertical
    for (i = 0; i < 3; i++)
    {
        tabuleiro[navio2_i + i][navio2_j] = navio2[i];
        /*{ tabuleiro[7][7];
            tabuleiro[8][7];
            tabuleiro[9][7] } = navio2[i];
        */
    }

    // Exibe o cabeçalho
    printf("\n\n*** Batalha Naval - Desafio Novato ***\n");

    // Exibe o tabuleiro
    printf("\nTabuleiro:\n");
    printf("0 = agua/espaço vazio\n");
    printf("3 = espaço ocupado pelos navios\n\n");

    // Imprime letras das colunas 
    printf("   "); // Espaço para alinhar com os números da linha
    for (j = 0; j < 10; j++)
    {
        printf(" %c", linha[j]);
    }
    printf("\n");

    // Exibe o tabuleiro
    for (i = 0; i < 10; i++)
    {
        printf("%2d ", coluna[i]); 
        for (j = 0; j < 10; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}
