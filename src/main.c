#include <stdio.h>
#include "database/dbtools.h" 
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "funcoes_main.h"
#include "utils/terminal.h"


int main() {
    configureTerminal();
    DISABLE_WRAP();
    

    system("cls");
    FILE *wpp = fopen("whatsapp.txt", "r");

    BACKGROUND_COLOR(32, 66, 43);
    FOREGROUND_COLOR(255,255,255);
    char c[200];
    while(fgets(c, sizeof(c), wpp) != NULL) {
        ERASE_LEND();
        centralizarTexto(c);
        ERASE_LEND();

        Sleep(100);
    }

    ERASE_CUREND();

    Sleep(1500);

    system("cls");
    // Data_T dados[4];

    // dados[0].ano = 2002;
    // dados[0].chassi = 647435;
    // dados[0].disponivel = true;
    // dados[0].preco = 300.0;
    // strcpy(dados[0].marca, "ferrari");
    // strcpy(dados[0].modelo, "F5");

    // dados[1].ano = 2032;
    // dados[1].chassi = 567485;
    // dados[1].disponivel = true;
    // dados[1].preco = 300.0;
    // strcpy(dados[1].marca, "merceds");
    // strcpy(dados[1].modelo, "gol");

    // dados[2].ano = 2012;
    // dados[2].chassi = 456748;
    // dados[2].disponivel = true;
    // dados[2].preco = 300.0;
    // strcpy(dados[2].marca, "aaaa");
    // strcpy(dados[2].modelo, "Saveiro");

    // dados[3].ano = 2032;
    // dados[3].chassi = 457864;
    // dados[3].disponivel = true;
    // dados[3].preco = 300.0;
    // strcpy(dados[3].marca, "fasfasd");
    // strcpy(dados[3].modelo, "yasuo");

    // save_data(dados, 4);
    
    size_t qtd;
    Data_T *dados_read = read_data(&qtd);

    menu(dados_read, &qtd);
    return 0;
}