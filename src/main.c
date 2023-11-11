#include <stdio.h>

#include "database/dbtools.h" 

#include <string.h>


int main() {
    Data_T dados[4];

    dados[0].ano = 2002;
    dados[0].chassi = 50661231;
    dados[0].disponivel = true;
    dados[0].preco = 300.0;
    strcpy(dados[0].marca, "ferrari");
    strcpy(dados[0].modelo, "F5");

    dados[1].ano = 2032;
    dados[1].chassi = 23213211;
    dados[1].disponivel = true;
    dados[1].preco = 300.0;
    strcpy(dados[1].marca, "merceds");
    strcpy(dados[1].modelo, "gol");

    dados[2].ano = 2012;
    dados[2].chassi = 32113211;
    dados[2].disponivel = true;
    dados[2].preco = 300.0;
    strcpy(dados[2].marca, "aaaa");
    strcpy(dados[2].modelo, "Saveiro");

    dados[3].ano = 2032;
    dados[3].chassi = 31235515;
    dados[3].disponivel = true;
    dados[3].preco = 300.0;
    strcpy(dados[3].marca, "fasfasd");
    strcpy(dados[3].modelo, "yasuo");

    save_data(dados, 4);

    size_t qtd;
    Data_T *read = read_data(&qtd);

    for (size_t i = 0; i < qtd; i++)
    {
        printf("%s\n", read[i].marca);
        printf("%s\n", read[i].modelo);
        printf("%d\n", read[i].ano);
        printf("%lu\n", read[i].chassi);
        printf("%d\n", read[i].disponivel);
        printf("%.2f\n", read[i].preco);
        puts("\n\n");
    }

    //Sort pelo modelo
    sortData(read, qtd);


    puts("Sorted data");
    for (size_t i = 0; i < qtd; i++)
    {
        printf("%s\n", read[i].marca);
        printf("%s\n", read[i].modelo);
        printf("%d\n", read[i].ano);
        printf("%lu\n", read[i].chassi);
        printf("%d\n", read[i].disponivel);
        printf("%.2f\n", read[i].preco);
        puts("\n\n");
    }

    free(read);
    return 0;
}