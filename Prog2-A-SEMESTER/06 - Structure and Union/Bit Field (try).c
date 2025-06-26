#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int id : 16;        // 16 bits (0-65535)
    unsigned int age : 7;        // 7 bits (0-127)
    bool enrollmentStats : 1;        // 1 bit (true/false)
    bool w_scholarship : 1;    // 1 bit 
    unsigned int grade : 4;      // 4 bits (0-15)
    unsigned int courses : 5;    // 5 bits (0-31)
} Student;


int main (){

  Student alice = {
        .id = 12345,
        .age = 20,
        .enrollmentStats = true,
        .w_scholarship = false,
        .grade = 10,
        .courses = 4
    };
    
    printf("Student ID: %u\n", alice.id);
    printf("Age: %u\n", alice.age);
    printf("Enrolled: %s\n", alice.enrollmentStats ? "Yes" : "No");
    printf("Scholarship: %s\n", alice.w_scholarship ? "Yes" : "No");
    printf("Grade: %u\n", alice.grade);
    printf("Courses: %u\n", alice.courses);
    
    //zu = ead values of type size_t ; z- size_t & u unsigned
    printf("\nSize of Student (in bit fields): %zu bytes\n", sizeof(Student));
    printf("Size without bit fields: %zu bytes\n", 
           sizeof(unsigned int) * 3 + sizeof(bool) * 2); 


  return 0;
}
