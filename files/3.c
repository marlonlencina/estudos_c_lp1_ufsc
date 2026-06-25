#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];
typedef struct user_data {
  string name;
  string cpf;
  int age;
  float average_salary;
  struct user_data *next;
} t_user;

void removerEnterFromString(string str) { str[strlen(str) - 1] = '\0'; }
void listAllUsers(t_user **list) {
  t_user *copy_list = *list;
  while (copy_list != NULL) {
    printf("Nome: %s\nCPF: %s\nIdade: %i\nSalário: %2.f\n", copy_list->name,
           copy_list->cpf, copy_list->age, copy_list->average_salary);
    copy_list = copy_list->next;
  }
}
t_user *createNewUser() {
  t_user *new_user;
  new_user = (t_user *)calloc(1, sizeof(t_user));
  new_user->next = NULL;

  printf("Digite o nome: \n");
  fgets(new_user->name, 100, stdin);
  removerEnterFromString(new_user->name);
  printf("Digite o CPF: \n");
  fgets(new_user->cpf, 100, stdin);
  removerEnterFromString(new_user->cpf);
  printf("Digite a idade: \n");
  scanf("%i", &new_user->age);
  printf("Digite o salário médio: \n");
  scanf("%f", &new_user->average_salary);

  printf("Novo usuário criado com sucesso. \n");
  return new_user;
}
void insertNewUserInListAtBeggining(t_user **list, t_user *new_user) {
  if (*list == NULL) {
    *list = new_user;
  } else {
    new_user->next = *list;
    *list = new_user;
  }
  printf("Usuário inserido na lista. \n");
}

void dataPersistenceOnBinaryFile(t_user **list) {
  FILE *file;
  file = fopen("user_data.txt", "wb");

  if(*list == NULL){
    printf("Lista vazia. \n");
    return;
  }

  t_user *copy_list = *list;
  while (copy_list != NULL) {
    t_user current_record = *copy_list;
    current_record.next = NULL;
    fwrite(&current_record, sizeof(t_user), 1, file);
    copy_list = copy_list->next;
  }

  printf("Todos dados foram persistidos. \n");
}

void loadDataFromBinaryFile(t_user **list) {
  FILE *file;
  file = fopen("user_data.txt", "rb");

  if (!file) {
    printf("Something went wrong on data loading from file or First "
           "inicialization. \n");
    return;
  }

  t_user user_temp;

  while (fread(&user_temp, sizeof(t_user), 1, file) == 1) {
    t_user *current_user_record;
    current_user_record = (t_user *)malloc(sizeof(t_user));
    *current_user_record = user_temp;
    current_user_record->next = NULL;
    printf("Nome: %s\n", current_user_record->name);
    printf("CPF: %s\n", current_user_record->cpf);

    insertNewUserInListAtBeggining(list, current_user_record);
  }
  fclose(file);
  printf("Todos os dados foram recuperados de um arquivo. \n");
}

int main() {
  int option;
  t_user *list = NULL;
  loadDataFromBinaryFile(&list);

  for (;;) {
    printf(
        "1) incluir pessoa\n2) listar pessoas cadastradas\n3) gravar dados de "
        "pessoas em arquivo binário\n4) ler dados de arquivo binário\n0) sair "
        "do programa\n");

    scanf("%i", &option);
    getchar();

    switch (option) {
    case 1: {
      t_user *new_user = createNewUser();
      insertNewUserInListAtBeggining(&list, new_user);
      break;
    }
    case 2:
      listAllUsers(&list);
      break;
    case 3:
      break;
    case 4:
      break;
    case 0:
      dataPersistenceOnBinaryFile(&list);
      exit(0);
      break;
    default:
      printf("Opção digitada é inválida. \n");
      break;
    }
  }

  return 0;
}
