#include <stdio.h>
 
int main() {
    int num;
    
    /* Nesse caso, o loop do-while assegura que o pedido de entrada seja feito pelo menos uma vez, independentemente do valor inicial de num. Após cada entrada, a condição num >= 0 é verificada. Se for verdadeira, o loop continua; se for falsa, o loop termina. */

    do {
        printf("Digite um número (negativo para sair): ");
        scanf("%d", &num);
       
        if (num >= 0) {
            printf("Você digitou: %d\n", num);
        }
    } while (num >= 0);
   
    printf("Número negativo detectado. Saindo...\n");
   
    return 0;
}