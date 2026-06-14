// vetor -> um ponteiro
// matriz é um vetor de vetores
// matriz é um vetor de ponteiros 
// matriz e um ponteiro de ponteiros

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));

    int rows = 4;
    int cols = 4; 
    int **matriz;

    matriz = (int**)malloc(rows * sizeof(int**));

    for(int i = 0; i < rows; i++) {
        int *vetor;
        vetor = (int*)malloc(cols * sizeof(int));
        *(matriz+i) = vetor;
    }

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            *(*(matriz+i)+j) = rand() % 101;
            printf("%d ", *(*(matriz+i)+j));
        }
        printf("\n");
    }

    return 0;
}