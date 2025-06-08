#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *ptr = (int *)calloc(5, sizeof(int));
    
 
    if (ptr == NULL) {
        printf("Allocation Failed");
        exit(0);
    }
    
    // No need to populate, already initialized to 0
        
    // Print the array
    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);
    return 0;
}
