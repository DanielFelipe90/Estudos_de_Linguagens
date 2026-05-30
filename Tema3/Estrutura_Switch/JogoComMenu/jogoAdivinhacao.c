#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int opcao, regras;
    ;
    int numeroSecreto, palpite;

    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2.Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        srand(time(0)); /* a função srand(time(0)) é chamada para inicializar o gerador de números aleatórios com base no tempo atual. Isso garante que o gerador de números aleatórios produza sequências diferentes cada vez que o programa for executado. */
        numeroSecreto = rand() % 10; /* A função rand() gera um número aleatório inteiro, e o operador % 10 limita esse número ao intervalo de 0 a 9. */
        printf("Digite um número de 0 a 9: ");
        scanf("%d", &palpite);
        if (numeroSecreto == palpite)
        {
            printf("Você acertou!\n", numeroSecreto);
            printf("O número secreto: %d\n", numeroSecreto);
        }
        else
        {
            printf("Você errou!\n");
            printf("O número secreto era: %d\n", numeroSecreto);
        }
        break;

    case 2:
        printf("Explicação das Regras do Jogo:\n");
        printf("Digite a opção relacionada as regras do jogo!\n");
        printf("1. Regra 1\n");
        printf("2. Regra 2\n");
        scanf("%d", &regras);

        switch (regras)
        {
        case 1:
            printf("Regra 1.\n");
            break;

        case 2:
            printf("Regra 2.\n");
            break;
        }

    case 3:
        printf("Saindo do jogo...!\n");
        break;

    default:
        printf("Opcao invalida!\n");
        break;
    }

    return 0;
}