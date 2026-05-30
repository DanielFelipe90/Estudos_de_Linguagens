#include <stdio.h>

/* Na programação, quando queremos que uma função modifique diretamente o valor de uma variável, 
usamos a técnica chamada passagem de parâmetros por referência. 
Isso significa que, em vez de enviar uma cópia da variável para a 
função (como na passagem por valor), enviamos o endereço de memória no qual a variável 
está armazenada. Com esse endereço, a função pode acessar e alterar o conteúdo original.*/

// A função agora recebe um endereço (ponteiro para int)
void dobrar(int *x){
    // Acessando o valor no ENDEREÇO e o modificamos.
    *x = (*x) * 2;
}

int main(){
    int numero = 5;
    printf("Antes da função, o valor é: %d\n", numero);

    // Passamos o ENDEREÇO de 'numero' com o operador &
    dobrar(&numero);

    printf("Depois da função, o valor é: %d\n", numero);

    return 0;
}