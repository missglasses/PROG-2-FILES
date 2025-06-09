#include <stdio.h>
#include <stdlib.h>

int main() {
    // atoi - Convert string to int
    char numStr[] = "123";
    int num = atoi(numStr);
    printf("Function: atoi → %d\n", num);

    // atof - Convert string to float
    char floatStr[] = "3.14";
    double fnum = atof(floatStr);
    printf("Function: atof → %.2f\n", fnum);

    // rand - Generate random number
    int r = rand();
    printf("Function: rand → %d\n", r);

    // malloc - Allocate memory
    int *arr = (int *)malloc(3 * sizeof(int));
    arr[0] = 10; arr[1] = 20; arr[2] = 30;
    printf("Function: malloc → %d %d %d\n", arr[0], arr[1], arr[2]);

    // realloc - Resize memory
    arr = (int *)realloc(arr, 5 * sizeof(int));
    arr[3] = 40; arr[4] = 50;
    printf("Function: realloc → %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    // calloc - Allocate and zero memory
    int *zeroArr = (int *)calloc(3, sizeof(int));
    printf("Function: calloc → %d %d %d\n", zeroArr[0], zeroArr[1], zeroArr[2]);

    // free - Free memory
    free(arr);
    free(zeroArr);
    printf("Function: free → Memory freed\n");

    return 0;
}
