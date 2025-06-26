#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char brand[20];
    char model[20];
    char color[20];
}Car; 


typedef struct {
    char fName[20];
    char lName[20];
    int yearOfPurchase;
    Car c;

}Owner; 



int main (){

    Owner one ={"Gran", "Sabandal", 2015, {01, "Honda", "Civic Type R", "White"}};
    printf("%s %s\n%d\n#%d %s %s %s\n", one.fName, one.lName, one.yearOfPurchase, one.c.id,  one.c.brand, one.c.model, one.c.color);
  // prints
//Gran Sabandal
// 2015
// #1 Honda Civic Type R White


   

    return 0;
}
