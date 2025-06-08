#include <stdio.h>
#include <stdlib.h>

int main() {
    // syntax: 
    // dt ptr = (dt*)malloc(sizeof(dt)*size);
    int *ptr = (int *)malloc(sizeof(int) * 5);
    
    // checks if failed or pass
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // populates
    for (int i = 0; i < 5; i++)
        ptr[i] = i + 1;
        
    
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return 0;
}
