#include "carros.h"
#include <stdio.h>
#include <windows.h>



Data_T *cadastro(Data_T *dados, size_t *qtd) {

    dados = realloc(dados, sizeof(Data_T)* ((*qtd) + 1));
    if(dados == NULL){
        exit(-1);
    }
 
    printf("Digite o nome da marca do carro: ");
    scanf("%s", dados[*qtd].marca);

    printf("\nDigite o nome do modelo do carro: ");
    scanf("%s", dados[*qtd].modelo);

    printf("\nDigite o ano do carro: ");
    scanf("%d", &dados[*qtd].ano);

    printf("\nDigite o preço do carro: ");
    scanf("%f", &dados[*qtd].preco);

    printf("\nDigite o chassi do carro: ");
    scanf("%ld", &dados[*qtd].chassi);

    dados[*qtd].disponivel = true;

    (*qtd) += 1;

    printf("Cadastro realizado!");
    Sleep(2000);

    return dados;
}
