
#include <stdio.h>

/*STEPS: func() -- str1 = str2, increment, add null at the end of str2*/
void myStrCpy(char src[], char des[]){
    int i=0;
    while (src[i]!='\0'){
        des[i]=src[i];
        i++;
    }
    des[i]='\0';
}


int main() {
    
    char src[20]="Mahal ko ang prog";
    char des[20];
    
    myStrCpy(src,des);
    
    printf("Original string: %s\n", src);
    printf("Copied string: %s\n", des);

    return 0;
}
