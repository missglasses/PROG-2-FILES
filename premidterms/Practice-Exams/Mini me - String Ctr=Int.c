#include <stdio.h>
#include <string.h>

void compress(char str[]){
    int i=0;
    while (str[i]!='\0'){
    char current = str[i];
    int count = 1;
    
        while(str[i]==str[i+1]){
            count++;
            i++;
        }
    
        printf("%c", current); 
    
        //prints count if more than 1 
        if (count>1){
            printf("%d", count);
        }
        i++;
    } 
    printf("\n");
}

int main (){
    
    char str[20];
    printf("Enter a string: ");
    scanf(" %[^\n]", str);
    
    printf("Compressed string: ");
    compress(str);
    
    return 0;
}
