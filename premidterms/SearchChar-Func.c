#include <stdio.h>
#include <string.h>

//FIND THE CHARACTER GIVEN BY USER INPUT

int findFirstChar(char *str, char find){
     
    for (int i=0; str[i]!='\0'; i++){
        if (str[i]==find){
            return i;
        }
    }
  return -1; //if not found
}
int main (){
    
    int i;
    char str[50];
    char find;
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    printf("Enter a character to find: ");
    scanf(" %c", &find);
   
    i=findFirstChar(str, find);
    
   if (i==-1){
       printf("Character '%c' not found in the string", find);
   } else {
        printf("First occurrence of '%c' is at index %d", find,i);
   }
    
    
    
    
    
    return 0;
}
