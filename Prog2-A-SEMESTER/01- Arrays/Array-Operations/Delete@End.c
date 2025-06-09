#include <stdio.h>

void deleteLast(int *n) {
    if (*n == 0) {
        printf("Array is already empty!\n");
        return;
    }

    // just decrease the size
    (*n)--;
}

int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;

    // Delete the last element
    deleteLast(&n);

    // Print the updated array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
