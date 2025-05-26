#include <stdio.h>
#include <stdlib.h>

// ARRAY LIST
//Gets element : 25

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

int get(ArrayList *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        printf("Invalid index\n");
        return -1;
    }
    return list->data[index];
}

int main()
{
    ArrayList *list = createList();

    int val = get(list, 2);
    if (val != -1)
    {
        printf("%d\n", val);  //prints 25
    }

    free(list->data);
    free(list);

    return 0;
}
