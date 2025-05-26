#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST

typedef struct
{
    int *data;
    int size;     // no. of elements
    int capacity; // up to what size

} ArrayList;

ArrayList *createList()
{
    ArrayList *list = malloc(sizeof(ArrayList));
    list->capacity = 4;
    list->size = 4;
    list->data = malloc(sizeof(int) * list->capacity);

    // manual way:
    list->data[0] = 5;
    list->data[1] = 15;
    list->data[2] = 25;
    list->data[3] = 35;

    return list;
}

int main()
{
    ArrayList *list = createList();
    printf("Capacity: %d\n", list->capacity);
    printf("Size: %d\n", list->size);
    printf("Contents:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }

    free(list->data);
    free(list);

    return 0;
}
