#include <stdio.h>
#include <stdlib.h>

/* FUNC: DOUBLES THE ELEMENTS IN ARRAY */

int *doubleArray(int arr[], int count)
{
    int *newArr;
    int i;
    newArr = malloc(sizeof(int) * count);
    for (i = 0; i < count; i++)
    {
        newArr[i] = arr[i] * 2;
    }
    return newArr;
}

int main()
{
    int count = 10;
    int arr[10];

    int *newArr;
    int i;
    for (i = 0; i < count; i++)
    {
        printf("Input Arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    newArr = doubleArray(arr, count);
    printf("\n");

    printf(" Doubled Array:");
    for (i = 0; i < count; i++)
    {
        printf("%d ", newArr[i]);
    }
}
