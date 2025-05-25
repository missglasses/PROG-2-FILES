#include <stdio.h>
#include <stdlib.h>

//SEPARATES THE POSITIVE AND NEGATIVE NUMBERS IN DIFFERENT ARRAYS
void transferPosNeg(int *arr, int n, int *posNum, int *negNum, int *posCount, int *negCount);

int main() {
    int arr[] = {-5, 10, -20, 15, -30, 25, 40};
    int n = 7;
    //newly initialized
    int negNum[10];
    int posNum[10];
    int posCount, negCount;
    
    transferPosNeg(arr, n,posNum, negNum, &posCount, &negCount);
    
    
    printf("Positive numbers: ");
    for (int i=0; i<posCount; i++){
        printf("%d ", posNum[i]);
    }
    printf("\n"); 
     printf("Negative numbers: ");
    for (int i=0; i<negCount; i++){
        printf("%d ", negNum[i]);   
    }
    
    return 0;
}

void transferPosNeg(int *arr, int n, int *posNum, int *negNum, int *posCount, int *negCount){
    *posCount=0;
    *negCount=0; 
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            negNum[*negCount]=arr[i];
            (*negCount)++;
        } else {
            posNum[*posCount]=arr[i];
            (*posCount)++; 
        }
    }

}
