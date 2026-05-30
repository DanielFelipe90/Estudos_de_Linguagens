#include <stdio.h>

int main(){

    int idade = 20;
    float altura = 1.75;

    //idade >= 18 => true
    //idade <= 30 => true
    //verdadeiro && verdadeiro => true
    //verdadeiro && altura > 1.70
    //verdadeiro && verdadeiro => true

    if (idade >= 18 && idade <= 30 && altura > 1.70) {
        printf("Você está na faixa etária e tem altura adequada.\n");
    } else {
        printf("Você não atende aos critérios.\n");
    }

    return 0;
}