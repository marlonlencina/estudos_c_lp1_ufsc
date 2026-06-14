#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fulfill_vetor(int *vetor, int size);
void print_vetor(int *vetor, int size);
int generate_random_number(int max_number);

int main(){

    srand(time(NULL));

    int size;
    printf("Digite um tamanho para o teu vetor: \n");
    scanf("%i", &size);
    // int vet[size]; alocacao estática de memória
    int *vet;
    vet = (int*)malloc(size * sizeof(int));
    if(vet == NULL) {printf("Error on memory allocation. \nExiting... \n"); exit(0);}

    fulfill_vetor(vet, size);
    print_vetor(vet, size);
    free(vet);

    return 0;
}
void fulfill_vetor(int *vetor, int size){
    for(int counter = 0; counter < size; counter++){
        *(vetor + counter) = generate_random_number(100);
    }
}
void print_vetor(int *vetor, int size){
    for(int counter = 0; counter < size; counter++){
        printf("%i ", *(vetor + counter));
    }
}

int generate_random_number(int max_number){
    return rand() % (max_number + 1);
};

