#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_vetor(int *vetor, int size);
void print_char_vetor(char *vetor, int size);
void fulfill_vetor(int *vetor, int size);
int main(){
    srand(time(NULL));
    int vetor[10] = {0,1,2,3,4,5,6,7,8,9}, fullfiled_vetor[10];
    char letters_vetor[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    // um vetor é consecutivo/ contiguo 
/*     printf("%p ", vetor);
    printf("%p ", &vetor[0]); */
    printf("\n\n");
    fulfill_vetor(fullfiled_vetor, 10);
    printf("\n\n");
    print_vetor(vetor, 10);
    printf("\n\n");
    print_vetor(fullfiled_vetor, 10);
    printf("\n\n");
    print_char_vetor(letters_vetor, 10);
    
    printf("\n\n");
    return 0;
}
void print_vetor(int *vetor, int size){
    for(int i = 0; i < size; i++){
        //printf("%d ", vet[i]);
        // pula o endereço de memoria vetor + i
        printf("%p ", vetor + i);
        printf("%d ", *(vetor + i));
        printf("\n");
    }
}

void print_char_vetor(char *vetor, int size){
    for(int counter = 0; counter < size; counter++){
        printf("char: %c\n", *(vetor+counter));
    }
};
void fulfill_vetor(int *vetor, int size){
    for(int counter = 0; counter < size; counter++){
        int random_number = rand() % 101;        
        *(vetor+counter) = random_number;
    }
}