#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){

    srand(time(NULL));

    printf("argc: %i. \n", argc);
    printf("argv[0]: %s. \n", argv[0]);
    printf("argv[1]: %s. \n", argv[1]);
    
    if(argc < 2){
        printf("Falta argumentos. \n");
        return 0;
    }

    int numbers_requested = atoi(argv[1]); // pega a segunda pos
    // Escrever e depois ler numeros aleatorios em um arquivo TXT
    FILE *file;
    file = fopen("output/numbers.txt", "w");

    if(!file) {
        printf("Erro ao abrir arquivo. \n");
        exit(0);
    }

    for(int counter = 0; counter < numbers_requested; counter++){
        int number_generated = rand() % 101;
        fprintf(file, "%i\n", number_generated);
    }

    fclose(file);

    return 0;
}