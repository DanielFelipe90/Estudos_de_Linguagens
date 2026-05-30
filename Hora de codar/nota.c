#include <stdio.h>

int main(){
    int nota;

    printf("Digite uma nota de 0 a 10: ");
    scanf("%d", &nota);

    if (nota >=6)
        printf("Aprovado\n");
    else if (nota >= 0 && nota < 6)
        printf("Reprovado\n");
    else
        printf("Nota inválida\n");

    return 0;
}