#include <stdio.h>

/* Na passagem por valor, a função recebe uma cópia da variável original. 
Isso significa que a função pode modificar essa cópia à vontade, mas a 
variável original — aquela que está no main() ou em outro lugar do 
programa — não será alterada. A ideia é simples: você entrega uma 
cópia para a função usar, como um documento escaneado. Ela pode riscar, 
dobrar ou jogar fora a cópia, mas sua versão original continua segura e intacta.*/

// Está função recebe uma copia do valor da variável
void dobrar(int x){
    x = x * 2;
    printf("Dentro da função, o valor da cópia é: %d\n", x);
}

int main(){
    int numero = 5;
    printf("Antes de chamar a função, o valor orifinal é: %d\n", numero);

    // Passando "numero" por valor
    dobrar(numero);

    printf("Depois de chamar a função, o valor original é %d\n", numero);

    return 0;
}