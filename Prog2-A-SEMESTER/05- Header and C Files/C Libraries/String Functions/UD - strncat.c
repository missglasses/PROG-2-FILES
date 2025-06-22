
#include <stdio.h>

/*while des is not null & while src is not null, dest=src, increment both i and j, add null*/
void myStrCat(int n, char src[], char des[]){
    int i=0,j=0;
   
   while(des[i]!='\0'){
       i++;
   }

   
   while(j<n && src[j]!='\0'){
       des[i]=src[j];
       i++;
       j++;
       
   }
   des[i]='\0';
   
}


int main() {
    
    char src[]="Days";
    char des[20]="Good";
    char n=2;
    
    myStrCat(n,src,des);
    
    printf("Original string: %s\n", src);
    printf("Combined string: %s\n", des); //output: GoodDa
    //copies only Da

    return 0;
}
