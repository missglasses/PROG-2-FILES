    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    void arrayCleaning(int arr[],int cleanedArr[],int count, int* cleanedCount);
    void display(int arr[],int cleanedCount);
    
    /*
    If you wish to add a sentinel value to the end of the array to signify the end of the array, you may but make sure you use another value from "-1".
    
    If you wish to choose this implementation, feel free to edit the function prototypes
    */
    
    int main(){
    	int arr[100];
    	int arrCount=0;
    	int cleanedArr[100];
    	int cleanedCount=0;
    	/*you may add as many other variables as necessary*/
    
    
    	/* TODO: Ask user input for how many items in array */
    	printf("Input how many items in the array: ");
    	int size;
    	scanf("%d", &arrCount);
    
    	/* TODO: Populate Array*/
    	printf("Input Array Values: ");
    	for(int i=0; i<arrCount; i++){
    	    scanf("%d", &arr[i]);
    	}
    	
        /* TODO: Complete Function call */
    // 	cleanedArr=arrayCleaning(arr,cleanedArr,arrCount,&cleanedCount);
    arrayCleaning(arr,cleanedArr,arrCount,&cleanedCount);
    	
    
    	/* TODO: Call to display */
    	display(cleanedArr, cleanedCount);
    
    
    }
    
    void arrayCleaning(int arr[],int cleanedArr[],int count, int* cleanedCount){
        *cleanedCount=0;
        int flag=0;
        
        for (int i=0; i<count; i++){
            if (arr[i]==-1){
                flag = !flag;
                continue; //skips -1
            }
            if(!flag){
                cleanedArr[(*cleanedCount)++]=arr[i];
            }
        }
    }
    
    void display(int arr[],int cleanedCount){
        if(cleanedCount==0){
            printf("\nOh no Data is fully corrupted and cannot be recovered!\n");
            return;
        }
        
        printf("Data has been recovered!\n");
        printf("Cleaned Data:");
        for(int i=0; i<cleanedCount; i++){
            printf(" %d ", arr[i]);
            
        }
        printf("\n");
    }
