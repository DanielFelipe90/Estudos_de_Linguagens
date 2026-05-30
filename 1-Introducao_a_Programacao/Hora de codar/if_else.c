#include <stdio.h>

int main(){

    int numero1;
    int numero2;

    numero1 = 10;
    numero2 = 20;

    if (numero1 > numero2){
        //bloco de codigo a ser executado se a condicao for verdadeira
        printf("Numero 1 é maior que Numero 2\n");
    }
    else {
        //bloco de codigo a ser executado se a condicao for falsa
        printf("Numero 1 não é menor que Numero 2\n");
    }

    return 0;
}