#include <stdio.h>
#include <stdlib.h>

int main() {
    int size=5;
    int myArray;

    int *myCalloc = calloc(sizeof(int), 5);
    
    if(myCalloc==NULL){
        printf("Failed to allocate");
        exit(1);
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", myCalloc[i]);
    }
    
    free(myCalloc);
    
    return 0;
}
