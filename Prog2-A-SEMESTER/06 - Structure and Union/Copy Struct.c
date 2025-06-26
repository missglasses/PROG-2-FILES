#include <stdio.h>

struct Student{
    
    char name[20];
    int age;
    float grade;
    
};

int main() {
    
    //COPY A STRUCTURE

    struct Student s1 = {"Kendrick Lamar", 23, 90.0};
    struct Student s2 = s1;
    
    printf("%s\t%d\t%.2f\n", s1.name, s1.age,
    s1.grade);
    printf("%s\t%d\t%.2f\n", s2.name, s2.age,
    s2.grade);
    
    
    

    return 0;
}
