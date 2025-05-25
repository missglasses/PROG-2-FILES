#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
#define INT_MIN -2147483648
#define INT_MAX 214748364

void display(int arr[]);
int *sorting_souls(int arr[]);

int main() {
    int list[MAX_SIZE];
    int *sort;

    printf("Enter number of souls: ");
    scanf("%d", &list[0]);

    printf("Enter soul scores: ");
    for(int i = 1; i <= list[0]; ++i) {
        scanf("%d", &list[i]);
    }

    printf("Initial soul list: ");
    // Hey there, start typing your C code here...
    display(list);
    
    printf("Sorted soul list: ");
    // Hey there, start typing your C code here...
    
    //returning something so we need a catcher variable
    sort = sorting_souls(list);
    display(sort);// or  
    
    // free(sort);
    return 0;
}

void display(int arr[]) {
    printf("[");
    for(int i = 1; i <= arr[0]; ++i) {
        printf("%d", arr[i]);
        if(i < arr[0]) { 
            printf("|");
        }
    }
    printf("], SOUL COUNT: %d\n", arr[0]);
}

int *sorting_souls(int arr[]) {

    int highest = INT_MIN;
    int second = INT_MIN;
    int secondIndex=0;
    
    for (int i=1; i<=arr[0]; i++){
        if (arr[i]>highest){
            highest=arr[i];
        }
    }
    for (int i=1; i<=arr[0]; i++){
        if (arr[i]>second && arr[i]!=highest){
           second=arr[i];
           secondIndex = i;
        }
    }
    
    int newCount = secondIndex==0 ? 0 : arr[0] - secondIndex + 1;
    int *sort = malloc(sizeof(int)*newCount);
    
    int j=1;
    
    for (int i=secondIndex; i<=arr[0]; i++){
        sort[j]=arr[i];
        j++;
    }
    
    sort[0]=newCount;
    return sort;
    
    
  //  return arr;
}
