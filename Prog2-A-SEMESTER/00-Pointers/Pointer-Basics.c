#include <stdio.h>

// Pointers

int main()
{
    // Declaration
    // syntax:
    // data_type* name
    // int ptr;

    int numero = 2;
    // Initialization
    int *ptr = &numero; // Dereference
    char *ptr2;

    // prints value
    printf("%d\n", numero);
    // prints address of numero
    printf("%p\n", &numero);
    // prints address of pointer
    printf("%p\n", ptr);

    // SIZE of pointers: 32bit - 4 bytes; 64bytes - 8 bytes
    printf("%zu\n", sizeof(ptr));
    printf("%zu\n", sizeof(ptr2));

    // NULL
    int *ptr = NULL;

    //POINTER ARITHMETIC IN SEPARATE FILE

    return 0;
}
