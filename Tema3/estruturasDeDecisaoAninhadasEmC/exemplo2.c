#include <stdio.h>

int main()
{
    int idade, dependentes;
    float renda, patrimonio;

    // A primeira condição verifica se a idade do usuário esá entre 18 e 65 anos.
    // A segunda condição verifica se a renda mensal é menor que R$ 3.000,00.
    // A terceira condição verifica se o número de dependentes é maior que 2.

    printf("Digite a  sua idade: \n");
    scanf("%d", &idade);
    printf("Digite a sua renda mensal: \n");
    scanf("%f", &renda);
    printf("Digite o número de dependentes: \n");
    scanf("%d", &dependentes);
    printf("Digite o seu patrimônio: \n");
    scanf("%f", &patrimonio);

    if (idade >= 18 && idade <= 65)
    {
        if (renda < 3000)
        {
            if (dependentes > 2)
            {
                if (patrimonio < 50000)
                    printf("Você atende todos os critérios\n");
                else
                    printf("Você não atende ao critério de patrimônio.\n");
            }
            else
            {
                printf("Você não atende ao critério de dependentes.\n");
            }
        }
        else
        {
            printf("Você não atende ao critério renda.\n");
        }
    }
    else
    {
        printf("Você não atende ao critério de idade.\n");
    }

    return 0;
}