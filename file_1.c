#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_STR 100
typedef char string[T_STR];
typedef struct person {
    string name;
    int age;
    char genre;
} person_t;

person_t list[10]; 
int quantity_list = 0;

string file_path = "output/list.txt";

void saveOnFile(void);
void readFile(void);
int createNewPerson(void);
int printArray(void);
int menu(void);
int main(){
    //createNewPerson();
    int option;
    for(;;){
        option = menu();
        if(!option) printf("chao! 👋 \n"), exit(0);
        switch (option)
        {
        case 1:
            int response = createNewPerson();
            response ? printf("Pessoa cadastrada com sucesso. \n") : printf("Erro ao cadastrar. \n");
            break;
        case 2:
            printArray();
            break;
        case 3:
            saveOnFile();
            break;
        case 4:
            readFile();
            break;
        default:
            printf("Opção desconhecida. \n");
            break;
        }
    }

    return 0;
}


int menu(){
    int option = 0;
    printf("Digite uma opção: \n");
    printf("1. Cadastrar pessoa. \n");
    printf("2. Listar pessoas. \n");
    printf("3. Exportar arquivo (.TXT). \n");
    printf("4. Ler do arquivo (.TXT). \n");
    printf("0. Encerrar programa. \n");
    scanf("%i", &option);\
    getchar();
    return option;
}

void readFile(void){
    FILE *file;
    file = fopen(file_path, "r");
    if(!file) {
        printf("Nao foi possivel abrir o arquivo. \n");
        return;
    };
    int recovered_quantity_list = 0;
    fscanf(file, "%i\n", &recovered_quantity_list);
    for(int counter = 0; counter < recovered_quantity_list; counter++){
        person_t current_person;
        fscanf(file, "%s\n", current_person.name);
        fscanf(file, "%i\n", &current_person.age);
        fscanf(file, "%c\n", &current_person.genre);

        printf("Nome: %s", current_person.name);
        printf(", Idade: %i", current_person.age);
        printf(", Gênero: %c\n", current_person.genre);

        list[counter] = current_person;
    }
    quantity_list = recovered_quantity_list;
    //list = recovered_list;
    printf("Leitura do arquivo realizada com sucesso. \n");
    fclose(file);
}
void saveOnFile(void){
    FILE *file;
    file = fopen(file_path, "w"); // retorna NULL se nao for possivel criar ou abrir o arquivo
    if(!file) {
        printf("erro ao abrir arquivo. \n");
        return;
    }; 

    fprintf(file, "%i\n", quantity_list); 
    for(int counter = 0; counter < quantity_list; counter++){
        person_t current_person = list[counter];
        fprintf(file, "%s\n", current_person.name); 
        fprintf(file, "%i\n", current_person.age); 
        fprintf(file, "%c\n", current_person.genre); 
        // function de escrita no arquivo
        // arquivo, mascara de formatacao, variaveis
    }

    printf("Arquivo exportado com sucesso. \n");
    fclose(file);
};
int printArray(void){
    int counter = 0; 
    while(counter < quantity_list){
        person_t current_person = list[counter];
        printf("Name: %s. \n", current_person.name);
        printf("Age: %i. \n", current_person.age);
        printf("Genre: %c. \n", current_person.genre);
        counter++;
    }
};
int createNewPerson(){
    {
    if(!(quantity_list < 10)){
        printf("Vetor cheio. \n");
        return 0;
    };

    person_t new_person;
    printf("Digite seu nome: \n");
    fgets(new_person.name, T_STR, stdin);
    new_person.name[strlen(new_person.name) - 1] = '\0';
    
    printf("Digite seu gênero: \n");
    scanf("%c", &new_person.genre);

    printf("Digite sua idade: \n");
    scanf("%i", &new_person.age);

    list[quantity_list] = new_person;
    quantity_list++;
    return 1;
}
}