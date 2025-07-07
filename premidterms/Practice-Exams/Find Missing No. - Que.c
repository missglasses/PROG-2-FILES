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

    printf("The missing number is: %d", missing);
    




    return 0;
}
