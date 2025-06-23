#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

bool insertRear(int a[], int *count, int item); //behaves like a queue (FIFO)


int main() {
    int myArray[MAX_SIZE];
    int n=0;
    
    insertRear(myArray,&n,30);
    insertRear(myArray,&n,40);
    
    int i;
    for(i=0; i<n; ++i){
        printf("%d ", myArray[i]);
        
    }
   
    return 0;
}




bool insertRear(int a[], int *count, int item){
    int i;
    if (*count<MAX_SIZE){
        a[(*count)++]=item;
        return true;
    }
    return false;
}

