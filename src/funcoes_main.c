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

void printHeader(const char * text, int r, int g, int b) {
    const char * text_holder = "*                                                  * ";

    centralizarTexto("**************************************************** ");
    ERASE_LEND();
    printf("\n");
    centralizarTexto("*                                                  * ");
    ERASE_LEND();

    MOVE_LEFT((strlen(text_holder) + strlen(text) + 1) / 2);

    if (r >= 0 || g >= 0 || b >= 0) {
        FOREGROUND_COLOR(r, g, b);
    }

    printf(text);
    RESET_FOREGROUND();

    printf("\n");
    centralizarTexto("**************************************************** ");
    ERASE_LEND();

}

void listarCarros(Data_T *dados, size_t qtd) {
    printHeader("LISTA DE CARROS", 18, 140, 126);

    printf("\n");

    if (qtd == 0) {
        MOVE_UP(1);
        printHeader("Sem carros cadastrados", 255,0,0);
    } else {

        sortData(dados, qtd);
        for (size_t i = 0; i < qtd; i++) {
            printCarro(&dados[i]);
        }
    }


    printf("\n");
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
    
    // centralizarTexto("****************************************************\n");
    // centralizarTexto("*                                                  * ");

    // MOVE_LEFT(47);
    // FOREGROUND_COLOR(255, 0 , 0);
    // printf("Insira o chassi para a consulta:");
    // RESET_FOREGROUND();

    // printf("\n");
    // centralizarTexto("**************************************************** ");

    printHeader("Insira o chassi para a consulta:              ", 37, 211, 102);

        
    MOVE_UP(1);
    MOVE_LEFT(14);
    FOREGROUND_COLOR(156, 194, 247);
    
    
    fflush(stdin); 
    scanf("%ld", &chassiConsulta); 
    RESET_FOREGROUND();
        
    Data_T *carro = findData(dados, qtd, chassiConsulta);

    printf("\n");

    if (carro == NULL) {
        MOVE_UP(1);
        printHeader("Chassi nao encontrado", 255,0,0);
        printf("\n");
    } else {
        printCarro(carro);
    }

    printf("\n");
    centralizarTexto("Deseja verificar outro carro?(s/n):  ");
    fflush(stdin);
    scanf(" %c", &opcao);

    if(opcao == 's'){
        MOVE_UP(3);
        
        goto startConsulta;
    }

}


Data_T * CadastroCarro(Data_T *dados, size_t *qtd) {
        
    printHeader("CADASTRO DE CARRO", 37, 211, 102);

    dados = cadastro(dados, qtd);

    save_data(dados, *qtd);

    return dados;
}
 

void DesativarCarro(Data_T *dados, size_t qtd) {
    MOVE_HOME();
    ERASE_CUREND();
    
    long int chassi;

    printHeader("Insira o chassi para desativar/ativar:          ", 37, 211, 102);

    MOVE_LEFT(12);
    MOVE_UP(1);
    getChassi(&chassi);

    bool ret = disableCar(dados, qtd, chassi);    

    if (ret) {
        Data_T *carro = findData(dados, qtd, chassi);

        printHeader(carro->disponivel ? "Carro Ativado!" : "Carro Desativado!", 0, 255, 0);
    } else {
        printHeader("Carro nao encontrado!", 255, 0, 0);
    }

    printf("\n");

    centralizarTexto("Aperte qualquer tecla para voltar");
    centralizarTexto("\n");

    fflush(stdin);
    getchar();
}

void ExcluirCarro(Data_T *dados, size_t *qtd){
    
    MOVE_HOME();
    ERASE_CUREND();
    
    long int ChassiExcluir;
    
    printHeader("Insira o chassi para a exclusao:             ", 37, 211, 102);


    MOVE_LEFT(12);
    MOVE_UP(1);
    while (!getChassi(&ChassiExcluir)) {
        printHeader("Chassi invalido!", 255, 0, 0);
        
        printf("\n");

        MOVE_UP(1);
        printHeader("Insira o chassi para a exclusao:             ", 37, 211, 102);
        MOVE_LEFT(12);
        MOVE_UP(1);
    }

    bool ret = excludeCar(dados, qtd, ChassiExcluir);

    if (ret) {
        printHeader("Carro excluido com sucesso!", 0, 255, 0);
    } else {
        printHeader("Carro nao encontrado!", 255, 0, 0);
    }

    printf("\n");
    centralizarTexto("Aperte qualquer tecla para voltar");
    printf("\n");    
    fflush(stdin);
    getchar();
}

