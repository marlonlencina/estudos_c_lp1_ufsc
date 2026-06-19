#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){

    FILE *file;
    file = fopen("output/numbers.txt", "r");

    if(!file) {
        printf("Erro ao abrir arquivo. \n");
        exit(0);
    }

    while(!feof(file)){
        int number;
        fscanf(file, "%i\n", &number);
        printf("%i\n", number);
    }

    fclose(file);
    return 0;
}