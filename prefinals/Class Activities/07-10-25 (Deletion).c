#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct node {
    int data;
    struct node *next;
} NodeType, *NodePtr;

// Function declarations
void insertFront(NodePtr *list, int data);
void display(NodePtr list);
int sumEven(NodePtr list);
int countPrime(NodePtr list);
float getAverage(NodePtr list);
bool isPalindrome(NodePtr list);
int countOccurence(NodePtr list, int data);
NodePtr getAllAboveAverage(NodePtr list);
bool deleteItem(NodePtr *list, int item);
bool deleteAllItem(NodePtr *list, int item);
void insertSorted(NodePtr *list, int item);
NodePtr removeDuplicates(NodePtr *list, int item);

// Helper
int isPrime(int num);
bool checkPal(int num);

int main() {
    NodePtr myList = NULL;

    // Build list
    insertFront(&myList, 66);
    insertFront(&myList, 45);
    insertFront(&myList, 89);
    insertFront(&myList, 121);
    insertFront(&myList, 1331);
    display(myList);

    // Palindrome check
    if (isPalindrome(myList))
        printf("All numbers in the list are palindromes\n");
    else
        printf("Not all numbers in the list are palindromes\n");

    // Function tests
    printf("\nOther function tests:\n");
    printf("Sum of even numbers: %d\n", sumEven(myList));
    printf("Count of prime numbers: %d\n", countPrime(myList));
    printf("Average: %.2f\n", getAverage(myList));
    printf("Count of 45: %d\n", countOccurence(myList, 45));

    NodePtr aboveAvgList = getAllAboveAverage(myList);
    printf("Above average elements: ");
    display(aboveAvgList);

    // Deletion test
    printf("\nDeleting 45 (first occurrence)...\n");
    deleteItem(&myList, 45);
    display(myList);

    printf("Deleting all 121s...\n");
    deleteAllItem(&myList, 121);
    display(myList);

    // Insert sorted
    insertSorted(&myList, 50);
    insertSorted(&myList, 30);
    insertSorted(&myList, 99);
    printf("\nAfter sorted insertions:\n");
    display(myList);

    // Remove duplicates
    insertSorted(&myList, 50); // duplicate
    insertSorted(&myList, 30); // duplicate
    printf("List with duplicates:\n");
    display(myList);

    NodePtr rem
