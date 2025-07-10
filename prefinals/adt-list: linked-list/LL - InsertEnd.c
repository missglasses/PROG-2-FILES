#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;

}NodeType, *NodePtr; 

void insertFront(NodePtr *list, int data);
void insertEnd(NodePtr *list, int data);
void display(NodePtr list);

int main (){
    NodePtr frontList = NULL;
    NodePtr endList = NULL;

//from 89, 90, 66, 45
//89, 90
//80, 66, 90
//80, 66, 90 , 45
    insertFront(&frontList, 89);
     insertEnd(&endList, 90);
    insertFront(&endList, 66);
    insertEnd(&endList, 45);
    display(frontList);
    display(endList);
    printf("\n");
    

    return 0;
}

void insertFront(NodePtr *list, int data) {
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp) {
        temp->data = data;
        temp->next = *list;
        *list = temp;
    }
}

void insertEnd(NodePtr *list, int data){
    NodePtr temp = malloc(sizeof(NodeType));
    if (temp) {
        temp->data = data;
        temp->next = NULL;

        //check if list is null else traverse to last node
        if (*list == NULL) {
            // List is empty, new node becomes the first node
            *list = temp; //node becomes first node instead
        } else {
            // Traverse to the last node
            NodePtr current = *list;//a pointer that points at the head of the list
            while (current->next != NULL) {
                current = current->next;//traverse
            }
            current->next = temp;//points to the new node
        }
    }
}

void display(NodePtr list) {
    while (list) {
        printf("%d", list->data);
        // if (list->next != NULL) {
            printf(" ");
        // }
        list = list->next;
    }
    // printf(" ");
}
/* OUTPUT: 
{}
{66}
{45->66}
{89->45->66}*/
