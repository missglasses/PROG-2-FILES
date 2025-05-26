#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST
// Removes an element @specific index

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

void removeAt(ArrayList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Invalid index\n");
        return;
    }

    // shifts elements to the left to overwrite the removed element
    for (int i = index; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
}

int main()
{
    ArrayList *list = createList();

    removeAt(list, 2); // removes element at index 2

    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    // expected output: 5 15 35

    free(list->data);
    free(list);

    return 0;
}
