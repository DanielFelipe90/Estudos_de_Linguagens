#include<stdio.h>
#include<string.h>

int main() {

    int idade, matricula, peso;
    float altura;
    char nome[50];
    
    printf("Digite seu nome: \n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu peso: \n");
    scanf("%d", &peso);

    printf("Digite sua matricula: \n");
    scanf("%d", &matricula);

    printf("Nome do aluno: %s \nMatricula: %d\n", nome, matricula);
    printf("Idade: %d - Altura: %.2f - Peso: %d", idade, altura, peso);

    return 0;
}