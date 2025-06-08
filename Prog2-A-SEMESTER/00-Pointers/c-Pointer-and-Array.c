#include <stdio.h>

//  this basically means that arr[0] and ptr both point first on the first element

int main() {
  	int arr[5] = { 1, 2, 3, 4, 5 };
  	int n = sizeof(arr) / sizeof(arr[0]);
  
    
    // Defining the pointer to first element of array
    int* ptr = &arr[0];

    // Traversing array using pointer arithmetic
    for (int i = 0; i < 5; i++)
        printf("%d ",ptr[i]);
    return 0;
}
