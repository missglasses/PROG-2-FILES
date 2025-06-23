
#include <stdio.h>

int myStrcmp(char str1[], char str2[]){
    int i=0;
    while (str1[i]!='\0'&&str2[i]!='\0'&&str1[i]!=str2[i]=='\0'){
        i++;
    }
    
    if(str1[i]<str2[i]){
    return -1; 
    } else if (str1[i]>str2[i]){
    return 1;    
    } else {
        return 0;
    }
}


int main() {
    char s1[] = "vanilla";
    char s2[] = "apple";
    char s3[] = "banana";
    char s4[] = "app";
    
    printf("'%s' vs '%s': %d\n", s1, s2, myStrcmp(s1, s2));  // 0 (equal)
    printf("'%s' vs '%s': %d\n", s1, s3, myStrcmp(s1, s3));  // -1 (apple < banana)
    printf("'%s' vs '%s': %d\n", s1, s4, myStrcmp(s1, s4));  // 1 (apple > app)
    
    return 0;
}
