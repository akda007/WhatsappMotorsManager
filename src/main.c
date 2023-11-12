#include <stdio.h>
#include <string.h>
#include "database/dbtools.h" 
#include "cadastro/carros.h"


int main() {

    size_t qtd;
    Data_T *dados = read_data(&qtd);
    dados = cadastro(dados, &qtd);

    save_data(dados, qtd);

    for (size_t i = 0; i < qtd; i++){

        printf("%s\n", dados[i].modelo);
        
    }
    
    
    return 0;
}