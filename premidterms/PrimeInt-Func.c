#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* transferPrimes(int* arr, int n, int* primeCount);
int isPrime(int num);

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = 10;
    int primeCount;
    
    int *prime = transferPrimes(arr, n, &primeCount);
    printf("Prime numbers: ");
    for(int i=0; i<primeCount; i++){
        printf("%d ", prime[i]);
    }
    
    
}


int isPrime(int num){
    if (num<2) return 0;
    
    for (int i=2; i*i<=num; i++){
        if(num%i==0) return 0;
    }
    
    return 1;
}

int* transferPrimes(int* arr, int n, int* primeCount){
    *primeCount =0;
    
    for (int i=0; i<n; i++){
        if(isPrime(arr[i])){
            (*primeCount)++;
        }
    }
    
    int *prime = (int*)malloc((*primeCount) * sizeof(int));
    
    int index=0;
    for (int i=0; i<n; i++){
        if(isPrime(arr[i])){
            prime[index++]=arr[i];
        }
    }
    return prime;
}
