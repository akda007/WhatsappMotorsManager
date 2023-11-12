#ifndef DATABASE_H
#define DATABASE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @struct Data_T
 * @brief Estrutura que representa informações de um veículo.
 */
typedef struct {
    char marca[100]; /**< Marca do veículo. */
    char modelo[100]; /**< Modelo do veículo. */
    long int chassi; /**< Número de chassi do veículo. */
    int ano; /**< Ano de fabricação do veículo. */
    float preco; /**< Preço do veículo. */
    bool disponivel; /**< Indica se o veículo está disponível. */
} Data_T;

/**
 * @brief Salvar dados em um arquivo binário.
 * 
 * Esta função salva os dados em um arquivo binário chamado "data".
 * 
 * @param data Ponteiro para o array de Data_T.
 * @param nsize Tamanho do array de dados.
 */
void save_data(Data_T *data, size_t nsize);

/**
 * @brief Ler dados de um arquivo binário.
 * 
 * Esta função lê os dados de um arquivo binário chamado "data" e retorna um ponteiro para os dados lidos.
 * 
 * @param size Ponteiro para a variável que armazenará o tamanho dos dados lidos.
 * @return Ponteiro para os dados lidos, ou NULL em caso de falha.
 */
Data_T *read_data(size_t *size);
#endif