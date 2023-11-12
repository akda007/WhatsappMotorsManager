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

    
    
    size_t qtd;
    Data_T *dados = read_data(&qtd);

    



    menu(dados, qtd);
    return 0;
}