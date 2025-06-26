#include <stdio.h>


//PASSING STRUCT TO A FUNC 
struct Car {
    int id;
    char brand[20];
    char model[20];
    char color[20];
}; 

void incrementId(struct Car c1, struct Car *incC1){
    c1.id++;
    incC1->id++;
}



int main (){

    struct Car car1 = {00, "Mazda", "Miata", "Black"};
    struct Car car2 = {01, "Honda", "Civic Type R", "White"};
    struct Car car3={02};


    printf("%d %s %s %s\n", car1.id,  car1.brand, car1.model,car1.color);
    printf("%d %s %s %s\n", car2.id,  car2.brand, car2.model,car2.color);

    incrementId(car1, &car3);
    printf("Increment id: %d\n", car3.id);
        

    return 0;
}
