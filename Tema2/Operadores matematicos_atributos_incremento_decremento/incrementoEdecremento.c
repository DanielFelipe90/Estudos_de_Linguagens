#include <stdio.h>

int main(){
/*
Incremento (++)
Pré-incremento (++a)
Pós-incremento (a++)
Decremento (--)
Pré-decremento (--a)
Pós-decremento (a--)
*/

int numero1 = 1, resultado;

printf("Antes do incremento: %d\n", numero1);
//numero1 = numero1 + 1;
//numero1+=1;

//Pós incremento: resultado = numero1=1, e depois numero1 recebe + 1;
resultado = numero1++;
//printf("Após incremento: %d\n", numero1);
printf("Após Pós-incremento - numero1: %d - Resultado: %d \n",numero1, resultado);

//Pré-incremento: numero1 recebe + 1, e depois resultado = numero1=2;
resultado = ++numero1;
printf("Após Pré-incremento - numero1: %d - Resultado: %d \n",numero1, resultado);

//Pós-decremento: resultado = numero1=2, e depois numero1 recebe - 1;
resultado = numero1--;
printf("Após Pós-decremento - numero1: %d - Resultado: %d \n",numero1, resultado);

resultado = --numero1;
printf("Após Pré-decremento - numero1: %d - Resultado: %d \n",numero1, resultado);

//numero1 = numero1 - 1;
//numero1-=1;
//numero1--;
//printf("Após decremento: %d\n", numero1);



}