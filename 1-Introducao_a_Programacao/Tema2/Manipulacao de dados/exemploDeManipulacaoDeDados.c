#include <stdio.h>

int main(){

int a =10;
float b = 3.5;
float resultado = a + b; //'a' é convertido implicitamente para float

printf("Resultado: %.2f\n", resultado); // Exibe o resultado com duas casas decimais

int c = 10;
int d = 3;
float quociente = (float) c / d; // Usando a variavel (float) 'c' é convertido explicitamente para float

printf("Quociente: %.2f\n", quociente); // Exibe o quociente com duas casas decimais

    return 0;
}