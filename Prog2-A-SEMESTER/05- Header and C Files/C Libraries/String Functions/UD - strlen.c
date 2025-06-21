
#include <stdio.h>

int myStrlen(char str[]){
    
    int i=0;
    while (str[i]!='\0'){
        i++;
    }
    return i;
    
}

int skipSpace(char str[]){
    int i=0, count=0,flag=0;
    while (str[i]!='\0'){
        if(str[i]==' '||str[i]=='\n'||str[i]=='\t'){
          flag=0;
        } else if (flag==0){
            flag =1;
            count++;
        }
        i++;
    }
     return count;
}


int main() {
    
    char str[50]={"Let's pass prog 2!"}; //Length: 18
    
    int len =myStrlen(str);
    int len2 = skipSpace(str);
    
    
    printf("Full Length: %d\n", len);
    printf("Word Count: %d\n", len2);

    return 0;
}
