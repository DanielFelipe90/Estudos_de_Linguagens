#include <stdio.h>

int main (){

    float media, nota1, nota2, nota3;

    printf("***Programa de cálculo de Média ***\n");

    printf("Digite a primeira nota: \n");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: \n");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: \n");
    scanf("%f", &nota3);

    /*media = (float)(nota1 + nota2 + nota3) / 3; (O (float) força que todos os números sejam do tipo float, caso usarmos int para as notas)*/

    // Cálculo da média
    media = (nota1 + nota2 + nota3) / 3;

    printf("\nA média de Notas é: %.1f\n", media);

    if (media >= 6){
        printf("Parabéns você foi Aprovado\n");
    }
    else{
        printf("Reprovado\n");
    }
    
    return 0;

}