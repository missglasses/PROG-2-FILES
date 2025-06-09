#include <stdio.h>

void searchElement(int arr[], int n, int key) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;  // Element to search for

    searchElement(arr, n, key);

    return 0;
}
