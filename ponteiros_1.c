#include <stdio.h>

int main(){
    int *valor1, valor2 = 50;
    char *letra1, letra2 = 'b';

    // valor1 e letra1 sao PONTEIROS do tipo INTEIRO e CHAR;
    // PONTEIROS ARMAZENAM ENDEREÇOS DE MEMÓRIA!
    // '&' Obtém o endereço de memória!!

    printf("*valor1: %p. \n", valor1);
    printf("*letra1: %p. \n", letra1);
  
    printf("valor2: %d. \n", valor2);
    printf("letra2: %c. \n", letra2);
    printf("endereço valor2: %p. \n", &valor2);
    printf("endereço letra2: %p. \n", &letra2);

    valor1 = &valor2;
    letra1 = &letra2;

    printf("\n*valor1: %p. \n", valor1);
    printf("*letra1: %p. \n", letra1);

    printf("conteudo apontado por *valor1: %d. \n", *valor1);
    printf("conteudo apontado por *letra1: %c. \n", *letra1);

    printf("\n");
    return 0;
}