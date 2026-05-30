#include <stdio.h>

int main(){

float temperatura, umidade;
unsigned int estoque, estoque_minimo = 1000;

printf("Entre com a temperatura atual: \n");
scanf("%f", &temperatura);
printf("Entre com a umidade atual: \n");
scanf("%f", &umidade);
printf("Entre com o estoque atual: \n");
scanf("%u", &estoque);

if (temperatura > 30.0) {
    printf("Alerta: Temperatura acima do limite!\n");
} 
else{
    printf("Temperatura dentro do limite.\n");
}

if (umidade > 50.0) {
    printf("Alerta: Umidade acima do limite!\n");  
}
else{
    printf("Umidade dentro do limite.\n");
}

if (estoque < estoque_minimo){
    printf("Alerta: Estoque abaixo do limite!\n");
}
else{
    printf("Estoque dentro do limite.\n");
}

}