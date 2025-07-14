
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[20];

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int prodID;
    String prodName;
    Date dateMfg;
    Date dateExp;
    int prodQty;
    float prodPrice;
} Product;

typedef struct node {
    Product prod;
    struct node *next;
} ProdNode, *ProdList;

const char *monthNames[13] = {
    "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

// Function declarations
Date createDate(int d, int m, int y);
Product createProduct(int id, String name, Date mfg, Date exp, int qty, float price);
bool initProductList(ProdList *list);
bool addProductSortedByExp(ProdList *list, Product p);
void displayProducts(ProdList list);
void displayProduct(Product p);
int compareDates(Date a, Date b);

int main() {
    ProdList productList;
    if (!initProductList(&productList)) {
        printf("Failed to initialize product list.\n");
        return 1;
    }

    Product p1 = createProduct(1, "Tiramisu", createDate(8, 2, 2025), createDate(8, 3, 2025), 15, 2995.00);
    Product p2 = createProduct(2, "Red Velvet", createDate(7, 1, 2025), createDate(7, 2, 2025), 12, 1695.00);
    Product p3 = createProduct(3, "Velvet", createDate(7, 3, 2025), createDate(7, 4, 2025), 10, 1695.00);
    Product p4 = createProduct(4, "Fruit Fest", createDate(6, 1, 2025), createDate(6, 2, 2025), 20, 2250.00);

    addProductSortedByExp(&productList, p1);
    addProductSortedByExp(&productList, p2);
    addProductSortedByExp(&productList, p3);
    addProductSortedByExp(&productList, p4);

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

//------------------ Functions --------------------

Date createDate(int d, int m, int y) {
    Date date = {d, m, y};
    return date;
}

Product createProduct(int id, String name, Date mfg, Date exp, int qty, float price) {
    Product prod;
    prod.prodID = id;
    strcpy(prod.prodName, name);
    prod.dateMfg = mfg;
    prod.dateExp = exp;
    prod.prodQty = qty;
    prod.prodPrice = price;
    return prod;
}

bool initProductList(ProdList *list) {
    *list = NULL;
    return true;
}

int compareDates(Date a, Date b) {
    if (a.year != b.year) return a.year - b.year;
    if (a.month != b.month) return a.month - b.month;
    return a.day - b.day;
}

bool addProductSortedByExp(ProdList *list, Product p) {
    ProdNode *newNode = (ProdNode *)malloc(sizeof(ProdNode));
    if (!newNode) return false;

    newNode->prod = p;
    newNode->next = NULL;

    if (*list == NULL || compareDates(p.dateMfg, (*list)->prod.dateMfg) < 0) {
        newNode->next = *list;
        *list = newNode;
        return true;
    }

    ProdNode *curr = *list;
    while (curr->next && compareDates(curr->next->prod.dateMfg, p.dateMfg) < 0) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

void displayProducts(ProdList list) {
    if (!list) {
        printf("No products to display.\n");
        return;
    }

    printf("ID   Name             Mfg Date     Exp Date     Qty   Price\n");
    printf("------------------------------------------------------------\n");

    ProdNode *curr = list;
    while (curr != NULL) {
        Product p = curr->prod;
        printf("%-4d %-16s %02d-%s-%04d  %02d-%s-%04d  %-5d %.2f\n",
               p.prodID,
               p.prodName,
               p.dateMfg.day, monthNames[p.dateMfg.month], p.dateMfg.year,
               p.dateExp.day, monthNames[p.dateExp.month], p.dateExp.year,
               p.prodQty,
               p.prodPrice);
        curr = curr->next;
    }
}

void displayProduct(Product p) {
    printf("ID: %d\n", p.prodID);
    printf("Name: %s\n", p.prodName);
    printf("Mfg Date: %02d-%s-%04d\n", p.dateMfg.day, monthNames[p.dateMfg.month], p.dateMfg.year);
    printf("Exp Date: %02d-%s-%04d\n", p.dateExp.day, monthNames[p.dateExp.month], p.dateExp.year);
    printf("Quantity: %d\n", p.prodQty);
    printf("Price: %.2f\n", p.prodPrice);
    printf("-------------------------\n");
}
