#include <stdio.h>
#include "database/dbtools.h" 
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "utils/terminal.h"
#include "cadastro/carros.h"

#define printInfo(text, format, arg) centralizarTexto(text); \
                                          MOVE_LEFT(strlen(text) - 4); \
                                          printf(format, arg)

void printCarro(Data_T *carro) {
    const char * text = "|                                                  | ";

    printInfo(text, "Marca: %s\n", carro->marca); 
    printInfo(text, "Modelo: %s\n", carro->modelo);
    printInfo(text, "Chassi: %ld\n", carro->chassi);
    printInfo(text, "Ano: %i\n", carro->ano);
    printInfo(text, "Preco: %f\n", carro->preco);
    printInfo(text, "Disponivel: %s\n", carro->disponivel ? "Sim" : "Nao");

    centralizarTexto("****************************************************\n");

}

void listarCarros(Data_T *dados, size_t qtd) {
    sortData(dados, qtd);

    const char * title = "LISTA DE VEICULOS";
    const char * text_holder = "*                                                  * ";


    centralizarTexto("****************************************************\n");
    centralizarTexto("*                                                  * ");

    MOVE_LEFT((strlen(text_holder) + strlen(title) + 1) / 2);

    FOREGROUND_COLOR(18, 140, 126);
    printf(title);
    RESET_FOREGROUND();

    printf("\n");
    centralizarTexto("****************************************************\n");

    for (size_t i = 0; i < qtd; i++) {
        printCarro(&dados[i]);
    }

    centralizarTexto("Aperte qualquer tecla para voltar");
    printf("\n");    
    fflush(stdin);
    getchar();
}

void ConsultaChassi(Data_T *dados, size_t qtd){
    long int chassiConsulta;
    char opcao; 
    
    MOVE_HOME();
    ERASE_CUREND();

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

    if (carro == NULL) {
        centralizarTexto("Chassi nao encontrado\n");
    } else {
        printCarro(carro);
    }

    centralizarTexto("Deseja verificar outro carro?(s/n):  ");
    scanf(" %c", &opcao);

    if(opcao == 's'){
        MOVE_UP(2);
        
        goto startConsulta;
    }

}


Data_T * CadastroCarro(Data_T *dados, size_t *qtd) {
        
    centralizarTexto("****************************************************\n");
    centralizarTexto("*                Cadastro de Carros                *\n");
    centralizarTexto("****************************************************\n");

    dados = cadastro(dados, qtd);

    save_data(dados, *qtd);

    return dados;
}
 

void DesativarCarro(Data_T *dados, size_t qtd) {
    
}


void menu(Data_T *dados, size_t *qtd){
    
    int opcao;
    start: 
    
    system("cls");
    
    centralizarTexto(        "****************************************************\n");
    centralizarTexto("========*                 Whatsapp Motors                  *========\n");
    centralizarTexto("****************************************************\n");
    centralizarTexto("| 1. Cadastrar novo carro                        |\n");
    centralizarTexto("| 2. Listar todos os carros                      |\n");
    centralizarTexto("| 3. Consultar carro por chassi                  |\n");
    centralizarTexto("| 4. Desativar um carro                          |\n");
    centralizarTexto("| 5. Excluir um carro                            |\n");
    centralizarTexto("| 6. Vender um carro                             |\n");
    centralizarTexto("| 0. Sair                                        |\n");
    centralizarTexto("****************************************************\n");
    centralizarTexto("Digite a opcao: ");

    ERASE_CUREND();
    
    fflush(stdin);
    scanf("%i", &opcao);

    MOVE_HOME();
    ERASE_CUREND();

    switch (opcao)
    {
    case 1:
        dados = CadastroCarro(dados, qtd);
        goto start;
        break;

    case 2:
        fflush(stdout);
        listarCarros(dados, *qtd);
        goto start;
        break;
    
    case 3:
        ConsultaChassi(dados, *qtd);
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