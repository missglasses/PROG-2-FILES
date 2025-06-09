#include <stdio.h>

void deleteFirst(int arr[], int *n) {
    if (*n==0){
        printf("Empty");
    }
    
    //shifts array to the left
    for (int i=0; i<*n; i++){
        arr[i]=arr[i+1];
        
    }

    (*n)--;
}   
int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;

    // Delete the first element
    deleteFirst(arr, &n);

    // Print the updated array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
