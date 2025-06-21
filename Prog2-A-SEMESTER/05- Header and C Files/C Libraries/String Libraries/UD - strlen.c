
#include <stdio.h>

int myStrlen(char str[]){
    
    int i;
    while (str[i]!='\0'){
        i++;
    }
    return i;
    
}


int main() {
    
    char str[50]={"Let's pass prog 2!"}; //Length: 18
    
    int len =myStrlen(str);
    
    printf("Length: %d\n", len);

    return 0;
}
