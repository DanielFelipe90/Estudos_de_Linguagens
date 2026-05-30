#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    //Gerar código aleatório
    srand(time(0));
    numeroComputador = rand() % 100 + 1; // Número entre 1 e 100

    //Início do jogo
    printf("*** Bem-vindo ao jogo Maior, Menor ou Igual! ***\n");
    printf("Você deve escolher um número e o tipo de comparação.\n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");

    printf("Escolha a comparação: \n");
    scanf(" %c", &tipoComparacao);

    printf("Digite um número entre 1 e 100: ");
    scanf("%d", &numeroJogador);

    //Exibir o número do computador
    /* printf("O número do computador é: %d\n", numeroComputador); */

    switch (tipoComparacao)
    {
    case 'M':
    case 'm':
        printf("Voê escolheu a opção maior!\n");
        resultado = (numeroJogador > numeroComputador) ? 1 : 0;
        printf("O número do computador é: %d\n", numeroComputador);
        break;

    case 'N':
    case 'n':
        printf("Voê escolheu a opção menor!\n");
        resultado = (numeroJogador < numeroComputador) ? 1 : 0;
        
        break;

    case 'I':
    case 'i':
        printf("Voê escolheu a opção igual!\n");
        resultado = (numeroJogador == numeroComputador) ? 1 : 0;
        break;
    
    default:
        printf("Opção inválida! Por favor, escolha uma opção válida.\n");
        break;
    }

    printf("O número do computador é: %d e o do jogador é: %d\n", numeroComputador, numeroJogador);

    if (resultado == 1) {
        printf("Parabéns! Você ganhou!\n");
    } else {
        printf("Que pena! Você perdeu. Tente novamente!\n");
    }

    return 0;
}