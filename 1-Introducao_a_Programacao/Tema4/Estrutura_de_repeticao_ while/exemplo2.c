#include <stdio.h>
 
    /* Importante: antes de você executar o código é necessário que sejam inseridos os valores a serem lidos no campo input, um número por linha, e o último número deve ser negativo para que o loop seja interrompido, enquanto o número for positivo vai ficar pedindo para digitar até vc digitar um número negativo. */

int main() {
    int num;
   
    printf("Digite um número (negativo para sair): \n");
    scanf("%d", &num);
   
    while (num >= 0) {
        printf("Você digitou: %d\n", num);
       
        printf("Digite um número (negativo para sair): \n");
        scanf("%d", &num);
    }
   
    printf("Número negativo detectado. Saindo...\n");
   
    return 0;
}