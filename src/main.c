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
    
    size_t qtd;
    Data_T *dados_read = read_data(&qtd);

    menu(dados_read, &qtd);
    return 0;
}