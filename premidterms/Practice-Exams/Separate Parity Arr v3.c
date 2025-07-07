#include <stdio.h>
#define MAX 100

int parity(int arr[], int n, int newArr[]){
    int count=0;
    int isEven = arr[0]%2==0;
    for (int i=0; i<n; i++){
        if ((arr[i]%2==0)==isEven){
            newArr[++count]=arr[i]; //starts@1
        }
    }
    
    newArr[0]=count; //stores count@index0;
    return count;
}

int main() {
    int list[MAX];
    int n;
    //insert new array
    int newList[MAX];
    printf("Enter how many values: ");
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", list+i);
    }   
    
    
     parity(list, n, newList);
     
    printf("Original {");
    for(int i = 0; i < n; ++i) {
        printf("%d", list[i]);
        if(i < n-1) {
            printf(", ");
        }
    }
    printf("}\n");
    
    printf("New {");
    for (int i = 1; i <= newList[0]; ++i) {
        printf("%d", newList[i]);
        if (i < newList[0]) {
            printf(", ");
        }
    }
    printf("}\n");
  
return 0;
}
