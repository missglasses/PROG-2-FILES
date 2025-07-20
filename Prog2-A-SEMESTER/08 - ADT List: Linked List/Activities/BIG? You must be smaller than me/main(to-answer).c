#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

// [ANSWER No. 1] insert your function definition for isDesceding()





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

    // [ANSWER No. 2] Add function call for isDescending()




    return 0;
}
