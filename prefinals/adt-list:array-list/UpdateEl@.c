#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST
//Changes value of an element @specific index 

typedef struct
{
    int *data;
    int size;     // number of elements
    int capacity; // maximum capacity

} ArrayList;

ArrayList *createList()
{
    ArrayList *list = malloc(sizeof(ArrayList));
    list->capacity = 4;
    list->size = 4;
    list->data = malloc(sizeof(int) * list->capacity);

    list->data[0] = 5;
    list->data[1] = 15;
    list->data[2] = 25;
    list->data[3] = 35;

    return list;
}

void update(ArrayList *list, int index, int value)
{
    if (index < 0 || index >= list->size)
    {
        printf("Invalid index\n");
        return;
    }
    list->data[index] = value;
}

int main()
{
    ArrayList *list = createList();

    update(list, 1, 100); // changes index 1 element to 100

    printf("%d\n", list->data[1]); // prints 100

    free(list->data);
    free(list);

    return 0;
}
