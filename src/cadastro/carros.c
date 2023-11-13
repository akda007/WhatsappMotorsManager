#include "carros.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "../utils/terminal.h"

int digitCount(long int num) {
    if (num / 10 == 0) {
        return 1;
    }

    return 1 + digitCount(num / 10);
}

void getChassi(long int *chassi) {
    scanf("%ld", chassi);
    
    if (digitCount(*chassi) != 6) {
        centralizarTexto("Chassi invalido!\n");
        return getChassi(chassi);
    }
}

void getInt(int *value, int min, int max) {
    scanf("%d", value);

    if (*value < min || *value > max) {
        centralizarTexto("Numero invalido!\n");
        getInt(value, min, max);        
    }
}

void getFloat(float *value, float min) {
    scanf("%f", value);

    if (*value < min) {
        centralizarTexto("Numero invalido!\n");
        getFloat(value, min);        
    }
}

Data_T *cadastro(Data_T *dados, size_t *qtd) {

    dados = realloc(dados, sizeof(Data_T)* ((*qtd) + 1));
    if(dados == NULL){
        exit(-1);
    }
 
    centralizarTexto("*Digite o nome da marca do carro: *");
    scanf("%s", dados[*qtd].marca);

    centralizarTexto("*Digite o nome do modelo do carro: *");
    scanf("%s", dados[*qtd].modelo);

    centralizarTexto("*Digite o ano do carro: *");

    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    getInt(&dados[*qtd].ano, 1860, date.tm_year + 1900);

    centralizarTexto("*Digite o preço do carro: *");
    getFloat( &dados[*qtd].preco, 0);

    bool checkChassi = true;

    while(checkChassi)
    {
        checkChassi = false;

        centralizarTexto("*Digite o chassi do carro: ");
        getChassi(&dados[*qtd].chassi);

        for (int i = 0; i < *qtd - 1; i++)
        {
            if (dados[i].chassi == dados[*qtd].chassi) {
                checkChassi = true;
                
                centralizarTexto("Chassi ja existe!");
                break;
            }
        }
    }

    dados[*qtd].disponivel = true;

    (*qtd) += 1;

    centralizarTexto("Cadastro realizado!");
    Sleep(2000);

    return dados;
}
