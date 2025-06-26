#include <stdio.h>
#include <stdlib.h>
//SELF-REFERENTIAL 

typedef struct Node {
    int data;
    struct Node* next;// <--
} Node;

int main() {
    
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL; 


    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data); 
        temp = temp->next;
    }
    printf("NULL\n");


    free(head);
    free(second);
    free(third);

    return 0;
}
