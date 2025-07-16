#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void modifyList(struct Node** head_ref) {

    /*3.) WRITE CODE TO MODIFY THE LINKED LIST AS PER SPECIFICATIONS*/
}


int main() {
    struct Node* head = NULL;


    printf("Enter the number of nodes: ");
    /*1.) WRITE CODE TO GET HOW MANY INPUTS FOR LINKED LIST*/

    printf("Enter the values for the nodes:\n");
    /*2.) WRITE CODE TO GET POPULATE THE LINKED LIST*/

    printf("Original list:\n");
    printList(head);

    modifyList(&head);

    printf("Modified list:\n");
    printList(head);

    return 0;
}
