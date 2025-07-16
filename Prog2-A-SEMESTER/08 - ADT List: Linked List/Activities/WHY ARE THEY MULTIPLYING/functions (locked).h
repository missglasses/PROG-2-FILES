#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data);

void append(struct Node** head_ref, int new_data) ;/*INSERTS A NODE INTO THE LINKED LIST FOR INITIAL POPULATION*/

void printList(struct Node* node);



#endif
