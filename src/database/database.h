#ifndef DATABASE_H
#define DATABASE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    char marca[100];
    char modelo[100];
    long int chassi;
    int ano;
    float preco;
    bool disponivel;
} Data_T;

void save_data(Data_T *data, size_t nsize);
Data_T * read_data(size_t *data);

#endif