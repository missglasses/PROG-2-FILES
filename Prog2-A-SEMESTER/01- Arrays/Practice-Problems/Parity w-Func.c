//using variation #1
#include <stdio.h>
#define MAX 100

void parity(int arr[], int newArr[], int n, int *arrCtr){
    if(n==0){
        *arrCtr=0;
        return;
    }
    
    
    int firstParity = arr[0]%2;
    *arrCtr=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==firstParity){
            newArr[(*arrCtr)]=arr[i];
            (*arrCtr)++;
        }
    }
    // newArr[0]=j-1; //stores at index[0]
    

}

void main() {
    int list[MAX];
    int newArr[MAX];
    int n, arrCtr;

    printf("Enter how many values: ");
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", list+i);
    }

    printf("Original {");
    for(int i = 0; i < n; ++i) {
        printf("%d", *(list + i));
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("}\n");
    
    
    // int newArr=
    parity(list, newArr, n, &arrCtr);
     printf("New {");
    for(int i = 0; i < arrCtr; ++i) {
        printf("%d", newArr[i]);
        if(i < arrCtr-1) {
            printf(", ");
        }
    }
       printf("}\n");

}