void VenderCarro(Data_T *dados, size_t *qtd){
    
    long int ChassiCompra;
    char opcaoCompra;
    char opcaoMenu;
    Data_T *CarroCompra;

    startCompra: 

    printf("\n");
    printHeader("Insira o chassi desejado para a venda:         ", 37, 211, 102);

    MOVE_LEFT(11);
    MOVE_UP(1);
    fflush(stdin);
    scanf("%ld", &ChassiCompra);

    CarroCompra = findData(dados, *qtd, ChassiCompra);

    printf("\n");

    if (CarroCompra == NULL) {
        MOVE_UP(1);

        printHeader("Chassi nao encontrado", 255, 0, 0);

        printf("\n");
        centralizarTexto("Deseja vender outro carro?(s/n):  ");
        fflush(stdin);
        scanf(" %c", &opcaoMenu);

        if(opcaoMenu == 's' || opcaoMenu == 'S'){
            MOVE_UP(3);

            goto startCompra;
        } 

        return;
    }

    if(!CarroCompra->disponivel) {
        MOVE_UP(1);
        printHeader("Carro nao disponivel.", 255, 0, 0);

        printf("\n");
        centralizarTexto("Deseja vender outro carro?(s/n):  ");
        fflush(stdin);
        scanf(" %c", &opcaoMenu);

        if(opcaoMenu == 's' || opcaoMenu == 'S'){
            MOVE_UP(3);

            goto startCompra;
        } 

        return;
    }
    printCarro(CarroCompra);
    MOVE_UP(1);

    printHeader("Esse e o carro desejado?(s/n): ", 37, 211, 102);

    MOVE_LEFT(11);
    MOVE_UP(1);

    fflush(stdin);
    scanf(" %c", &opcaoCompra);

    if(opcaoCompra == 's' || opcaoCompra == 'S'){
        FOREGROUND_COLOR(0,255,0);
        centralizarTexto("Parabens pela compra!, a WhatsappMotors Agradece!");
        RESET_FOREGROUND();

        excludeCar(dados, qtd, ChassiCompra);
        save_data(dados, *qtd);
    } else {
        MOVE_UP(1);
        goto startCompra;
    }

    printf("\n");
    centralizarTexto("Deseja comprar outro carro?(s/n):  ");
    fflush(stdin);
    scanf(" %c", &opcaoMenu);

    if(opcaoMenu == 's' || opcaoMenu == 'S'){
        MOVE_UP(2);
        
        goto startCompra;
    } 

}
    




void menu(Data_T *dados, size_t *qtd){
    
    char opcao;
    start: 
    
    system("cls");
    
    printHeader("Whatsapp Motors", 0, 255, 0);
    ERASE_LEND();
    printf("\n");
    ERASE_LEND();
    centralizarTexto("| 1. Cadastrar novo carro                        |\n");
    ERASE_LEND();
    centralizarTexto("| 2. Listar todos os carros                      |\n");
    ERASE_LEND();
    centralizarTexto("| 3. Consultar carro por chassi                  |\n");
    ERASE_LEND();
    centralizarTexto("| 4. Desativar/Ativar um carro                   |\n");
    ERASE_LEND();
    centralizarTexto("| 5. Excluir um carro                            |\n");
    ERASE_LEND();
    centralizarTexto("| 6. Vender um carro                             |\n");
    ERASE_LEND();
    centralizarTexto("| 0. Sair                                        |\n");
    ERASE_LEND();
    centralizarTexto("****************************************************\n");
    ERASE_LEND();
    centralizarTexto("Digite a opcao: ");
    ERASE_LEND();

    ERASE_CUREND();
    
    fflush(stdin);
    scanf("%c", &opcao);

    MOVE_HOME();
    ERASE_CUREND();

    switch (opcao)
    {
    case '1':
        dados = CadastroCarro(dados, qtd);
        goto start;

    case '2':
        fflush(stdout);
        listarCarros(dados, *qtd);
        goto start;
    
    case '3':
        ConsultaChassi(dados, *qtd);
        goto start;
    
    case '4':
        DesativarCarro(dados, *qtd);
        save_data(dados, *qtd);
        goto start;
    
    case '5':
        ExcluirCarro(dados, qtd);
        save_data(dados, *qtd);
        goto start;

    case '6':
        VenderCarro(dados, qtd);
        save_data(dados, *qtd);
        goto start;

    case '0':
        free(dados);
        exit(0);
    
    default:
        printHeader("Valor invalido", 255,0,0);

        Sleep(1300);

        goto start;
    }
}