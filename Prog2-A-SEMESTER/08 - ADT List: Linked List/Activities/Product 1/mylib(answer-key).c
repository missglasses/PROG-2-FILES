#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

void displayDate(Date d) {
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    printf("%02d %s %d", d.date, months[d.month-1], d.year);
}

void displayProduct(Product p) {
    printf("Product ID: %d\n", p.prodID);
    printf("Product Name: %s\n", p.prodName);
    printf("Shelf Life: %d months\n", p.prodShelfLife);
    printf("Manufacturing Date: ");
    displayDate(p.prodMFG);
    printf("\n");
    printf("Quantity: %d\n", p.prodQty);
}

void displayProducts(ProductList prodList) {
     printf("%-10s | %-25s | %-15s | %-10s | %s\n",
        "ID", "Name", "Shelf Life", "Quantity", "Manufactured Date");

    for(int i = 0; i < prodList.count; i++) {
        Product p = prodList.prods[i];
        printf("%10d | %-25s | %15d | %10d | ",
              p.prodID, p.prodName, p.prodShelfLife, p.prodQty);
        displayDate(p.prodMFG);
        printf("\n");
    }
}

Date createDate(int date, int month, int year) {
    Date d;
    d.date = date;
    d.month = month;
    d.year = year;
    return d;
}

Product createProduct(int prodID, char prodName[], int prodShelfLife, Date prodMFG, int prodQty) {
    Product p;
    p.prodID = prodID;
    strcpy(p.prodName, prodName);
    p.prodShelfLife = prodShelfLife;
    p.prodMFG = prodMFG;
    p.prodQty = prodQty;
    return p;
}

ProductList populateProductList(int option, int count) {
    Product list[20];
    int ctr = 0;
    ProductList prods;

    // Initialize all products with correct dates
    list[ctr++] = createProduct(1, "BBQ Sauce", 12, createDate(5, 7, 2024), 10);
    list[ctr++] = createProduct(2, "Variental Vinegar", 24, createDate(16, 3, 2023), 17);
    list[ctr++] = createProduct(3, "Marmalade", 18, createDate(25, 9, 2023), 30);
    list[ctr++] = createProduct(4, "Chocolate Chaud", 24, createDate(25, 12, 2024), 25);
    list[ctr++] = createProduct(5, "Compote", 18, createDate(7, 4, 2023), 5);
    list[ctr++] = createProduct(6, "Spiced Sea Salt", 36, createDate(1, 1, 2024), 32);
    list[ctr++] = createProduct(7, "Pizza Paste", 18, createDate(15, 5, 2023), 12);
    list[ctr++] = createProduct(8, "Bruschetta", 18, createDate(21, 8, 2024), 18);
    list[ctr++] = createProduct(9, "Vinaigrette", 18, createDate(14, 6, 2024), 3);
    list[ctr++] = createProduct(10, "Infused Oil", 18, createDate(25, 8, 2023), 30);
    list[ctr++] = createProduct(11, "Butter", 4, createDate(18, 10, 2023), 10);
    list[ctr++] = createProduct(12, "Beans", 12, createDate(14, 2, 2024), 17);
    list[ctr++] = createProduct(13, "Olives", 24, createDate(29, 8, 2023), 30);
    list[ctr++] = createProduct(14, "Pickles", 24, createDate(21, 12, 2024), 25);
    list[ctr++] = createProduct(15, "Cereal", 12, createDate(4, 4, 2024), 5);
    list[ctr++] = createProduct(16, "Yogurt", 4, createDate(1, 1, 2025), 32);
    list[ctr++] = createProduct(17, "Pork", 1, createDate(20, 4, 2025), 12);
    list[ctr++] = createProduct(18, "Cream", 2, createDate(29, 4, 2025), 18);
    list[ctr++] = createProduct(19, "Cheese", 12, createDate(8, 1, 2024), 3);
    list[ctr++] = createProduct(20, "Milk", 4, createDate(5, 8, 2023), 30);

    prods.prods = malloc(sizeof(Product) * count);
    prods.count = 0;
    prods.max = count;

    if(option == 1) {
        // First 'count' products
        memcpy(prods.prods, list, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 2) {
        // Products 11-20 (but only 'count' of them)
        memcpy(prods.prods, list+10, sizeof(Product) * count);
        prods.count = count;
    } else if(option == 3) {
        // Even-indexed products (0, 2, 4...)
        for(int i = 0; i < 20 && prods.count < count; i += 2) {
            prods.prods[prods.count++] = list[i];
        }
    } else {
        // Odd-indexed products (1, 3, 5...)
        for(int i = 1; i < 20 && prods.count < count; i += 2) {
            prods.prods[prods.count++] = list[i];
        }
    }

    return prods;
}
