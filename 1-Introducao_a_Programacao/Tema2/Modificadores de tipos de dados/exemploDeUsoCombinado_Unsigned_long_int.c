#include <stdio.h>
 
int main() {

    /*A variável largePositiveNumber é declarada como unsigned long int, permitindo armazenar um número positivo extremamente grande. O especificador de formato %lu é usado no printf para exibir valores unsigned long int.*/
    
    unsigned long int largePositiveNumber = 4000000000;
    printf("Número positivo grande: %lu\n", largePositiveNumber);
 
    return 0;
}