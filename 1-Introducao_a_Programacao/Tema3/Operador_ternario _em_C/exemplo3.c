#include <stdio.h>

int main() {
    int temperatura = 10;
    int resultado;

    resultado = temperatura > 30 ? 1 : 0;

    if(resultado == 1) {
        printf("Temperatura acima de 30 graus.\n");
    } else {
        printf("Temperatura abaixo de 30 graus.\n");
    }


}