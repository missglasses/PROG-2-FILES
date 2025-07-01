#include <stdio.h>
#include <stdlib.h>

int findMissing(int arr[], int n, int *missingNo){
    for(int i=0; i<n-1; i++){
        if(arr[i+1]-arr[i]!=1){
            *missingNo=arr[i]+1;
            return 0;
        }
    }
    return -1;
}

int main(){
    int arr[100];
    int count=0;

    int missingNo=0;
    
     printf("Input Count of Array: ");
    scanf("%d", &count);
    printf("\n");
    
    printf("Populate Array:");
    for (int i=0; i<count; i++){
        scanf("%d", &arr[i]);
    }
    
     findMissing(arr, count, &missingNo);
    printf("\n\n");
    printf("Missing Number is: %d\n", missingNo);
    
    return 0;
}
