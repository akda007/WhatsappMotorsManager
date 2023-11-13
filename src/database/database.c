#include "database.h"


void save_data(Data_T *data, size_t nsize) {
    FILE *file = fopen("data", "wb");

    fwrite(&nsize, sizeof(size_t), 1, file);

    if (nsize > 0) {
        fwrite(data, sizeof(Data_T), nsize, file);
    }

    fclose(file);
}

Data_T *read_data(size_t *size) {
    FILE *file = fopen("data", "rb");

    if (file == NULL) {
        *size = 0;

        return NULL;
    }

    fread(size, sizeof(size_t), 1, file);

    if (size == 0) {
        return NULL;
    }
    
    Data_T *data = (Data_T*)malloc(sizeof(Data_T) * (*size));
    
    fread(data, sizeof(Data_T), (*size), file);

    fclose(file);

    return data;
}

