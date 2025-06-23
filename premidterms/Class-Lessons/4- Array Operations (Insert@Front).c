#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

bool insertFront(int a[], int *count, int item);
bool insertRear(int a[], int *count, int item);
bool insertAt(int a[], int *count, int pos, int item);
bool insertSorted(int a[], int *count, int item);
void displayArray(int a[], int count, char msg[]);

int main() {
    int myArray[MAX_SIZE];
    int n = 0;
    char menu[5][30] = {"Insert Front", "Insert Rear", "Insert At", "Insert Sorted"};
    int choice, item, pos;
    
    do {
        printf("\n\n");
        for(int i = 0; i < 4; ++i) {
            printf("[%2d.] %s\n", i+1, menu[i]);
        }
        printf("enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("%s\n", menu[choice-1]);
                printf("Enter item: ");
                scanf("%d", &item);
                insertFront(myArray, &n, item);
                printf("Inserting %d in front", item);
                displayArray(myArray, n, "Array");
                break;
            case 2:
                printf("%s\n", menu[choice-1]);
                printf("Enter item: ");
                scanf("%d", &item);
                insertRear(myArray, &n, item);
                printf("Inserting %d in rear", item);
                displayArray(myArray, n, "Array");
                break;
            case 3:
                printf("%s\n", menu[choice-1]);
                printf("Enter item: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAt(myArray, &n, pos, item);
                printf("Inserting %d at %d", item, pos);
                displayArray(myArray, n, "Array");
                break;
            case 4:
                printf("%s\n", menu[choice-1]);
                printf("Enter item: ");
                scanf("%d", &item);
                insertSorted(myArray, &n, item);
                printf("Inserting %d in the sorted array", item);
                displayArray(myArray, n, "Array");
                break;
            case 0:
                printf("End of program.");
                break;
            default:
                printf("Invalid Input.");
        }
    } while (choice != 0);
    
    
    return 0;
}

bool insertFront(int a[], int *count, int item) {
    int i;
    
    if(*count < MAX_SIZE) {
        for(i = *count; i > 0 ; --i) {
            a[i] = a[i-1];
        }
        a[i] = item;
        (*count)++;
        return true;
    }
    
    return false;
}

bool insertRear(int a[], int *count, int item) {
    if(*count < MAX_SIZE) {
        a[(*count)++] = item;
        return true;
    }
    
    return false;
}

bool insertAt(int a[], int *count, int pos, int item) {
    // to do code
    //insert@pos -move until given pos/stop at a certain index
    int i;
//     for (i=0; i<pos; i++){
//     	a[i]=pos;
//     	(*count)++;
//     	return true;
// 	}

 
    if(*count < MAX_SIZE) {
        for(i = *count; i > pos ; --i) {
            a[i] = a[i-1];
        }
        a[i] =item;
        (*count)++;
        return true;
    }
    
    
    return false;
}

bool insertSorted(int a[], int *count, int item) {
    // to do code
    //if item is greater than
    int i;
    if(*count < MAX_SIZE) {
        for(i = *count; i > 0 && a[i - 1]>item ; --i) {
            //(item >a[i-2] wrong
            // item<a[i+1] wrong
            if (a[i]>arr[i]){ // if L > R  ; R = current
            //move 
                 a[i] = a[i-1];
            } else {
                //insert
                // a[i] = item;
           
            // i--;
            }
            
        }
        a[i]=item;
        (*count)++;
    return true;
    }
 
    return false;   //FIX this bro
}

void displayArray(int a[], int count, char msg[]) {
    printf("\n%s: {", msg);
    for(int i = 0; i < count; ++i) {
        printf("%d", a[i]);
        if(i < count - 1) {
            printf(", ");
        }
    }
    printf("}");
}
