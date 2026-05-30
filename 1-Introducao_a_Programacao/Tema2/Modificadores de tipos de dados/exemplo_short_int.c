#include <stdio.h>

int main(){
short int numeroPequeno = 32767; // Valor máximo de short int
printf("Número pequeno (short int): %hd\n", numeroPequeno);

numeroPequeno = 32768; // Valor maior que o máximo de short int
printf("Número pequeno atualizado (short int): %hd\n", numeroPequeno);

printf("\n*** Tamanho das variáveis ***\n");
printf("Short int: %lu B - int: %lu B - long int:%lu B\n", sizeof(short int), sizeof(int), sizeof(long long int));
printf("Float: %lu B - double: %lu B - long double: %lu B\n", sizeof(float), sizeof(double), sizeof(long double));
// O short int é mais utilizado para economizar memória quando sabemos que os valores não excederão o intervalo de -32768 a 32767.
    return 0;
}