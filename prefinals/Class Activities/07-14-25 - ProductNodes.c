#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef char String[20];

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

Date createDate(int d, int m, int y);
void displayDate(Date d);
Product createProduct(int id, String name, Date exp, int qty, float price);
bool updateProductQty(ProdList *list, int id, int newQty);
void displayProduct (Product p);
void initProductList (ProdList *list);
bool addProductSortedByExp(ProdList *list, Product p);
ProdList removedProductOverDate(ProdList *list, Date cutoffDate);
void displayProducts(ProdList list);


int main (){

    char *months[13]={" ", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    Product prodList;
    initProductList(&prodList); 

    Product p1 = createProduct(001, "Tiramisu", createDate(08, months[1],2025), 15, 2995.0);
    Product p2 =createProduct(002, "Red Velvet", createDate(07, months[1], 2025), 12,1695.0);
    Product p3 = createProduct(003, " Velvet", createDate(07, months[1], 2025), 12, 1695.0);
    Product p4 =createProduct(004, "Fruit Festival", createDate(07, months[1], 2025), 12, 2250.0);

    addProductSortedByExp(&prodList,p1); 
    addProductSortedByExp(&prodList,p2); 
    addProductSortedByExp(&prodList,p3); 
    addProductSortedByExp(&prodList,p4); 

    printf("\n=== PRODUCT TABLE ===\n");
    displayProducts(productList);

    printf("\n=== PRODUCT DETAILS ===\n");
    ProdNode *curr = productList;
    while (curr != NULL) {
        displayProduct(curr->prod);
        curr = curr->next;
    }

    return 0;
}


Date createDate(int d, int m, int y){

    Date petsa;
    petsa.day=d;
    petsa.month=m;
    petsa.year=y;

    return petsa;

}
void displayDate(Date d){
    printf("%d %s %d", d.day, d.month, d.year);
}
Product createProduct(int id, String name, Date exp, int qty, float price){

    Product prod;
    prod.prodID = id;
    strcpy(prod.prodName, name);
    prod.dateMfg = exp;
    prod.prodQty= qty; 
    prod.prodPrice=price;

    return prod;

}
bool updateProductQty(ProdList *list, int id, int newQty){
   ProdNode *curr = *list;
    while(curr!=NULL){
        if(curr->prod.prodID==id){
            curr->prod.prodQty=newQty;
            return true;
        }
        curr = curr->next;
    }
}
void displayProduct (Product p){
    printf("ID: %d\n", list->prod.prodID);
    printf("Name: %s\n", list->prod.prodName);
    printf("Mfg Date: %02d-%s-%04d\n", list->prod.dateMfg.day, monthNames[list->prod.dateMfg.month], list->prod.dateMfg.year);
    printf("Exp Date: %02d-%s-%04d\n", list->prod.dateExp.day, monthNames[list->prod.dateExp.month], list->prod.dateExp.year);
    printf("Quantity: %d\n", list->prod.prodQty);
    printf("Price: %.2f\n", list->prod.prodPrice);
    printf("-------------------------\n");
}
void initProductList (ProdList *list){
    // list[0] = {000, "Carrot Cake", Date(9, months[1], 2025), 19, 1995.0}
    *list =NULL;
    return true;
}

bool addProductSortedByExp(ProdList *list, Product p){
    
}
ProdList removedProductOverDate(ProdList *list, Date cutoffDate){

}
void displayProducts(ProdList list){
    ProdNode *curr = list;
   printf("ID   Name             Mfg Date     Exp Date     Qty   Price\n");
    printf("--------------------------------------- ---------------------\n");
    ProdNode *curr = list;
    while (curr != NULL) {
        Product p = curr->prod;
        printf("%-4d %-16s %02d-%s-%04d  %02d-%s-%04d  %-5d %.2f\n",
               p.prodID,
               p.prodName,ProdNode *newNode = (ProdNode *)malloc(sizeof(ProdNode));
  
   
}

