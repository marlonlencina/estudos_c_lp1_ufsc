#include <stdio.h>
#include <stdlib.h>

int main(){
    //char letter; // aloca de forma estática um espaço na memória para letter
    char *letter; //aloca um espaço para um endereço de memoria

    printf("endereço do ponteiro (letter): %p. \n", letter);

    letter = (char*)malloc(sizeof(char));
    if(!letter) exit(0); 
    //if(!letter) exit(0);
    *letter = 'm'; 
    
    printf("*letter: %c. \n", *letter);
    printf("endereço do ponteiro (letter): %p. \n", letter);
    

    return 0;
}