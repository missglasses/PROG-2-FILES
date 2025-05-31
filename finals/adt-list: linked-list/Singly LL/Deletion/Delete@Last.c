#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void deleteLast(Node **head)
{
    if (*head == NULL)
        return; // check if link is empty

    if ((*head)->next == NULL)
    {
        // if there's only one node
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // helps to point@second to the last node
    free(temp->next);
    temp->next = NULL;
}

int main()
{
    Node *head = malloc(sizeof(Node));
    Node *second = malloc(sizeof(Node));
    Node *third = malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Before deletion
    printf("Original:\n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    deleteLast(&head);

    printf("\nAfter Deletion:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
