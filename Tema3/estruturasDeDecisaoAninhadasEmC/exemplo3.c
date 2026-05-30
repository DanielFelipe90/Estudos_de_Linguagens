#include <stdio.h>

int main(){
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    if (numero > 0) {
        if (numero % 2 == 0) {
            printf("Número Par\n");
        } else {
            printf("Número Ímpar\n");
        }
        printf("Número Positivo\n");
    } else if (numero == 0) {
        printf("Número é zero\n");
    } else {
        printf("Número Negativo\n");
        if (numero % 2 == 0) {
            printf("Número Par\n");
        } else {
            printf("Número Ímpar\n");
        }
    }

return 0;
}