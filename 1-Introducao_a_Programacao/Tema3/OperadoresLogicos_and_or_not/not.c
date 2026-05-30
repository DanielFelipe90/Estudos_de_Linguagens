#include <stdio.h>

int main(){

    int a = 0, b = 10, c = -5;

    if (!a) {
        printf("A variável a é zero.\n");
    } else {
        printf("A variável a é diferente de zero.\n");
    }

    if(!(a > 0)){
        printf("A variável b é negativa.\n");
    } else {
        printf("A variável b é positiva.\n");
    }

     if(!(c > 0)){
        printf("A variável c é negativa.\n");
    } else {
        printf("A variável c é positiva.\n");
    }
    return 0;
}