//SAY HI TO ERRORS :d
#include <stdio.h>

int main() {
  
  int a[5];
    int b[5];
    int *c;
  
    a=b; // error: assignment to expression with array type
    c=a; //no error
    a=c; //assignment to expression with array type
    
    

    return 0;
}
