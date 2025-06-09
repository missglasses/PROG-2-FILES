#include <stdio.h>

void deleteAtPos(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) { //less than 0 or greater/equal to size
        printf("Invalid position!\n");
        return;
    }

    // shift elements left from pos
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // decrease the size
    (*n)--;
}

int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;  

    deleteAtPos(arr, &n, pos);


    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
