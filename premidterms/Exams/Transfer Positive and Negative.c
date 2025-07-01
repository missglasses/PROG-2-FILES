#include <stdio.h>
#include <stdlib.h>

void transferPosNeg(int arr[], int n, int posNum[], int negNum[], int *posCount, int *negCount) {
    *posCount = 0;
    *negCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            (*negCount)++;   
        } else {
            (*posCount)++;
        }
    }
    
    *posCount = 0;
    *negCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negNum[(*negCount)++] = arr[i];
        } else {
            posNum[(*posCount)++] = arr[i];
        }
    }
}

int main() {
    int arr[] = {-5, 10, -20, 15, -30, 25, 40};
    int n = 7;
    int posCount = 0;
    int negCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negCount++;   
        } else {
            posCount++;
        }
    }
    
    int posNum[posCount];
    int negNum[negCount];
    
    transferPosNeg(arr, n, posNum, negNum, &posCount, &negCount);
    
    printf("Positive numbers: ");
    for (int i = 0; i < posCount; i++) {
        printf("%d ", posNum[i]); 
    }
    printf("\n"); 
    
    printf("Negative numbers: ");
    for (int i = 0; i < negCount; i++) {
        printf("%d ", negNum[i]);
    }
    printf("\n"); 
    
    return 0;
}
