
#include <stdio.h>

//strncpy copies up to n characters you specify
//if string<n -- it pads remaining spaces with '\0'
void myStrNCpy(int n, char src[], char des[]){
    int i=0;
    while (i<n && src[i]!='\0'){
        des[i]=src[i];
        i++;
    }
    while (i<n){ //this is how padding works
        des[i]='\0';
        i++;
    }
}


int main() {
    
    char src[20]="Mahal ko ang prog";
    char des[20];
    char n=5;
    
    myStrNCpy(n, src,des);
    
    printf("Original string: %s\n", src);
    printf("Copied string: %s\n", des);

    return 0;
}
