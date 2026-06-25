/*
Escreva um programa em C para ler o arquivo do tipo texto gerado pelo programa
do exercício (1). O programa deverá ler os números inteiros e armazená-los em um
vetor. Não esqueça de que o vetor deverá ser alocado dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
int main() {

  FILE *file;
  file = fopen("dudu.txt", "r");

  if (!file) {
    printf("Impossível de ler o arquivo. \n");
    return 0;
  }

  int total_numbers = 0;

  while (feof(file)) {
    total_numbers++;
  }

  int *numbers_read;
  numbers_read = (int *)calloc(total_numbers, sizeof(int));
  int counter = 0;

  while (fscanf(file, "%i", &numbers_read[counter]) == 1) {
    counter++;
  }

  for (int i = 0; i < counter; i++) {
    printf("%i.\n", numbers_read[i]);
  }

  fclose(file);
  return 0;
}