#include <stdio.h>
#include <stdlib.h>
#define STRING_MAX 50
#define LIST_MAX 10
#define LOYALTY 5
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
    
    printf("\nInput Details for Employees: \n");
    for(i=0;i<employeeCount;i++){
    	printf("\n\n===Employee %d===\n",i+1);
    	/*CODE FOR INPUTS*/
    	printf("Input First Name: ");
    	scanf("%s", record.employeeList[i].employeeInfo.fName);
    	printf("Input Month of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireMonth);
    	printf("Input Year of Hire: ");
    	scanf("%d", &record.employeeList[i].dateOfHire.hireYear);
    	
    	record.count++; //increment employee count
	}
	//get list
	loyalList=getLoyalList(record,&loyalListCount,date);
	
	/*COMPLETE THE FUNCTION CALL*/
    if (loyalListCount>0){
        display(loyalList, loyalListCount);
        	free(loyalList);
    } else {
       printf("There are currently no Employees who are eligible for the reward.\n");
    }
	
	return 0;

	
}

employee* getLoyalList(employeeRecords record,int *loyalListCount,currentDate currDate){
    /*CODE TO CREATE THE LOYAL LIST*/
    int count =0;
    
    for (int i=0; i<record.count; i++){
        int years = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if (years> LOYALTY || years == LOYALTY && record.employeeList[i].dateOfHire.hireMonth <=currDate.month){
             count++;
        } 
    }
    
    *loyalListCount=count;
    
    employee* loyal = (employee*)malloc(count* sizeof(employee));
    
    int j=0;
    for (int i=0; i<record.count; i++){
        int years = currDate.year - record.employeeList[i].dateOfHire.hireYear;
        if (years> LOYALTY || years == LOYALTY && record.employeeList[i].dateOfHire.hireMonth <=currDate.month){
             loyal[j++]=record.employeeList[i];
        }
    }
    
    return loyal;
}

void display(employee *loyalList,int loyalListCount){
    /*CODE TO DISPLAY*/
    	printf("Loyal List:\n\n");
    for (int i=0; i<loyalListCount; i++){
        printf("Name: %s -- Hire Date:%d-%d\n", loyalList[i].employeeInfo.fName, loyalList[i].dateOfHire.hireMonth, loyalList[i].dateOfHire.hireYear);
    }
}
