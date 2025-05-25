#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "problems.h"

/* YOU MAY ADD TO MAIN IF NECESSARY FOR YOUR SOLUTION, BUT DO TAKE NOTE THAT YOU SHOULD NOT REMOVE ANY CODE FROM MAIN. YOU CAN CREATE YOUR OWN FUNCTIONS IF NECESSARY */

int main(){
	studentNode *studentListhead;
	gradeNode *gradeListhead;
	int idNum;

	Node* head;

    //Populates the Student Linked List
	studentListhead=populateStudents();

    //Populates the Grades Linked List
	gradeListhead=populateGradesRecord();

	head=populate(studentListhead,gradeListhead);

	printf("Input ID Number of Student: ");
	scanf("%d",&idNum);

	display(head,idNum);

	return 0;
}
