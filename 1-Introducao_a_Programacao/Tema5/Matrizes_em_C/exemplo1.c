/* Definição e inicialização de matrizes

Uma matriz bidimensional de inteiros pode ser definida da seguinte forma. Confira! */

#include <stdio.h>
 
int main() {
    int matriz[3][3];  // Declaração de uma matriz 3x3 de inteiros
 
    // Inicializando os elementos da matriz
    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[0][2] = 3;
    matriz[1][0] = 4;
    matriz[1][1] = 5;
    matriz[1][2] = 6;
    matriz[2][0] = 7;
    matriz[2][1] = 8;
    matriz[2][2] = 9;
 
    // Acessando elementos da matriz
    printf("O elemento na posição [0][0] é %d\n", matriz[0][0]);
    printf("O elemento na posição [1][1] é %d\n", matriz[1][1]);
 
    return 0;
}

/* Nesse exemplo, matriz é uma matriz 3x3. Cada elemento é acessado usando dois índices, correspondendo à linha e à coluna. */