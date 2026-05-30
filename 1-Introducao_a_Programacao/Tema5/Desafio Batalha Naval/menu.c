#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define TOTAL_OPCOES 4

void setColor(int textColor, int bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor + (bgColor << 4));
}

void limparTela() {
    system("cls");
}

void desenharMenu(int selecionado) {
    const char *opcoes[TOTAL_OPCOES] = {
        "Iniciar",
        "Opcoes",
        "Creditos",
        "Sair"
    };

    limparTela();

    for (int i = 0; i < TOTAL_OPCOES; i++) {
        if (i == selecionado) {
            setColor(0, 14); // texto preto, fundo amarelo
            printf(" > %s <\n", opcoes[i]);
        } else {
            setColor(15, 0); // texto branco, fundo preto
            printf("   %s\n", opcoes[i]);
        }
    }

    setColor(15, 0); // resetar cor
}

int main() {
    int selecionado = 0;
    int tecla;

    desenharMenu(selecionado);

    while (1) {
        tecla = getch();

        if (tecla == 0 || tecla == 224) {
            tecla = getch(); // captura a segunda parte da tecla especial

            switch (tecla) {
                case 72: // seta para cima
                    selecionado = (selecionado - 1 + TOTAL_OPCOES) % TOTAL_OPCOES;
                    break;
                case 80: // seta para baixo
                    selecionado = (selecionado + 1) % TOTAL_OPCOES;
                    break;
            }

            desenharMenu(selecionado);
        } else if (tecla == 13) { // Enter
            break;
        }
    }

    limparTela();
    printf("Você escolheu: %s\n", selecionado == 0 ? "Iniciar" :
                                     selecionado == 1 ? "Opcoes" :
                                     selecionado == 2 ? "Creditos" : "Sair");

    return 0;
}
