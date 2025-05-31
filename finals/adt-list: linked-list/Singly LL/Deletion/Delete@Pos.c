#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void deleteAtPos(Node **head, int position)
{
    if (*head == NULL || position < 1)
        return;

    if (position == 1)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    for (int i = 1; i < position - 1 && current->next != NULL; i++)
    {
        current = current->next;
    }

    if (current->next == NULL)
        return;

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
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

    printf("Original:\n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    deleteAtPos(&head, 2);
    printf("\nAfter Deletion at position 2:\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
