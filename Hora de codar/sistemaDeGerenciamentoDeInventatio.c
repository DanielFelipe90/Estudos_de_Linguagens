#include <stdio.h>

int main(){

    //Declarar variaveis char Produto 
    char produtoA[30] = "Produto A";
    char produtoB[30] = "Produto B";

    //Declarar variaveis unsigned int estoque
    unsigned int estoqueA = 1000;
    unsigned int estoqueB = 2000;

    //Declarar variaveis float valor unitario
    float valorA = 10.50;
    float valorB = 20.40;
    
    // Declarar variaveis unsigned int estoque minimo
    unsigned int estoqueMinimoA = 500;
    unsigned int estoqueMinimoB = 2500;
    
    //Declarar variaveis double valor total
    double valorTotalA;
    double valorTotalB;

    //Declarar a variavel int resultadoA, resultadoB para comparações de estoque
    int resultadoA, resultadoB;

    //Exibir as informacoes dos produtos
    printf("Produto %s tem estoque %u e o valor unitário é R$ %.2f\n", produtoA, estoqueA, valorA);
    printf("Produto %s tem estoque %u e o valor unitário é R$ %.2f\n", produtoB, estoqueB, valorB);

    //Comparações com o valor mínimo de estoque
    resultadoA = estoqueA > estoqueMinimoA;
    resultadoB = estoqueB > estoqueMinimoB;

    printf("O produto %s tem estoque minimo %d\n", produtoA, resultadoA);
    printf("O produto %s tem estoque minimo %d\n", produtoB, resultadoB);

    //Comparações entre os valores totais dos produtos
    printf("O valor total de A (R$%.2f) é maior que o valor total de B (R$%.2f)? %d\n", estoqueA * valorA, estoqueB * valorB, (estoqueA * valorA) > (estoqueB * valorB));
    
    return 0;
}