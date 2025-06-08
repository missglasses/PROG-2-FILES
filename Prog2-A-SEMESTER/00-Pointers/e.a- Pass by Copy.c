#include <stdio.h>
//THE VALUE IN MAIN REMAINS THE SAME
void changeVal(numero)
{
    numero = 5;
}

int main()
{

    int numero = 3;
    changeVal(numero);

    printf("%d", numero); //prints 3

    return 0;
}
