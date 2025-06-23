#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5

bool insertAt(int a[], int *count, int pos, int item);

int main() {
    int myArray[MAX_SIZE];
    int n=0;
    
    insertAt(myArray, &n, 0, 30); 
    insertAt(myArray, &n, 1, 40); //30,40
    
    
    int i;
    for(i=0; i<n; ++i){
        printf("%d ", myArray[i]);
        
    }
   
    return 0;
}




bool insertAt(int a[], int *count, int pos, int item){
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
        a[pos] =item;
        (*count)++;
        return true;
    }
    
    
    return false;
}
