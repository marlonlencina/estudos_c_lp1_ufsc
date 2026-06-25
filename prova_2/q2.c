/*Escreva um programa para cadastrar pessoas em uma lista encadeada. A estrutura
de dados que modela a pessoa é a seguinte: struct dados_pessoa { string nome;
int idade;
float altura;
};
O programa deverá ter as seguintes funções:
• Criação e Inserção de uma nova pessoa na lista encadeada (pelo início ou pelo
fim); • Localizar pessoa por nome; • Salvar dados de pessoas em um arquivo
binário chamado pessoas.bin. Não há necessidade de interação com o usuário. Não
esqueça de definir o tipo string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STRING 100
typedef char string[MAX_SIZE_STRING];
struct dados_pessoa {
  string nome;
  int idade;
  float altura;
  struct dados_pessoa *next;
} typedef t_dados_pessoa;
t_dados_pessoa *createNewPerson(string name, float altura, int idade);

void insertNewPersonInListAtBeggining(t_dados_pessoa **list,
                                      t_dados_pessoa *new_person);
t_dados_pessoa *findPersonByName(t_dados_pessoa *list, string name);
void exportDataFile(t_dados_pessoa *list);
int main() {
  t_dados_pessoa *list;
  t_dados_pessoa *new_person = createNewPerson("Lulisco", 1.13, 130);
  insertNewPersonInListAtBeggining(&list, new_person);
  t_dados_pessoa *new_person_2 = createNewPerson("Bozo", 1.22, 220);
  insertNewPersonInListAtBeggining(&list, new_person_2);

  t_dados_pessoa *person_found = findPersonByName(list, "Lulisco");
  person_found == NULL
      ? printf("Nenhuma pessoa encontrada.\n")
      : printf("Encontrei! Nome: %s, altura: %2.f, idade: %i.\n",
               person_found->nome, person_found->altura, person_found->idade);

  t_dados_pessoa *person_found_2 = findPersonByName(list, "Ciro");
  person_found_2 == NULL
      ? printf("Nenhuma pessoa encontrada.\n")
      : printf("Encontrei! Nome: %s, altura: %2.f, idade: %i.\n",
               person_found_2->nome, person_found_2->altura,
               person_found_2->idade);

  exportDataFile(list);
  return 0;
}

t_dados_pessoa *createNewPerson(string name, float altura, int idade) {
  t_dados_pessoa *new_person;
  new_person = (t_dados_pessoa *)malloc(sizeof(t_dados_pessoa));

  strcpy(new_person->nome, name);
  new_person->altura = altura;
  new_person->idade = idade;
  new_person->next = NULL;

  return new_person;
}

void insertNewPersonInListAtBeggining(t_dados_pessoa **list,
                                      t_dados_pessoa *new_person) {
  new_person->next = *list;
  *list = new_person;
}

t_dados_pessoa *findPersonByName(t_dados_pessoa *list, string name) {
  t_dados_pessoa *copy_list = list;
  while (copy_list != NULL) {
    if (strcmp(copy_list->nome, name) == 0) {
      return copy_list;
    }
    copy_list = copy_list->next;
  }
  return copy_list = NULL;
}

void exportDataFile(t_dados_pessoa *list) {
  FILE *file;
  file = fopen("persons.bin", "wb");
  t_dados_pessoa *no_correlated_list = list;
  while (no_correlated_list != NULL) {
    t_dados_pessoa copy_record = *no_correlated_list;
    copy_record.next = NULL;
    fwrite(&copy_record, sizeof(t_dados_pessoa), 1, file);
    no_correlated_list = no_correlated_list->next;
  }
  fclose(file);
}