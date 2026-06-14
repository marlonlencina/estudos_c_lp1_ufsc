#include <stdlib.h>
#include <stdio.h>

typedef struct node node_t;
struct node {
    int value;
    node_t *next;
};

typedef struct list {
    node_t *start;
    int size;
} list_t;

void insert_at_beginning(list_t *list, int value);
void insert_at_ending(list_t *list, int value);

void print_list(list_t *list);

int main(){
    list_t list;
    int opt, value;
    list.start = NULL;
    list.size = 0;

    do{
        printf("1. Inserir no início\n2. Imprimir\n3. Inserir no fim\n0. Sair\n");
        printf("Digite uma opção: \n");
        scanf("%i", &opt);
        switch(opt){
            case 1: 
                printf("Digite um valor: \n");
                scanf("%i", &value);
                insert_at_beginning(&list, value);
                break;
            case 2: 
                print_list(&list);
                break;
            case 3:
                printf("Digite um valor: \n");
                scanf("%i", &value);
                insert_at_ending(&list, value);
            default: 
                opt != 0 && printf("not this time =/ try again...\n");
                break;
        }
    }while(opt != 0);


    return 0;
}

void insert_at_beginning(list_t *list, int value){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value; // (*new_node).value = value;
    new_node->next = list->start; 
    list->start = new_node;
    list->size++;
}

void print_list(list_t *list){
    printf("Tamanho da lista: %i. \n", list->size);
    node_t *start = list->start;
    while(start != NULL){
        printf("%d ", start->value);
        start = start->next;
    }
    printf("\n\n");
};

void insert_at_ending(list_t *list, int value){
    node_t *node, *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    if(list->start == NULL){
        list->start = new_node;
    } else {
        node = list->start;
        while (node->next != NULL){
            node = node->next;
        }
        node->next = new_node;
    }
    list->size++;
}