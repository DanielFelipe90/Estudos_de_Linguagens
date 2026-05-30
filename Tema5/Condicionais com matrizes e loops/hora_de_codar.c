#include <stdio.h>

#define linha 3
#define coluna 3
 
int main() {
    int matriz[linha][coluna];
    int target = 5;
    int found = 0;
    int soma = 1;
    
    // Inicialização condicional da matriz
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            matriz[i][j] = soma;
            soma++;
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
 
    // Busca condicional do elemento alvo
    for (int i = 0; i < linha; i++) {      // Loop externo para as linhas
        for (int j = 0; j < coluna; j++) {  // Loop interno para as colunas
            if (matriz[i][j] == target) {
                printf("Elemento %d encontrado na posição (%d, %d)\n", target, i, j);
                found = 1; // Condição booleana verdadeira (true = 1)
                break;
            }
        }
        if (found) break;
    }
    
    // Condição boolena falsa (false = 0)
    if (!found) {
        printf("Elemento %d não encontrado na matriz\n", target);
    }

    printf("\n\n");
    return 0;
}