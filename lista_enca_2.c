#include <stdio.h>

// PILHA: RESTRICAO INSERE NO TOPO E REMOVE DO TOPO
// FILA: RESTRICAO INSERE NO FINAL E REMOVE NO INICIO
// LISTA ENCADEADA: MAIS GENÉRICA SEM RESTRIÇOES, PODE INSERIR E REMOVER NO INICIO, MEIO, FIM 
typedef struct node {
    int value;
    struct node *next;
} node_t;

// inserir no inicio
void insert_at_beginning(node_t **list, int num);
void insert_at_ending(node_t **list, int num);

int main(){

    return 0;
}

void insert_at_beginning(node_t **list, int num){
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node){
        new_node->value = num;
        new_node->next = *list;
        *list = new_node;
        //(*new_node).value = num;
    } else {
        printf("Error on memory allocation. \n");
    }
};

void insert_at_ending(node_t **list, int num){
   node_t *aux, *new_node;
   new_node = malloc(sizeof(node_t));
   if(new_node){
        new_node->value=num;
        new_node->next=NULL;
        // é o primeiro?
        if(*list == NULL){
            *list = new_node;
        }else{
            aux = *list;
            while(aux->next!=NULL){
                aux=aux->next; // passo de incremento, vai pulando de nó em nó
            }
            aux->next=new_node; 
        }
   }else{
        printf("Error on memory allocation. \n");
   } 
};
