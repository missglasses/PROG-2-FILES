#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

bool insertFront(int a[], int *count, int item);

int main() {
    int myArray[MAX_SIZE];
    int n=0;

    insertFront(myArray,&n,10);
    insertFront(myArray,&n,20);
    insertFront(myArray,&n,30);
    insertFront(myArray,&n,40);
    insertFront(myArray,&n,50);
    int i;
    for(i=0; i<n; ++i){
        printf("%d ", myArray[i]); //50 40 30 20 10 
        
    }
   
    return 0;
}

bool insertFront(int a[], int *count, int item) {
    int i;
    
    if(*count < MAX_SIZE) {
        for(i = *count; i > 0 ; --i) {
            a[i] = a[i-1];
        }
        a[i] = item;
        (*count)++;
        return true;
    }
    
    return false;
}


