#include <stdio.h>
#include <stdlib.h>

//ARRAY WITHIN A STRUCT 
typedef struct{
    
    int stud_id;
    char stud_fName[50];
    char stud_lName[50];
    float grades[5];
    
}Student;
int main() {
    
    Student s1 = {1, "Cindy", "Leps", {99,98,97,98,96}};
    Student s2 = {2, "Brent", "Manalaur", {99,98,99,99,98}};
    
     printf("%d\n %s %s\n", s1.stud_id, s1.stud_fName, s1.stud_lName);
     for (int i=0; i<5; i++){
        printf(" %.2f\n", s1.grades[i]); 
     }
     
     printf("%d\n %s %s\n", s2.stud_id, s2.stud_fName, s2.stud_lName);
     for (int i=0; i<5; i++){
        printf(" %.2f\n", s2.grades[i]); 
     }

    return 0;
}

/*Output: 1
 Cindy Leps
 99.00
 98.00
 97.00
 98.00
 96.00
2
 Brent Manalaur
 99.00
 98.00
 99.00
 99.00
 98.00

*/
