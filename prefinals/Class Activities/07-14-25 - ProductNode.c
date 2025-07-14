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



    return 0;
}


Date createDate(int d, int m, int y){

}
void displayDate(Date d){
    
}
Product createProduct(int id, String name, Date exp, int qty, float price){
    
}
bool updateProductQty(ProdList *list, int id, int newQty){
    
}
void displayProduct (Product p){
    
}
void initProductList (ProdList *list){
    
}
ProdList createProductList(){
    
}
bool addProductSortedByExp(ProdList *list, Product p){
    
}
ProdList removedProductOverDate(ProdList *list, Date cutoffDate){
    
}
void displayProducts(ProdList list){
    
}
