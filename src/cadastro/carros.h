#ifndef CARROS_H
#define CARROS_H
#include "../database/database.h"
#include "../database/dbtools.h"

bool getChassi(long int *chassi);
Data_T *cadastro(Data_T *dados, size_t *qtd);


#endif