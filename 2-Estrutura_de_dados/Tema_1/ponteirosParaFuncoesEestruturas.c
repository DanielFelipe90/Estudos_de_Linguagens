#include <stdio.h>
#include <stdlib.h>

// FUNÇÃO UTILIZADADA COMO EXEMPLO PARA PONTEIRO PARA FUNÇÃO
void saudacao()
{
    printf("Olá! Bem-vindo ao mundo dos ponteiros e estruturas em C!\n\n");
}

// ESTRUTURA PARA EXEMPLO DE USO DE STRUCTS COM PONTEIROS
typedef struct
{
    char nome[50];
    int idade;
} Pessoa;

int main(){

    // PONTEIROS PARA APONTAR PARA FUNÇÕES
    // Declarando um ponteiro 'ptr' para uma função
    // que não retorna nada (void) e não recebe parâmetros
    void (*ptr)() = saudacao;

    // Chamando a função através do ponteiro
    ptr();

    // PONTEIROS PARA ESTRUTURAS
    // p éum ponteiro apar uma pessoa
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));

    printf("Digite o nome da pessoa: \n");
    // Lê o nome da pessoa, usamos a seta (->) para acessar os membros da estrutura através do ponteiro
    fgets(p->nome, 50, stdin); 

    printf("Digite a idade da pessoa: \n");
    scanf("%d", &p->idade); // Lê a idade da pessoa

    printf("\nPessoa cadastrada:\n");
    printf("Nome: %s", p->nome); // Imprime o nome da pessoa
    printf("Idade: %d\n", p->idade); // Imprime a idade

    free(p); // Libera a memória alocada para a pessoa

    return 0;
}