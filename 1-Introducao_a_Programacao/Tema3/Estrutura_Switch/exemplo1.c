#include <stdio.h>

int main()
{
    int variavel;

    printf("Digite um valor: \n");
    scanf("%d", &variavel);

    switch (variavel)
    {
    case 1:
        printf("Você digitou o valor 1\n");
        break;
    case 2:
        printf("Você digitou o valor 2\n");
        break;
    case 3:
        printf("Você digitou o valor 3\n");
        break;
    default:
        printf("Você não digitou nem 1, nem 2, nem 3\n");
    }
}