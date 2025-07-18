#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void displayDate(Date d) {
    // 1 - to do code logic here
    //initilaize montsh as string then print 
    char* months[] = {"Jan", "Feb", "Mar", "Ap","May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%d %s %d", d.date, months[d.month - 1], d.year);
}


void displayProduct(Product p) {
    // 1 - to do code logic here
    printf("Product ID: %d\n", p.prodID);
    printf("Product Name: %s\n", p.prodName);
    printf("Shelf Life: %d months\n", p.prodShelfLife);
    printf("Manufacturing Date: ");
    displayDate(p.prodMFG);
    printf("\n");
    printf("Quantity: %d\n", p.prodQty);

}

void displayProducts(ProductList prodList) {
    printf("%s | %s | %s | %s | %s\n",
        "ID", "Name", "Shelf Life", "Quantity", "Manufactured Date");

    // 3 - to do code logic here
        for (int i = 0; i < prodList.count; i++) {
        printf("%d | %s | %d | %d | ", 
               prodList.prods[i].prodID, 
               prodList.prods[i].prodName, 
               prodList.prods[i].prodShelfLife, 
               prodList.prods[i].prodQty);
        displayDate(prodList.prods[i].prodMFG);
        printf("\n");

}

Date createDate(int date, int month, int year) {
    // 4 - to do code logic here
  //  date newdate then assign to dmy
  Date newDate;
  newDate.date = date;
  newDate.month = month;
  newDate.year = year;
    
    return newDate;

}

Product createProduct(int prodID, char prodName[], int prodShelfLife, Date prodMFG, int prodQty) {
    // 5 - to do code logic here
    Product newProd;
    newProd.prodID=prodID;
    newProd->prodName= pro
    newProd.prodShelfLife=prodShelfLife;
    newProd.prodQty = prodQty;
    
    return newProd;

}

ProductList populateProductList(int option, int count) {
    Product list[20];
    int ctr = 0;
    ProductList prods;

    prods.prods = malloc(sizeof(Product) * count);
    prods.count = 0;
    prods.max = count;

    list[ctr++] = createProduct(1, "BBQ Sauce", 12, createDate(5, 6, 2024), 10);
    list[ctr++] = createProduct(2, "Variental Vinegar", 24, createDate(16, 2, 2023), 17);
    list[ctr++] = createProduct(3, "Marmalade", 18, createDate(25, 8, 2023), 30);
    list[ctr++] = createProduct(4, "Chocolate Chaud", 24, createDate(25, 11, 2024), 25);
    list[ctr++] = createProduct(5, "Compote", 18, createDate(7, 3, 2023), 5);
    list[ctr++] = createProduct(6, "Spiced Sea Salt", 36, createDate(1, 0, 2024), 32);
    list[ctr++] = createProduct(7, "Pizza Paste", 18, createDate(15, 4, 2023), 12);
    list[ctr++] = createProduct(8, "Bruschetta", 18, createDate(21, 7, 2024), 18);
    list[ctr++] = createProduct(9, "Vinaigrette", 18, createDate(14, 5, 2024), 3);
    list[ctr++] = createProduct(10, "Infused Oil", 18, createDate(25, 8, 2023), 30);
    list[ctr++] = createProduct(11, "Butter", 4, createDate(18, 9, 2023), 10);
    list[ctr++] = createProduct(12, "Beans", 12, createDate(14, 1, 2024), 17);
    list[ctr++] = createProduct(13, "Olives", 24, createDate(29, 7, 2023), 30);
    list[ctr++] = createProduct(14, "Pickles", 24, createDate(21, 11, 2024), 25);
    list[ctr++] = createProduct(15, "Cereal", 12, createDate(4, 3, 2024), 5);
    list[ctr++] = createProduct(16, "Yogurt", 4, createDate(1, 0, 2025), 32);
    list[ctr++] = createProduct(17, "Pork", 1, createDate(20, 4, 2025), 12);
    list[ctr++] = createProduct(18, "Cream", 2, createDate(29, 4, 2025), 18);
    list[ctr++] = createProduct(19, "Cheese", 12, createDate(8, 1, 2024), 3);
    list[ctr++] = createProduct(20, "Milk", 4, createDate(5, 8, 2023), 30);

    if(option == 1) {
        memcpy(prods.prods, list, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 2) {
        memcpy(prods.prods, list+10, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 3) {
        for(int i = 0; i < 20 && count > prods.count; ++i) {
            if(i % 2 == 0) {
                prods.prods[prods.count++] = list[i];
            }
        }
    } else {
        for(int i = 0; i < 20 && count > prods.count; ++i) {
            if(i % 2 == 1) {
                prods.prods[prods.count++] = list[i];
            }
        }
    }

    return prods;
}
