#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)calloc(sizeof(int), 5);
    
    //some code here...  :P
    free(ptr);
    
    return 0;
}
