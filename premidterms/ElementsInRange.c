#include <stdio.h>
#include <stdlib.h>

//DISPLAYS ELEMENTS ONLY IN GIVEN RANGE

int* transferInRange(int *arr, int n, int low, int high, int *count) {
    int i, j = 0;


    for (i = 0; i < n; i++) {
        if (arr[i] >= low && arr[i] <= high) {
            (*count)++;
        }
    }

    if (*count == 0) {
        return NULL;
    }


    int *filteredArr = (int*)malloc((*count) * sizeof(int));
   
    for (i = 0; i < n; i++) {
        if (arr[i] >= low && arr[i] <= high) {
            filteredArr[j++] = arr[i];
        }
    }

    return filteredArr;
}

int main() {
    int arr[] = {1, 15, 25, 30, 50, 65, 70, 80};
    int n = 8;
    int low, high;
    int rangeCount = 0;
    int *newArr;


    printf("Input Low Range: ");
    scanf("%d", &low);
    printf("Input High Range: ");
    scanf("%d", &high);

    
    newArr = transferInRange(arr, n, low, high, &rangeCount);

  
    if (newArr == NULL) {
        printf("No elements in range [%d,%d]\n", low, high);
    } else {
        printf("Elements in range [%d, %d]: ", low, high);
        for (int i = 0; i < rangeCount; i++) {
            printf("%d ", newArr[i]);
        }
        printf("\n");

      
        free(newArr);
    }

    return 0;
}
