#include <stdio.h>
 
int main() {
    int numeroRegular = 2147483647; // Valor máximo de int
    long int numeroGrande = 2147483647;
 
    printf("Número regular (int): %d\n", numeroRegular);
    printf("Número grande (long int): %ld\n", numeroGrande);
 
    numeroGrande = 2147483648; // Valor maior que o máximo de int
    printf("Número grande atualizado (long long int): %lld\n", numeroGrande);
    // Aqui usamos long long int para suportar valores maiores
    // O long int pode armazenar valores maiores que o int, mas ainda assim não suporta valores acima de 2147483647.
    // O long long int é usado para valores ainda maiores.
    //Dependendo do compilador, long int pode ser igual a int, mas geralmente é maior.
    //Dependendo do sistema (windows, Linux), long int pode ser de 32 bits ou 64 bits.
 
    return 0;
}