#include <stdio.h>
#include <stdlib.h>

//TRANSFER ODD ELEMENTS TO A NEW ARRAY 
void transferOddIndexed(int* arr, int n, int *newArr,int *oddCount);

int main() {
    int arr[] = {10, 21, 32, 43, 54, 65, 76};
    int newArr[10];
    int n = 7;
    int oddCount;
    
    transferOddIndexed(arr, n, newArr, &oddCount);
    
     printf("Odd-indexed elements: ");
    for(int i=0; i<oddCount; i++){
        printf("%d ", newArr[i]);
    }
    printf("\n");
    
    return 0;
}

void transferOddIndexed(int* arr, int n, int *newArr,int *oddCount){
    *oddCount=0;
    
    for(int i=1; i<n; i+=2){ 
        newArr[*oddCount]=arr[i];
        (*oddCount)++;
    }
}
