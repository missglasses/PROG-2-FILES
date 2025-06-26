#include <stdio.h>

// STRUCT POINTER APPLICATION
//->  
struct Car
{
    int id;
    char brand[20];
    char model[20];
    char color[20];
};

int main()
{

    struct Car car = {00, "Mazda", "Miata", "Black"}; // initial values

    struct Car *carPtr = &car; //this is the structure pointer

    printf("Car Details:\n");
    printf("ID: %d\n", carPtr->id);
    printf("Brand: %s\n", carPtr->brand);
    printf("Model: %s\n", carPtr->model);
    printf("Color: %s\n", carPtr->color);

    return 0;
}
