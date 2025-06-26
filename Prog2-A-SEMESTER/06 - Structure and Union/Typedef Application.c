#include <stdio.h>

/*APPLYING TYPEDEF*/

//From this : 
// struct Car {
//     int id;
//     char brand[20];
//     char model[20];
//     char color[20];
// }; 

//To this:

typedef struct {
    int id;
    char brand[20];
    char model[20];
    char color[20];
}Car; 


int main (){

     Car car1 = {00, "Mazda", "Miata", "Black"};
     Car car2 = {01, "Honda", "Civic Type R", "White"};


    printf("%d %s %s %s\n", car1.id,  car1.brand, car1.model,car1.color);
    printf("%d %s %s %s\n", car2.id,  car2.brand, car2.model,car2.color);

    
        

    return 0;
}
