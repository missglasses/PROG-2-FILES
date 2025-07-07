#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10
typedef struct{
	int month;
	int year;
}currentDate;
typedef struct{
	int hireMonth;
	int hireYear;
}hiringDetails;

typedef struct{
	char fName[STRING_MAX];
}empDetails;

typedef struct{
	hiringDetails dateOfHire;
	empDetails employeeInfo;
}employee;

typedef struct{
	employee employeeList[LIST_MAX];
	int count;
}employeeRecords;

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate);

void display(employee *loyalList,int loyalListCount);
int main(){
	employeeRecords record;
	int employeeCount;
	int loyalListCount=0;
	record.count=0;
	employee *loyalList;
	currentDate date={07,2023};
	
	int i=0;
	printf("Input Number of Employees:" );
    scanf("%d",&employeeCount);
    
    //set the record count to the number of employees entered
    record.count = employeeCount;
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	/*CODE FOR INPUTS*/
    	printf("Input First Name: ");
    	scanf(" %[^\n]", &record.employeeList[i].employeeInfo.fName);
    	printf("Input Month of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
    	printf("Input Year of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
	}
	
	loyalList=getLoyalList(record,&loyalListCount,date);
	
// // 	display(/*COMPLETE THE FUNCTION CALL*/);
	display(loyalList, loyalListCount);
	free(loyalList);
	return 0;
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    *loyalListCount=0;
    /*CODE TO CREATE THE LOYAL LIST*/
    for (int i=0; i<record.count; i++){
        int years = currDate.year - record.employeeList[i].dateOfHire.hireYear;
       if(years > 5 || (years == 5 && currDate.month >= record.employeeList[i].dateOfHire.hireMonth))
    {
        (*loyalListCount)++;
    }
    }
    
    // employee *loyalList = malloc(sizeof(employee)*(*loyalListCount));
    
    employee *loyalList = malloc(sizeof(employee) * (*loyalListCount)); 
    int loyalListIndex=0;
    for (int i=0; i<record.count; i++){
        int years = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if(years > 5 || (years == 5 && currDate.month >= record.employeeList[i].dateOfHire.hireMonth))
    {
        loyalList[loyalListIndex]=record.employeeList[i];
        loyalListIndex++;
        
    }
    }
    return loyalList;
}

void display(employee *loyalList,int loyalListCount){
    /*CODE TO DISPLAY*/ 
      if(loyalListCount==0){
          printf("There are currently no Employees who are eligible for the reward.\n");
      } else {
           printf("Loyal List: \n\n");
      }
   
     
    
    for (int i=0; i<loyalListCount; i++){
  
    printf("Name: %s -- Hire Date:%d-%d\n", loyalList[i].employeeInfo.fName, loyalList[i].dateOfHire.hireMonth, loyalList[i].dateOfHire.hireYear);
    }
}
