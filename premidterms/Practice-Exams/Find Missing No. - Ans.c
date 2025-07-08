#include <stdio.h>

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  //n-1 to prevent oob
      
        if (arr[i+1] - arr[i] != 1) { 
            return arr[i] + 1;
        }
    }
    return -1;  // if no missing no
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    int missing = findMissing(arr, size);

    if (missing == -1) {
        printf("No missing number found.\n");
    } else {
        printf("The missing number is: %d\n", missing);
    }

    return 0;
}

