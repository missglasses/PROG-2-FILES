#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insertLast(Node **head, int data)
{

    Node *C = malloc(sizeof(Node));
    C->data = data;
    C->next = NULL;

    if (*head == NULL)
    {
        *head = C;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = C;
}

int main()
{

    Node *head = NULL;
    Node *A = malloc(sizeof(Node));
    Node *B = malloc(sizeof(Node));
    A->data = 1;
    A->next = B;

    B->data = 2;
    B->next = NULL;

    head = A;

    insertLast(&head, 3);

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
