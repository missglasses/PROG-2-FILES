//SAY HI TO ERRORS :d
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool insertFront(int a[], int *count, int item, int *n);
void display(int *a, int count);

int main() {
    int *myArray;
    int max=10;
    int count=0;
    
    myArray=malloc(sizeof(int)*max);
    
    insertFront(myArray,&count, 10, &max);
    insertFront(myArray,&count, 20, &max);
    display(myArray, count);

    return 0;
}

bool insertFront(int a[], int *count, int item, int *n) {
    
    if(*count >=*n) {
        a= realloc(a, sizeof(int)*(*n)*2);
        *n*=2;
    }
    
    for (int i=*count; i>0; --i){
        a[i]=a[i-1];
    }
    a[0]=item;
    (*count)++;
      
}


void display(int *a, int count){
    printf("List: {");
    int i;
    for (i=0; i<count; ++i){
        printf("%d", a[i]);
        if(i<count-1){
            printf(",");
        }
    }
    printf("}\n");
}


