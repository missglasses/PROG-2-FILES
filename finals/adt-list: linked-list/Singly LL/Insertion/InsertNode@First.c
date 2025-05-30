#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insertFirst(Node **head, int data)
{
    Node *A = malloc(sizeof(Node));

    A->data = data;
    A->next = *head;

    *head = A; // head points to this new node
}
int main()
{
    Node *head = NULL;
    Node *B = malloc(sizeof(Node));
    Node *C = malloc(sizeof(Node));
    B->data = 2;
    B->next = C;
    C->data = 3;
    C->next = NULL;

    head = B; // head currently points to B

    insertFirst(&head, 1);

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
