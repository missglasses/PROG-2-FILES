#include <stdio.h>

void insertLast(int arr[], int *n, int val) {

   arr[*n] = val; //*n is the index (last) where the new value will be inserted
   
   (*n)++; //increases size bc a new element was added
}

int main() {
    int arr[7] = {10, 20, 30, 40, 50};
    int n = 5;
    int val = 25;

    //insert val @end
    insertLast(arr, &n, val);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
