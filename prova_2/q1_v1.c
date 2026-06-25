/*Escreva um programa para ler uma matriz de inteiros de tamanho N x M. Em
seguida, salve em um arquivo do tipo texto todos os números ímpares contidos na
matriz. A matriz poderá ser alocada de forma estática ou dinâmica, fica a seu
critério a escolha pela forma de alocação. N e M representam, respectivamente o
número de linhas e o número de colunas e são definidos por você.*/

#define rows 4
#define cols 4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  FILE *file;
  file = fopen("odds.txt", "w");
  int matriz[rows][cols];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matriz[i][j] = rand() % 101;
    }
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int is_even = matriz[i][j] % 2 == 0;
      if (!is_even) {
        fprintf(file, "%i\n", matriz[i][j]);
      }
    }
  }

  fclose(file);

  return 0;
}