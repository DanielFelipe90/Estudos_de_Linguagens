#include <stdio.h>

int main(){
    char banco[50];
    int opcao, agencia, conta;
    float saldo = 1000.00, saque = 100, deposito; // Exemplo de saldo inicial

    printf("Escolha uma opção: \n");
    printf("1. Verificar saldo.\n");
    printf("2. Verificar  deposito.\n");
    printf("3. Fazer Saque.\n");
    printf("4. Opção inválida.\n");
    scanf("%d", &opcao);


    switch (opcao)
    {
    case 1:
        printf("Você escolheu verificar saldo.\n");
        printf("Seu saldo atual é: R$ %.2f\n", saldo);
        break; 
    case 2:
        printf("Você escolheu verificar depósito.\n");
        printf("Digite o banco que você deseja depositar:\n");
        scanf("%s", banco);
        printf("Digite a agência:\n");
        scanf("%d", &agencia);
        printf("Digite a conta:\n");
        scanf("%d", &conta);
        printf("Digite o valor do depósito:\n");
        scanf("%f", &deposito);
        printf("Depósito realizado no Banco %s, agência %d, conta %d, valor de R$ %.2f.\n", banco, agencia, conta, deposito);
           break;
    case 3:
        printf("Você escolheu fazer saque.\n");
        printf("Digite o valor do saque:\n");
        scanf("%f", &saque);
        break;
    case 4:
        printf("Você escolheu uma opção inválida.\n");
        break;
    }

  

}