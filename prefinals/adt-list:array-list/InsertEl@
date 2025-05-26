#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST
//Element to be inserted: 20

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

// to resize array when full-- doubling it
void resize(ArrayList *list)
{
    list->capacity *= 2;
    list->data = realloc(list->data, sizeof(int) * list->capacity);
}

void insert(ArrayList *list, int index, int value)
{
    if (index < 0 || index > list->size)
    {
        printf("Invalid index\n");
        return;
    }

    // to resize when full
    if (list->size == list->capacity)
    {
        resize(list);
    }

    // to shift elements right from index onwards
    for (int i = list->size - 1; i >= index; i--)
    {
        list->data[i + 1] = list->data[i];
    }

    // insert new val & update size
    list->data[index] = value;
    list->size++;
}

int main()
{
    ArrayList *list = createList();

    printf("Before insert:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");

      insert(list, 2, 20);

    printf("After insert:\n");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");

    free(list->data);
    free(list);

    return 0;
    return 0;
}
