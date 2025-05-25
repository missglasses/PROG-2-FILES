#include <stdio.h>
#include <stdlib.h>

//BASICALLY COUNTS HOW MANY WORDS ARE GIVEN FROM USER INPUT
int countWords(char *str){
    int count=0, flag=0;
    
    while(*str){
        if(*str==' '){
            flag = 0; //flag is init to 0
        } else if (flag==0){ // if flag=0 is spotted, turn to 1
            flag=1; //start of new word
            count++; //counts the new word
        }
        str++;
    }
    return count;
}

int main(){
    
    char str[50];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    int count = countWords(str);
    
    printf("Number of words: %d", count);
    
    return 0;
    
}
