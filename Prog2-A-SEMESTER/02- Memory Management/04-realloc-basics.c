#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *ptr = (int *)malloc(5 * sizeof(int));
    
    if (ptr == NULL) {
        printf("Memory Allocation Failed\n");
        exit(0);
    }
    
    //realloc from 5 integers to 8
    ptr = (int *)realloc(ptr, 8 * sizeof(int)); 
    
    // check if successful
    if (ptr == NULL) {
        printf("Memory Reallocation Failed\n");
        exit(0);
    }
    
    //assume 5 elements only
    for (int i = 0; i < 5; i++) {
        ptr[i] = (i + 1) * 10;
    }
    
    //shrink back to 5 elements
    ptr = (int *)realloc(ptr, 5 * sizeof(int));
    
    
    if (ptr == NULL) {
        printf("Memory Reallocation Failed\n");
        exit(0);
    }
    
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
 
    free(ptr);
    
    return 0;
}
