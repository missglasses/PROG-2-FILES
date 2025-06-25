#include <stdio.h>
#include <stdlib.h>
int* myMalloc(int size) {
    int *newArr = malloc(sizeof(int)*size);
    if(newArr == NULL) {
        printf("Failed to allocate\n");
        exit(1);
    }
    return newArr;
}

int* myRealloc(int *arr, int size, int newSize){
     int *newArr = realloc(arr, sizeof(int)*newSize);
     
     if(newArr==NULL){
         printf("Failed to allocate");
         exit(1);
     }
    
    
    return newArr;
}

int main() {
    int size=5;
    int *myArray=myMalloc(size);
    
    printf("Old array: ");
    for (int i = 0; i < size; i++) {
       myArray[i]= i*10;
    }
 
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    
    int newSize = 15;
    myArray=myRealloc(myArray, size,newSize); //expanded : 15 elements 
    
    
    printf("\nNew array: ");
    
    for (int i = 0; i < size; i++) {
       myArray[i]= i*20;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    
    
    free(myArray);
    
    return 0;
}
