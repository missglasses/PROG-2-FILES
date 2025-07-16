#include <stdio.h>
#include <string.h>
typedef char String [20];

typedef struct {
    int day;
    int month;
    int year;
}Date;

typedef struct {
    int prodID;
    String prodName; 
    Date dateMfg;
    int prodQty;
    float prodPrice;
}Product;

typedef struct {
    Product prod;
    struct node *next;
}ProdNode, *ProdList;

Date createDate(int d, int m, int y); //1
void displayDate(Date d); //2
Product createProduct(int id, String name, Date exp, int qty, float price); //3
void displayProduct (Product p); //4

int main (){
    char *months[13]={" ", "Jan", "Feb", "Mar",  "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    Product prodList;
    //3
    Product p1 = createProduct(001, "Tiramisu", createDate(8, 1, 2025), 15, 2995.0); //@months, directly put the index
    Product p2 = createProduct(002, "Red Velvet", createDate(7, 1, 2025), 12, 1695.0);
    Product p3 = createProduct(003, "Velvet", createDate(7, 1, 2025), 12, 1695.0);
    Product p4 = createProduct(004, "Fruit Festival", createDate(7, 1, 2025), 12, 2250.0);
    
    return 0;
}

Date createDate(int d, int m, int y){
    Date petsa;
    petsa.day = d;
    petsa.month = m;
    petsa.year =y;

    return petsa;
}

void displayDate(Date d){
    printf("%d %s %d", d.day, d.month, d.year);
}

Product createProduct(int id, String name, Date exp, int qty, float price){
    Product prod;
    prod.prodID=id;
    strcpy(prod.prodName, name);
    prod.dateMfg=exp;
    prod.prodQty=qty;
    prod.prodPrice=price;

    return prod;
}

void displayProduct (Product p){

}

