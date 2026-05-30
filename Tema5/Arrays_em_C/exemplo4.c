/* Aplicações simples de arrays

Os arrays são usados para armazenar conjuntos de dados relacionados de maneira eficiente. A seguir, veremos algumas aplicações simples de arrays, demonstrando como eles podem ser úteis em diversas situações. Vejamos cada uma a seguir.

Armazenamento de notas de alunos

Arrays podem ser usados para armazenar as notas de um grupo de alunos, facilitando o cálculo de médias e a verificação de desempenho. Veja o código a seguir. */

#include <stdio.h>
 
int main() {
    float notas[3] = {85.5, 90.0, 78.0};  // Array de notas de 3 alunos
 
    printf("Nota do primeiro aluno: %.1f\n", notas[0]);
    printf("Nota do segundo aluno: %.1f\n", notas[1]);
    printf("Nota do terceiro aluno: %.1f\n", notas[2]);
 
    return 0;
}

/* Nesse exemplo, um array notas armazena as notas de três alunos e as imprime. */