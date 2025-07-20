#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

// [ANSWER No. 1] insert your function definition for removeAfter()


// the main()
int main() {
    Node* head = NULL;
    int n, item;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input and insert nodes into the list
    for(int i = 0; i < n; ++i) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &item);
        insertNode(&head, item);
    }

    printf("List: ");
    printList(head);

    int ditem;
    NodePtr removedList = NULL;

    printf("\nEnter item: ");
    scanf("%d", &ditem);

    // [ANSWER No. 2] Add function call for removeAfter()


    //end of Answer No. 2

    printf("Orginal List (after delete): ");
    printList(head);
    printf("Deleted List: ");
    printList(removedList);

    return 0;
}
