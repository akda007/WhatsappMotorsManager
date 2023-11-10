#include <stdio.h>

#include "database/database.h"

#include <string.h>


int main() {
//     Data_T dados[2];
//
//     dados[0].ano = 2032;
//     dados[0].chassi = 23213211;
//     dados[0].disponivel = true;
//     strcpy(dados[0].marca, "merceds");
//     strcpy(dados[0].modelo, "gol");
//
//     dados[1].ano = 2002;
//     dados[1].chassi = 50661231;
//     dados[1].disponivel = true;
//     strcpy(dados[1].marca, "ferrari");
//     strcpy(dados[1].modelo, "F5");
//
//     save_data(dados, 2);

    size_t qtd;
    Data_T *dados = read_data(&qtd);


    for (size_t i = 0; i < qtd; i++)
    {
        printf("%s\n", dados[i].marca);
        printf("%s\n", dados[i].modelo);
        printf("%d\n", dados[i].ano);
        printf("%lu\n", dados[i].chassi);
        printf("%d\n", dados[i].disponivel);
        printf("%.2f\n", dados[i].preco);
    }


    free(dados);
    return 0;
}