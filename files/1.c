/*

Escreva um programa em C para escrever números inteiros em um arquivo do tipo
texto. O usuário deverá informar o nome do arquivo de saída e a quantidade de
números a serem gerados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char string[100];

int main(int argc, char *argv[]) {
  srand(time(NULL));
  if (argc < 3) {
    printf("Está faltando args na chamada do file. \n");
    return 0;
  }

  int quantity_numbers_requested = 0;
  quantity_numbers_requested = atoi(argv[1]);
  string filename;
  strcpy(filename, argv[2]);

  FILE *file;
  file = fopen(filename, "w");
  if (!file) {
    printf("Erro no processamento do arquivo. \n");
    return 0;
  }

  for (int counter = 0; counter < quantity_numbers_requested; counter++) {
    int number_generated = rand() % 101;
    fprintf(file, "%i\n", number_generated);
  }

  fclose(file);

  return 0;
}