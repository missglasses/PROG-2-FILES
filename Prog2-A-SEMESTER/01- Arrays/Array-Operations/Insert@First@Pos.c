#include <stdio.h>
//BOTH WORKS FOR INSERTION @POS AND INSERTION @FIRST ELEMENT
void insertAtPos(int arr[], int *n, int pos, int val) {
    // shift elements to the right
    for (int i = *n; i > pos; i--) { // starts at the end of the current array (i = *n)
        arr[i] = arr[i - 1]; //shifts each element one position to the right.
    }

    arr[pos] = val; // insert the new value at index pos.

    //increase array size by one bc a new element was added 
    (*n)++;
}

int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 3;
    int val = 25;

    insertAtPos(arr, &n, pos, val);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
