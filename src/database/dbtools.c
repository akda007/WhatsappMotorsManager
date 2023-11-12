//
// Created by akdag on 11/11/2023.
//

#include "dbtools.h"

void swapData(Data_T *a, Data_T *b) {
    Data_T tmp = *b;

    *b = *a;
    *a = tmp;
}

void sortData(Data_T * dataset, size_t size) {
    bool sorted = false;
    
    while (!sorted) {
        sorted = true;

        for (size_t i = 0; i < size-1; i++) {
            if (strcmp(dataset[i].modelo, dataset[i+1].modelo) > 0) {
                swapData(&dataset[i], &dataset[i+1]);
                sorted = false;
            }
        }
    }
}

Data_T * findData(Data_T * dataset, size_t size, long int chassi) {
    Data_T *data = NULL;

    for (size_t i = 0; i < size; i++) {
        if (dataset[i].chassi == chassi)
            data = &dataset[i];
    }

    return data;
}

void disableCar (Data_T * dataset, size_t size, long int chassi)
{
    for (size_t i = 0; i < size; i++) {
        if (dataset[i].chassi == chassi)
            dataset[i].disponivel = false;
    }
}

void excludeCar (Data_T * dataset, size_t * size, long int chassi)
{
    for (size_t i = 0; i < *size; i++) {
        if (dataset[i].chassi == chassi)
        {
            for (size_t j = i; j < (*size) - 1; j++)
                dataset[j] = dataset[j + 1];

            (*size)--;
            break;
        }
    }
}
