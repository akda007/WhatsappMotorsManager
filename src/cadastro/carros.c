#include "carros.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "../utils/terminal.h"

void getInt(int *value, int min, int max) {
    scanf("%d", value);

    if (*value < min || *value > max) {
        printf("Valor invalido!");
        getInt(value, min, max);        
    }
}

void getFloat(float *value, float min, float max) {
    scanf("%f", value);

    if (*value < min || *value > max) {
        printf("Valor invalido!");
        getInt(value, min, max);        
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

    getInt(&dados[*qtd].ano, 1860, date.tm_year);

    centralizarTexto("*Digite o preço do carro: *");
    scanf("%f", &dados[*qtd].preco);

    centralizarTexto("*Digite o chassi do carro: *");
    scanf("%ld", &dados[*qtd].chassi);

    dados[*qtd].disponivel = true;

    (*qtd) += 1;

    centralizarTexto("Cadastro realizado!");
    Sleep(2000);

    return dados;
}
