#include <stdio.h>

int main(){
    int idade;
    float renda;

    //if (condição) { 
    //    if (condição) {
    //      // Código a ser executado se a condição1 e condição2 forem verdadeiras
    //    } else {}
    //}

    /* Programa que verifica se uma pessoa está qualificada para um desconto especial com base na idade e ana renda mensal.A pessoa de ter mais de 60 anos ou menos de 18 anos e ter uma renda mensal abaixo de R$ 2000 */

    printf("Digite a idade da pessoa: \n");
    scanf("%d", &idade);
    printf("Digite a sua renda mensal: \n");
    scanf("%f", &renda);

    if (idade <= 18 || idade >= 60)
    {
      if (renda < 2000) 
      {
        printf("Você tem direito ao desconto!\n");
      } else {
        printf("Você não tem direito ao desconto.\n");
      }

    } else {
        printf("Você não atende aos critérios devido a idade\n");
    }
    
    return 0;
}

