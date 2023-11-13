//
// Created by akdag on 11/11/2023.
//

#ifndef WHATSAPPMOTORSMANAGER_DBTOOLS_H
#define WHATSAPPMOTORSMANAGER_DBTOOLS_H

#include "database.h"


void swapData(Data_T *a, Data_T *b);

/**
 * @brief Ordenar um conjunto de dados com base no modelo.
 * 
 * Esta função utiliza o algoritmo Bubble Sort para ordenar um conjunto de dados com base no modelo.
 * 
 * @param dataset Ponteiro para o array de Data_T.
 * @param size Tamanho do conjunto de dados.
 */
void sortData(Data_T * dataset, size_t size);



/**
 * @brief Encontrar dados em um conjunto de dados com base no número do chassi.
 * 
 * Esta função procura dados em um conjunto de dados com base no número do chassi especificado.
 * 
 * @param dataset Ponteiro para o array de Data_T.
 * @param size Tamanho do conjunto de dados.
 * @param chassi Número do chassi a ser pesquisado.
 * 
 * @return Ponteiro para os dados encontrados, ou NULL se não encontrados.
 */
Data_T * findData(Data_T * dataset, size_t size, long int chassi);

/**
 * @brief Desabilita um carro com o número de chassi fornecido.
 *
 * Esta função define o sinalizador 'disponivel' como falso para o carro com o número de chassi especificado.
 *
 * @param dataset Ponteiro para o array de dados de carros.
 * @param size Tamanho do array dataset.
 * @param chassi Número de chassi do carro a ser desabilitado.
 */
void disableCar(Data_T *dataset, size_t size, long int chassi);

/**
 * @brief Exclui um carro com o número de chassi fornecido do conjunto de dados.
 *
 * Esta função remove o carro com o número de chassi especificado do array dataset.
 *
 * @param dataset Ponteiro para o array de dados de carros.
 * @param size Ponteiro para o tamanho do array dataset. O tamanho será atualizado após a exclusão.
 * @param chassi Número de chassi do carro a ser excluído.
 */
void excludeCar(Data_T *dataset, size_t *size, long int chassi);

#endif //WHATSAPPMOTORSMANAGER_DBTOOLS_H
