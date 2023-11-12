#include <stdio.h>
#include "database/dbtools.h" 
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "utils/terminal.h"

#define printInfo(text, format, arg) centralizarTexto(text); \
                                          MOVE_LEFT(strlen(text) - 4); \
                                          printf(format, arg)

int getTerminalWidth() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO console_info;

    if (GetConsoleScreenBufferInfo(hConsole, &console_info)) {
        return console_info.dwSize.X;
    } else {
        return -1;
    }
}

void centralizarTexto(const char *texto) {
    int larguraLinha = getTerminalWidth();

    int posicaoInicial = (larguraLinha - strlen(texto)) / 2;

    for (int i = 0; i < posicaoInicial; i++) {
        printf(" ");
    }

    printf("%s", texto);
}

void listarCarros() {
    
}

void ConsultaChassi(Data_T *dados, size_t qtd){
    
    long int chassiConsulta;
    char opcao; 
    
    ERASE_ALL();
    MOVE_HOME();

    startConsulta: 
    
    centralizarTexto("****************************************************\n");
    centralizarTexto("*                                                  * ");

    MOVE_LEFT(47);
    FOREGROUND_COLOR(255, 0 , 0);
    printf("Insira o chassi para a consulta:");
    RESET_FOREGROUND();

    printf("\n");
    centralizarTexto("**************************************************** ");
        
    MOVE_UP(1);
    MOVE_LEFT(14);
    FOREGROUND_COLOR(156, 194, 247);
    
    fflush(stdin); 
    scanf("%ld", &chassiConsulta); 
    RESET_FOREGROUND();
        
    Data_T *carro = findData(dados, qtd, chassiConsulta);

    printf("\n");

    
    const char * text = "|                                                  | ";

    printInfo(text, "Marca: %s\n", carro->marca); 
    printInfo(text, "Modelo: %s\n", carro->modelo);
    printInfo(text, "Chassi: %ld\n", carro->chassi);
    printInfo(text, "Ano: %i\n", carro->ano);
    printInfo(text, "Preco: %f\n", carro->preco);
    printInfo(text, "Disponivel: %s\n", carro->disponivel ? "Sim" : "Nao");

    centralizarTexto("****************************************************\n");
    
    centralizarTexto("Deseja verificar outro carro?(s/n):  ");
    
    scanf(" %c", &opcao);

    if(opcao == 's'){
        MOVE_UP(2);
        
        goto startConsulta;
    }

}





void menu(Data_T *dados, size_t qtd){
    
    int opcao;
    start: 
    
    ERASE_ALL();
    MOVE_HOME();
    
    centralizarTexto(        "****************************************************\n");
    centralizarTexto("========*                 Whatsapp Motors                  *========\n");
    centralizarTexto("****************************************************\n");
    centralizarTexto("* 1. Cadastrar novo carro                        *\n");
    centralizarTexto("* 2. Listar todos os carros                      *\n");
    centralizarTexto("* 3. Consultar carro por chassi                  *\n");
    centralizarTexto("* 4. Desativar um carro                          *\n");
    centralizarTexto("* 5. Excluir um carro                            *\n");
    centralizarTexto("* 6. Vender um carro                             *\n");
    centralizarTexto("* 0. Sair                                        *\n");
    centralizarTexto("****************************************************\n");
    centralizarTexto("Digite a opcao: ");
    
    fflush(stdin);
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
        
        break;

    case 2:

        break;
    
    case 3:
        ConsultaChassi(dados, qtd);
        goto start;
        break;
    
    case 4:

        break;
    
    case 5:

        break;

    case 6:

        break;

    case 0:

        break;
    
    default:
        break;
    }
}