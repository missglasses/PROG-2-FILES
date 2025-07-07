#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main (){

    char str[100];
    char str2[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str); 
    
    
    printf("\nModified string: %s", str2);
    

    
    return 0;
}
