#include <stdio.h>

int main(){

    //Primeiro exemplo
    int i = 0;

    while (i <= 10)
    {
        if (i % 2 == 0)
        {
            printf("O número %d é par!\n", i);
        } else if (i % 2 !=0){
            printf("O número %d é impar!\n", i);
        }
        i++;
    }

    printf("\n");

    //Segundo exemplo
    int numero;

    do
    {
        printf("Digite um número par para sair do programa...\n");
        scanf("%d", &numero);

        if (numero % 2 == 0)
        {
            printf("%d é par!\n", numero);
        } else {
            printf("%d é impar!\n", numero);
        }
        
    } while (numero % 2 != 0);
    
    printf("Você digitou um numero par, saindo do programa...\n");

    printf("\n");

    //Terceiro exemplo, Programa usando for para tabuada.
    int number, a;

    printf("Digite um numero para calcularmos a tabuada:\n");
    scanf("%d", &number);

    for (a = 0; a <= 10; a++)
    {
        printf("%d x %d = %d\n", a, number, a * number);
    }
    

    return 0;
}