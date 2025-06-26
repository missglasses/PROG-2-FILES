#include <stdio.h>
#define SIZE 5

typedef struct {
    int id;
    char brand[20];
    char model[20];
    char color[20];
} Car;

int main() {
    Car cars[SIZE] = {
        {1, "Toyota", "Corolla", "Red"},
        {2, "Honda", "Civic", "Blue"},
        {3, "Ford", "Mustang", "Black"},
        {4, "Tesla", "Model 3", "White"},
        {5, "BMW", "X5", "Silver"}
    };

    for (int i = 0; i < SIZE; i++) {
        printf("Car %d: %s %s (%s)\n", cars[i].id, cars[i].brand, cars[i].model, cars[i].color);
    }

    return 0;
}
