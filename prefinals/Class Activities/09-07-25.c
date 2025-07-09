#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
    int data;
    struct node *next;
}NodeType, *NodePtr; 

void insertFront(NodePtr *list, int data);
void display(NodePtr list);

int sumEven(NodePtr list);
int countPrime(NodePtr list);
float getAverage(NodePtr list);
bool isPalindrome(NodePtr list);
int countOccurence(NodePtr list, int data);
NodePtr getAllAboveAverage(NodePtr list);


int main (){
    NodePtr myList =NULL; 
    NodePtr *pList = &myList;

    display(myList);
    insertFront(&myList, 66);
    //you can also:
    //insertFront(pList, 66);
    display(myList);
    insertFront(&myList, 45);
    display(myList);
    insertFront(&myList, 89);
    display(myList);
    

    return 0;
}

void insertFront(NodePtr *list, int data){

    NodePtr temp = malloc(sizeof(NodeType)); //if it doesn't work, use struct node 
    
    if (temp){
        temp->data=data;
        temp->next=*list;
        *list = temp;
    }

}

void display(NodePtr list){

    printf("{");
    while(list){
        printf("%d", list->data);
        if(list->next!=NULL){
            printf("->");
        }
        list = list->next;
    }
      printf("}\n");

}

int sumEven(NodePtr list){
    int sumEv =0;

    NodePtr temp = list;

    while(temp!=NULL){
    if (temp->data%2==0){
        sumEv +=temp->data;
    }
    temp = temp->next;
    }
    return sumEv;
}
int countPrime(NodePtr list){

    int prime=1;

    for(int i*i; i< ; --i){ //i forgot brooo
        if (if n<){

        }
    }


}
float getAverage(NodePtr list){

     int count=0;
     int sum =0.0;

     NodePtr temp =list;

     while   (temp!=NULL){
        sum += list->data;
        count++;
        temp = temp->next; //traverse
     }

     return sum/count; 

}
bool isPalindrome(NodePtr list){

}
int countOccurence(NodePtr list, int data){

}
NodePtr getAllAboveAverage(NodePtr list){

}
