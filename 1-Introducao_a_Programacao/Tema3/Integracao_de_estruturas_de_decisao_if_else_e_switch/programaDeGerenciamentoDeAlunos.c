#include <stdio.h>

int main()
{
    int opcao;
    float nota1, nota2, media;

    printf("Menu de Gerenciamento de EStudantes\n");
    printf("1. Calcular Media\n");
    printf("2. Determinar Status\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Calcular a Média\n");
        printf("Digite a primeira nota: \n");
        scanf("%f", &nota1);
        printf("Digite a segunda nota: \n");
        scanf("%f", &nota2);

        //Testar a condicao se a nota é >= 0 e <= 10
        if ((nota1 >= 0 && nota1 <= 10) && (nota2 >= 0 && nota2 <= 10))
        {
            media = (nota1 + nota2) / 2;
            printf("A média é: %.2f\n", media);
        } else {
            printf("Entrada com valores errados de notas.");
        }
            
        break;

    case 2:
        printf("Determinar o Status do Aluno\n");
        printf("Digite a média do aluno: \n");
        scanf("%f", &media);

        /* Operador ternário para verificar se o aluno foi aprovado ou reprovado
        media >= 5 ? printf("Aluno Aprovado!\n") : printf("Aluno Reprovado!\n"); */

        // Usando estrutura encadeada if-else para determinar o status do aluno
        if (media >= 7){
            printf("Aluno Aprovado!\n");
        } else if (media >= 5) {
            printf("Aluno em Recuperação!\n");
        } else {
            printf("Aluno Reprovado!\n");
        }
        break;

    case 3:
        printf("Saindo do Programa\n");
        break;

    default:
        printf("Opcao Invalida. Tente novamente.\n");
        break;
    }
}