#include "carros.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "../utils/terminal.h"


#define printInfo(text, format) centralizarTexto(text); \
                                          MOVE_LEFT((strlen(text) + strlen(format))/ 2); \
                                          printf(format)

const char * text = "|                                                  | ";

void printInfoColored(const char *print_text, int r, int g, int b){
    centralizarTexto(text); 
    MOVE_LEFT((strlen(text) + strlen(print_text)) / 2); 
    FOREGROUND_COLOR(r, g, b);
    printf(print_text);
    RESET_FOREGROUND(); 
    printf("\n");

}
int digitCount(long int num) {
    if (num / 10 == 0) {
        return 1;
    }

    return 1 + digitCount(num / 10);
}

bool getChassi(long int *chassi) {
    scanf("%ld", chassi);
    
    if (digitCount(*chassi) != 6) {
        return false;
    }

    return true;
}

void getInt(int *value, int min, int max) {
    printInfo(text, "Digite o ano do carro:             ");
    MOVE_LEFT(11);

    scanf("%d", value);

    if (*value < min || *value > max) {
        printInfoColored("Numero Invalido!", 255, 0, 0);
        
        getInt(value, min, max);        
    }
}

void getFloat(float *value, float min) {
    printInfo(text, "Digite o preco do carro:           ");
    MOVE_LEFT(10);

    scanf("%f", value);

    if (*value < min) {
        printInfoColored("Numero Invalido!", 255, 0, 0);

        getFloat(value, min);        
    }
}

Data_T *cadastro(Data_T *dados, size_t *qtd) {

    dados = realloc(dados, sizeof(Data_T)* ((*qtd) + 1));
    if(dados == NULL){
        exit(-1);
    }


    printf("\n");
 
    printInfo(text, "Digite a marca do carro:           ");
    MOVE_LEFT(9);

    scanf("%s", dados[*qtd].marca);

    printInfo(text, "Digite o modelo do carro:          ");
    MOVE_LEFT(8);

    scanf("%s", dados[*qtd].modelo);


    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    getInt(&dados[*qtd].ano, 1860, date.tm_year + 1900);


    getFloat( &dados[*qtd].preco, 0);

    bool checkChassi = true;

    while(checkChassi)
    {
        checkChassi = false;

        printInfo(text, "Digite o chassi do carro:          ");
        MOVE_LEFT(8);

        if (!getChassi(&dados[*qtd].chassi)) {
            printInfoColored("Chassi Invalido", 255,0,0);

            checkChassi = true;
            continue;
        }


        if (*qtd > 1)
        for (int i = 0; i < *qtd; i++)
        {
            if (dados[i].chassi == dados[*qtd].chassi) {
                checkChassi = true;
                
                printInfoColored("Chassi ja cadastrado", 255,0,0);
                
                break;
            }
        }
    }

    dados[*qtd].disponivel = true;

    (*qtd) += 1;

    printInfoColored("Veiculo cadastrado com sucesso!", 0, 255, 0);
    centralizarTexto("---------------------------------------------------- ");
    printf("\n");

    Sleep(2000);

    return dados;
}
