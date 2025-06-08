#include <st

// void changeVal(numero)
void changeVal(int *numero)
{
    *numero = 5;
}

int main()
{

    int numero = 3;
    // changeVal(numero);
    changeVal(&numero);

    printf("%d", numero); //prints 5

    return 0;
}
