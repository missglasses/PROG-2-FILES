#ifndef MYLIB_H
#define MYLIB_H

#include "mydate.h"

typedef struct {
    int prodID;
    char prodName[20];
    int prodShelfLife; // in months
    Date prodMFG;
    int prodQty;
} Product;

typedef struct {
    Product *prods; // dynamic collection of products
    int count; // current number of products in list
    int max; // maximum number of items currently products can hold
} ProductList;

void displayDate(Date d);
void displayProduct(Product p);
void displayProducts(ProductList prodList);
Date createDate(int date, int month, int year);
Product createProduct(int prodID, char prodName[], int prodShelfLife, Date prodMFG, int prodQty);
ProductList populateProductList(int option, int count);

#endif
