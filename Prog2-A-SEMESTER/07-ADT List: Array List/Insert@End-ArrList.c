#include<stdio.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int size;
} ArrayList;

void insertEnd(ArrayList* list, int value) {
    if (list->size >= MAX) {
        printf("List is full. Cannot insert %d.\n", value);
        return;
    }

    list->items[list->size] = value; //first: size =0; 
    list->size++; //first: size =1;
}


int main() {
    ArrayList myList = {{}, 0};  //init empty list

    insertEnd(&myList, 10);
    insertEnd(&myList, 20);
    insertEnd(&myList, 30);  // List: [10, 20, 30]

    printf("List: ");
    for (int i = 0; i < myList.size; i++) {
        printf("%d ", myList.items[i]);
    }

    return 0;
}
