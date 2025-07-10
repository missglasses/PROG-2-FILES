#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} NodeType, *NodePtr;

void insertFront(NodePtr *list, int data);
void display(NodePtr list);

int sumEven(NodePtr list);
int countPrime(NodePtr list);
float getAverage(NodePtr list);
bool isPalindrome(NodePtr list);
int countOccurence(NodePtr list, int data);
NodePtr getAllAboveAverage(NodePtr list);

int main()
{
    NodePtr myList = NULL;
    NodePtr *pList = &myList;

    display(myList);
    insertFront(&myList, 66);
    display(myList);
    insertFront(&myList, 45);
    display(myList);
    insertFront(&myList, 89);
    display(myList);

    printf("\nAdding palindrome numbers:\n");
    insertFront(&myList, 121);
    insertFront(&myList, 1331);
    display(myList);

    /*printf("Is all numbers palindrome? %s\n",
           isListPalindrome(myList) ? "Yes" : "No");*/
    if (isPalindrome(myList))
    {
        printf("All numbers in the list are palindromes\n");
    }
    else
    {
        printf("Not all numbers in the list are palindromes\n");
    }

    printf("\nOther function tests:\n");
    printf("Sum of even numbers: %d\n", sumEven(myList));
    printf("Count of prime numbers: %d\n", countPrime(myList));
    printf("Average: %.2f\n", getAverage(myList));
    printf("Count of 45: %d\n", countOccurence(myList, 45));

    NodePtr aboveAvgList = getAllAboveAverage(myList);
    printf("Above average elements: ");
    display(aboveAvgList);

    return 0;
}

void insertFront(NodePtr *list, int data)
{

    NodePtr temp = malloc(sizeof(NodeType)); // if it doesn't work, use struct node daw

    if (temp)
    {
        temp->data = data;
        temp->next = *list;
        *list = temp;
    }
}

void display(NodePtr list)
{

    printf("{");
    while (list)
    {
        printf("%d", list->data);
        if (list->next != NULL)
        {
            printf("->");
        }
        list = list->next;
    }
    printf("}\n");
}

int sumEven(NodePtr list)
{
    int sumEv = 0;

    NodePtr temp = list;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            sumEv += temp->data;
        }
        temp = temp->next;
    }
    return sumEv;
}

/* 2 FUNCTIONS FOR PRIME COUNTER*/
int isPrime(int num)
{
    if (num <= 1)
        return 0;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int countPrime(NodePtr list)
{
    int primeCtr = 0;
    while (list != NULL)
    {
        if (isPrime(list->data))
        {
            primeCtr++;
        }
        list = list->next;
    }
    return primeCtr;
}
float getAverage(NodePtr list)
{

    int count = 0;
    int sum = 0.0;

    NodePtr temp = list;

    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next; // traverse
    }

    // return sum / count;
    return (float)sum / count; // typecast bro
}

/*TWO FUNCTIONS TO CHECK PALINDROME */
bool checkPal(int num)
{
    if (num < 0)
        return 0;
    int rev = 0, org = num;
    while (num > 0)
    {   
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return org == rev;
}

bool isPalindrome(NodePtr list)
{
    while (list != NULL)
    {
        if (!checkPal(list->data))
        {
            return false;
        }
        list = list->next;
    }
    return true;
}

int countOccurence(NodePtr list, int data)
{
    // count occurence of a data
    int count = 0;
    while (list != NULL)
    {
        if (list->data == data)
        {
            count++;
        }
        list = list->next; // traverse
    }

    return count;
}
NodePtr getAllAboveAverage(NodePtr list)
{
    if (list == NULL)
        return NULL;

    // call the other ave func
    float avg = getAverage(list);
    NodePtr newList = NULL;

    int count = 0;
    NodePtr temp = list;
    while (temp != NULL)
    {
        if (temp->data > avg)
        {
            count++;
        }
        temp = temp->next; // traverse
    }

    if (count == 0)
        return NULL;

    // this is to create new list
    temp = list;
    while (temp != NULL)
    {
        if (temp->data > avg)
        {
            NodePtr newNode = malloc(sizeof(NodeType));
            newNode->data = temp->data;
            newNode->next = newList; // which is null pa?
            newList = newNode;
        }
        temp = temp->next; // traverse
    }

    return newList;
}
