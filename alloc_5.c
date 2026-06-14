#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int size_a, size_b;
    scanf("%i", &size_a);

    int *array;
    
    array = (int*)malloc(size_a * sizeof(int));
    for(int i = 0; i < size_a; i++) *(array + i) = 1;
    for(int i = 0; i < size_a; i++) printf("%d ", *(array + i));
    printf("\n");

    scanf("%i", &size_b);
    array = (int*)realloc(array, size_b * sizeof(int));
    for(int i = 0; i < size_b; i++) printf("%d ", *(array + i));
    printf("\n");

    for(int i = size_b - size_a; i < size_b; i++) *(array + i) = 2;
    for(int i = 0; i < size_b; i++) printf("%d ", *(array + i));

    return 0;
}