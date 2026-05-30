#include <stdio.h>

int main(){
/*
Atribuição Simples (=)
Atribuiçaõ por Soma (+=)
Atribuição por Subtração (-=)
Atribuição por Multiplicação (*=)
Atribuição por Divisão (/=)
*/

int numero1 = 10, numero2, resultado;
resultado = 10;
printf("Resutado: %d\n", resultado);

//Resultado = resultado + 20;
resultado +=20;
printf("Resultado: %d\n", resultado);

//Resultado = resultado - numero1;
resultado -= numero1;
printf("Resultado: %d\n", resultado);

//Resultado = resultado * 5;
resultado *= 5;
printf("Resultado: %d\n", resultado);

//Resultado = resultado / 2;
resultado /= 2;
printf("Resultado: %d\n", resultado);

}