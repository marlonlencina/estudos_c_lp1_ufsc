#include <stdio.h>
#include <stdlib.h>

int main(){
    int size_of_allocation = 10;
    int *p, *p2;
    // quantidade de bytes do tipo * quantidade de elementos
    // sizeof() retorna a quantidade de bytes de um tipo
    // (int*) avisa o compilador que o endereço de memória retornado é para inteiro
    // se nao for possivel alocar, retorna NULL

    printf("posicao inicial alocado *p: %p. \n", p);
    printf("posicao inicial alocado *p2: %p. \n", p2);

    // aloca memória para 1 inteiro!
    p = (int*)malloc(sizeof(int));

    // aloca memória para 10 inteiros!
    p2 = (int*)malloc(sizeof(int) * size_of_allocation);

    printf("posicao inicial alocado *p: %p. \n", p);
    printf("posicao inicial alocado *p2: %p. \n", p2);

    /*     p == NULL || p2 == NULL ? (
        printf("Não foi possível alocar memória. \n"), exit(0)
    ) : printf("memória alocada. \n"); */

    if(p == NULL || p2 == NULL){
        printf("Não foi possível alocar memória. \n");
        exit(0);
    } else {
        printf("memória alocada. \n");
    }
    printf("posicao inicial alocado *p: %p. \n", p);
    printf("posicao inicial alocado *p2: %p. \n", p2);

    free(p), free(p2);
    return 0;
}