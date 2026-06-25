/*
Escreva um programa para manipular um vetor de 10 elementos do tipo caractere. O
programa deverá ter as seguintes sub-rotinas (funções): • Para ler o vetor; •
Para contar quantas vezes um determinado caractere está no vetor. Neste caso o
usuário informará qual é o caractere a ser contado e o programa deverá retornar
a quantidade de vezes que o caractere aparece no vetor. Você deve utilizar
aritmética de ponteiros para percorrer o vetor, tanto na leitura dos dados como
na localização/contagem de um caractere específico.
*/

#include <stdio.h>
#define SIZE_VETOR 10
void fulfillVetor(char *vetor, int v_size);
int countCharactere(char *vetor, int v_size, char target);

int main() {

  char vetor[SIZE_VETOR];
  fulfillVetor(vetor, SIZE_VETOR);
  char target;
  printf("Digite o target: \n");

  scanf("%c", &target);
  getchar();

  int quantity = countCharactere(vetor, SIZE_VETOR, target);
  printf("Aparece: %i vez(es). \n", quantity);
}

void fulfillVetor(char *vetor, int v_size) {
  for (int i = 0; i < v_size; i++) {
    scanf("%c", (vetor + i));
    getchar();
  }
}

int countCharactere(char *vetor, int v_size, char target) {
  int counter = 0;
  for (int i = 0; i < v_size; i++) {
    printf("%c == %c\n", *(vetor+i), target);

    if (*(vetor + i) == target) {
      counter++;
    }
  }
  return counter;
}