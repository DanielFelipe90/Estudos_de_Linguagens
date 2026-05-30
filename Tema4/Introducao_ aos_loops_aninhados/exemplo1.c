#include <stdio.h>

int main(){
    //Programa da tabuada usando loop aninhado
    for (int i = 1; i <=10; i++)//Estrutura loop for externa
    {
        printf("Tabuada de %d:\n", i);
        for (int j = 1; j <= 10; j++) 
        /* Estrutura loop for interna, vai rodar esse loop 10 vezes pra depois rodar novamente o loop externo */
        {
            printf("%d x %d = %d\n", i, j, i * j);
            // Loop aninhado para simular um atraso
            for (int i = 0; i < 100000000; i++) {
            // Apenas para simular um atraso
            }
        }
        printf("\n");
    }


    //Loop aninhado usando while,Programa da tabuada
    /* int i = 1;
    while (i <= 10) {
        int j = 1;
        printf("Tabuada de %d:\n", i);
        while (j <= 10) {
            printf("%d x %d = %d\n", i, j, i * j);
            j++;
        }
        printf("\n");
        i++;
    } */

    /* Loop aninhado usando do-while Programa da tabuafa*/
     /* int i = 1;
    do {
        int j = 1;
        printf("Tabuada de %d:\n", i);
        do {
            printf("%d x %d = %d\n", i, j, i * j);
            j++;
        } while (j <= 10);
        printf("\n");
        i++;
    } while (i <= 10); */

    return 0;
}