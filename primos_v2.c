// Consigo identificar um primo
// Achei os N primeiros primos

// Usei uma lista encadeada para salvar os primos, usando insercao pelo inicio

// Usei os args de main para pegar a quntd de primos
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define initial_n_prime 2

typedef struct node node_t;
struct node {
    int value;
    node_t *next;
};

int isPrime(int num);
void insert_at_beginning(node_t **list, int num);
void insert_at_ending(node_t **list, int num);
void insert_at_middle(node_t **list, int num, int prev);
void print(node_t *list);

int main(int argc, char *argv[]){

    printf("%i. \n", argc);
    printf("%s. \n", argv[0]);
    printf("%s. \n", argv[1]);

    if(argc < 1){
        printf("tá faltando args. \n");
        exit(0);
    }

    node_t *list = NULL;

    int primes_requested = atoi(argv[1]), total_primes_found = 0;
    //printf("Digite a quantidade de números de primos: \n");
    //scanf("%i", &primes_requested);

    for(int i = 0; total_primes_found < primes_requested; i++){
        if(isPrime(i)){
            //insert_at_beginning(&list, i);
            insert_at_ending(&list, i);
            total_primes_found++;
        }
    }

    print(list);

    printf("Total de primos Requisitado: %i. \n", primes_requested);
    printf("Total de primos Encontrados: %i. \n", total_primes_found);

    return 0;
}

void print(node_t *list){
    while(list != NULL){
        printf("valor de Num: %i. \n", list->value);
        list = list->next;
    }
}


// insert after a element
void insert_at_middle(node_t **list, int num, int prev){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = num;

    // is the first?
    if(*list == NULL){
        *list = new_node;
    } else {
        node_t *aux = *list;
        while(aux->next != prev && aux->next) aux = aux->next;
        new_node->next = aux->next;
        aux->next = new_node;
    }
}

void insert_at_ending(node_t **list, int num){
    // insere no final
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = num;
    new_node->next = NULL;

    if(*list == NULL){
        *list = new_node;
    } else {
        node_t *last_item = *list;;
        while(last_item->next != NULL){
            last_item = last_item->next;
        }
        last_item->next = new_node;
    }   
}

void insert_at_beginning(node_t **list, int num){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = num;
    if(list == NULL){
        new_node->next = NULL;
    } else {
        new_node->next = *list;
    }
    *list = new_node;
}

int isPrime(int num){
    if(num <= 1) return 0;

    for(int i = 2; i <= (int)sqrt(num); i++){
        if(num % i == 0){
            return 0;
            break;
        }
    }
    return 1;
}