#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

typedef struct {
    int items[MAX];
    int size;
} ArrayList;

void insertFront(ArrayList* list, int value) {
    if (list->size >= MAX) {
        printf("List is full\n");
        return;
    }


    for (int i = list->size; i > 0; i--) {
        list->items[i] = list->items[i - 1];
    }


    list->items[0] = value;
    list->size++;
}

int main() {
    ArrayList myList = {{}, 0};  // Initialize empty list

    insertFront(&myList, 30); 
    insertFront(&myList, 20);  
    insertFront(&myList, 10);  // Final list: [10, 20, 30]

    printf("List: ");
    for (int i = 0; i < myList.size; i++) {
        printf("%d ", myList.items[i]);
    }

    return 0;
}
