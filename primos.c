#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Consigo identificar um primo
// Achei os N primeiros primos
// Usei uma lista encadeada para salvar os primos, usando insercao pelo inicio
// Usei os args de main para pegar a quntd de primos 

typedef struct node node_t;
struct node {
    int value;
    node_t *next; 
};

int is_prime(int number);
void insert_at_beginning(node_t **list, int value);
void print(node_t *list);
int main(int argc, char *argv[]){

    printf("argument count: %i. \n", argc);
    printf("argument [0]: %s. \n", argv[0]);
    printf("argument [1]: %s. \n", argv[1]);

    if(argc < 2){
        printf("Forneça todos parâmetros necessários para rodar a função. \n");
        exit(0);
    }

    int requested_primes = atoi(argv[1]);
    int total_primes_found = 0;

    node_t *list = NULL;
    
    for(int i = 2; total_primes_found < requested_primes; i++){
        int current_number = i;
        if(is_prime(current_number)){
            insert_at_beginning(&list, current_number);
            total_primes_found++;
        }
    }
    print(list);

    return 0;
}

void print(node_t *list){
    while(list != NULL){
        printf("Valor do Node: %i. \n", list->value);
        printf("Endereço do Next Node: %p. \n", list->next);
        list = list->next;
    }
}

void insert_at_beginning(node_t **list, int value){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = *list;
    *list = new_node;
}

int is_prime(int number){
    if(number <= 1) return 0;
    int is_prime = 1;
        for(int i = 2; i * i <= number; i++){
            if(number % i == 0){
                is_prime = 0;
                break;
            }
        }
    return is_prime;
}