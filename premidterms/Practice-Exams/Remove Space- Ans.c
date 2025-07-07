#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeSpace(char str[]){
    
    int i=0, j=0;
    
    while(str[i]!='\0'){
        if(str[i]!=' ' && str[i]!='\t' && str[i]!='\n'){
            str[j]=str[i];//to keep char 
         j++;
        }
       i++; 
    }
    //add null term
    str[j]='\0';    
}



int main (){

    char str[100];
    //char str2[100];
    printf("Enter a string: ");
    scanf(" %[^\n]", str); 
    
    removeSpace(str);
    
    //printf("\nModified string: %s", str2);
    printf("Modified string: %s", str);
    

    
    return 0;
}
