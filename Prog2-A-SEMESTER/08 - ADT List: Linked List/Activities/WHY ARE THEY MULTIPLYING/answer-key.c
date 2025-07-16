#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void modifyList(struct Node** head_ref) {
    struct Node* temp = *head_ref;
    
    while (temp != NULL) {
       
        struct Node* next_node = temp->next;
       
        int modified_value = (temp->data % 2 == 0) ? temp->data * 2 : temp->data + 1;
        
       
        struct Node* newNode = createNode(modified_value);
        newNode->next = next_node;  
        temp->next = newNode;  
    
        
        temp = next_node;
    }
}


int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values for the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Original list:\n");
    printList(head);

    modifyList(&head);

    printf("Modified list:\n");
    printList(head);

    return 0;
}
