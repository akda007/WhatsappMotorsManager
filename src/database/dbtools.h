//
// Created by akdag on 11/11/2023.
//

#ifndef WHATSAPPMOTORSMANAGER_DBTOOLS_H
#define WHATSAPPMOTORSMANAGER_DBTOOLS_H

#include "database.h"

void swapData(Data_T *a, Data_T *b);
void sortData(Data_T * dataset, size_t size);
Data_T * findData(Data_T * dataset, size_t size, long int chassi);

#endif //WHATSAPPMOTORSMANAGER_DBTOOLS_H
