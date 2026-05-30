#include <stdio.h>

int main(){

    int i = 1;

    while (i <= 5)
    {
        printf("%d\n", i);
        i++; //Incrementar para não acontecer o loop infinito
    }
    
    return 0;
}