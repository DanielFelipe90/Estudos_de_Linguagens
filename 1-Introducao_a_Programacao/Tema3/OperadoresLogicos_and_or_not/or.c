#include <stdio.h>

int main(){

    int a = 10, b = 5;

    if (a > 0 || b > 0) {
        printf("Pelo menos um dos dois números são positivo\n");
    } else {
        printf("Os dois números são negativos.\n");
    }

    return 0;
}