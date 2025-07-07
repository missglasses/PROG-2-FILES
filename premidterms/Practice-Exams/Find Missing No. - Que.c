#include <stdio.h>


int main (){

    int size,missing;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    int i;
    for (i=0; i<size; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    /*for (i=0; i<size; i++){
        if (arr[i+1]-arr[i-1]!=1){
          missing = arr[i+1]-arr[i-1];
        }
    }*/

    for (i=0; i<size; i++){
        if (arr[i+1]-arr[i]==1){
       //   missing = arr[i++]-arr[i-1];
            missing = arr[i]+arr[i+1];
        }
    }
    printf("The missing number is: %d", missing);
    




    return 0;
}
