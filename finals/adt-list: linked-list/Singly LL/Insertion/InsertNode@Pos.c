#include <stdio.h>
#include <stdlib.h>

// DATA TO BE INSERTED : 3
//  @ POSITION: 2

typedef struct node
{
    int data;
    struct node *next;
} Node;

void insertLast(Node **head, int data, int pos)
{

    Node *C = malloc(sizeof(Node));

    C->data = data;
    C->next = NULL;

    // if pos is 0, add node @ beginning
    if (pos == 0)
    {
        C->next = *head;
        *head = C;
        return;
    }

    Node *temp = *head;
    int i = 0;

    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    C->next = temp->next;
    temp->next = C;
}

int main()
{

    Node *head = NULL;
    Node *A = malloc(sizeof(Node));
    Node *B = malloc(sizeof(Node));
    Node *D = malloc(sizeof(Node));
    A->data = 1;
    A->next = B;

    B->data = 2;
    B->next = D;

    D->data = 4;
    D->next = NULL;

    head = A;

    insertLast(&head, 3, 2);

    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
