#include "database.h"

/* FILE Structure
size_t num_of_elements;
Data_T elements[num_of_elements];
*/

/* save_data -> Recebe um array de dados do tipo Data_T
                e salva em um arquivo binario
    
   args:
    [data] -> array de dados
    [nsize] -> quantidade de elementos a serem salvos
    
*/
void save_data(Data_T *data, size_t nsize) {
    FILE *file = fopen("data", "wb");

    fwrite(&nsize, sizeof(size_t), 1, file);
    fwrite(data, sizeof(Data_T), nsize, file);

    fclose(file);
}

/* read_data() -> Le os dados do arquivo binario,
                  aloca memoria para um array de dados
                  e retorna a quantidade de elementos lidos.
   
   args:
    [data] -> Ponteiro(array) do tipo Data_T
              no qual a memoria sera alocada
              e os dadods serao salvos
*/
Data_T *read_data(size_t *size) {
    FILE *file = fopen("data", "rb");

    fread(size, sizeof(size_t), 1, file);
    Data_T* data = (Data_T*)malloc(sizeof(Data_T) * (*size));
    
    fread(data, sizeof(Data_T), (*size), file);

    fclose(file);

    return data;
}

