#include <stdio.h>

#define linhas 5
#define colunas 5

int main()
{

    int matriz[linhas][colunas];
    int soma = 0;

    printf("\n");

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            soma++;
            matriz[i][j] = soma;
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}

    
