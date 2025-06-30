#using var2
#include <stdio.h>
#define MAX 100
#define SENTINEL -1
void parity(int arr[], int newArr[], int n){

    if(n==0){
    newArr[0]=SENTINEL;
    return;
    }
    
    int firstParity = arr[0]%2;
    // *arrCtr=0;
    int i, j=0;
    for(int i=0; i<n; i++){
        if(arr[i]%2==firstParity){
        newArr[j++]=arr[i];
        // (*arrCtr)++;
        // j++;
    }
    }
    newArr[j]=SENTINEL; //as end of the array
}

void main() {
    int list[MAX];
    int newArr[MAX];
    int n;

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
    parity(list, newArr, n);
    int i=0;

     printf("New {");
    while(newArr[i]!=SENTINEL) {
        printf("%d", newArr[i]);
        
        if(newArr[i+1]!=SENTINEL) {
            printf(", ");
            
        }
        i++;
    }
       printf("}\n");

}
