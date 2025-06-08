#include <stdio.h>
// THIS FILE MAY NOT RUN/WORK WELL; I JUST COMBINED ALL CODES IN ONE FILE HEHE
int main()
{

    // Increment / Decrement of a Pointer
    int arr[] = {10, 20, 30};
    int *ptr = arr;

    printf("Original pointer points to: %d\n", *ptr);

    ptr++; // Increment
    printf("After increment: %d\n", *ptr);

    ptr--; // Decrement
    printf("After decrement: %d\n", *ptr);

    // Addition of Integer to a Pointer
    int arr[] = {5, 15, 25, 35};
    int *ptr = arr;

    ptr = ptr + 2;
    printf("Pointer after adding 2: %d\n", *ptr); // Should print 25

    // Subtraction of Integer from a Pointer
    int arr[] = {3, 6, 9, 12};
    int *ptr = arr + 3; // Points to 12

    ptr = ptr - 2;
    printf("Pointer after subtracting 2: %d\n", *ptr); // Should print 6

    // Subtracting Two Pointers of the Same Type
    int arr[] = {100, 200, 300, 400};
    int *ptr1 = &arr[3];
    int *ptr2 = &arr[0];

    int diff = ptr1 - ptr2;                            // Number of elements between the pointers
    printf("Difference between pointers: %d\n", diff); // Should print 3

    // How? 12 bytes in array
    // 12/4 bytes each element = 3

    // Comparison of Pointers
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr1 = &arr[1]; // Points to 2
    int *ptr2 = &arr[3]; // Points to 4

    if (ptr1 < ptr2)
    {
        printf("ptr1 points to an earlier element than ptr2\n");
    }
    else
    {
        printf("ptr1 does not point to an earlier element\n");
    }

    return 0;
}
