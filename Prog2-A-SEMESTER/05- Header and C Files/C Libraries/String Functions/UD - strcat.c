
#include <stdio.h>

/*while des is not null & while src is not null, dest=src, increment both i and j, add null*/
void myStrCat(char src[], char des[]){
    int i=0,j=0;
   
   while(des[i]!='\0'){
       i++;
   }
   //to add space 
    des[i] = ' ';
    i++;
    
   while(src[j]!='\0'){
       des[i]=src[j];
       i++;
       j++;
   }
  
  des[i]='\0';
}


int main() {
    
    char src[]="Days";
    char des[20]="Good";
    char n=5;
    
    myStrCat(src,des);
    
    printf("Original string: %s\n", src);
    printf("Combined string: %s\n", des); //Good Days

    return 0;
}
