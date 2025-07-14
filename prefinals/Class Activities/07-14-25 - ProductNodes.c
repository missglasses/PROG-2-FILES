#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char String[20];

typedef struct {
    int day;
    int month;
    int year
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

Date createDate(int d, int m, int y);
void displayDate(Date d);
Product createProduct(int id, String name, Date exp, int qty, float price);
bool updateProductQty(ProdList *list, int id, int newQty);
void displayProduct (Product p);
void initProductList (ProdList *list);
ProdList createProductList();
bool addProductSortedByExp(ProdList *list, Product p);
ProdList removedProductOverDate(ProdList *list, Date cutoffDate);
void displayProducts(ProdList list);


int main (){

     char *months={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    createDate(31,months[1],2025);
    createProduct(001, "Tiramisu", createDate(8, months[1],2025), 15, 2995.0);
    createProduct(002, "Red Velvet", createDate(7, months[1], 2025), 12,1695.0);
    createProduct(003, " Velvet", createDate(7, months[1], 2025), 12, 1695.0);
    createProduct(004, "Fruit Festival", createDate(7, months[1], 2025), 12, 2250.0);



    return 0;
}


Date createDate(int d, int m, int y){

    Date petsa;
    petsa.day=d;
    petsa.month=m;
    petsa.year=y;

}
void displayDate(Date d){
    
}
Product createProduct(int id, String name, Date exp, int qty, float price){

    Product prod;
    prod.id = id;
    prod.name = name;
    prod.exp = exp;
    prod.qty= qty; 
    prod.price=price;
    

}
bool updateProductQty(ProdList *list, int id, int newQty){
    
    if (list->id==id){
        list->prodQty=prodQty;
    }
}
void displayProduct (Product p){
    
}
void initProductList (ProdList *list){
    list[0] = {000, "Carrot Cake", Date(9, months[1], 2025), 19, 1995.0};
}
ProdList createProductList(){
    
}
bool addProductSortedByExp(ProdList *list, Product p){
    
}
ProdList removedProductOverDate(ProdList *list, Date cutoffDate){
    
}
void displayProducts(ProdList list){
    
}
