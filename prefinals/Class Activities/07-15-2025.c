#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[100];
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

typedef struct {
    Product *prods; //dynamic array
    int count; //current number of prods in prods
    int max; //max number of products
    int max_qty; //quantity limit
    int current_qty; //the current total qty
}Storage;


const char *monthNames[13] = {
    "", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

Date createDate(int d, int m, int y);
Product createProduct(int id, String name, Date mfg, Date exp, int qty, float price);
bool updateProductQty(ProdList *list, int id, int newQty);
void displayProduct(Product p);
void initProductList(ProdList *list);
bool addProductSortedByExp(ProdList *list, Product p);
ProdList removedProductOverDate(ProdList *list, Date cutoffDate);
void displayProducts(ProdList list);
/*******************************************************************************/
Product *getProduct(ProdList list, int qty_threshold);
void displayProductList(Product *aList);
bool addItemToStorage(Storage *item_storage, Product p);


int main() {
    ProdList list;
    initProductList(&list);
    printf("\n\t\t\t\t\t\t\t\t\t10 DOVE STREEET\n");
    Product p1 = createProduct(001, "Tiramisu", createDate(8, 2, 2025), createDate(8, 2, 2026), 15, 2995.0);
    Product p2 = createProduct(002, "Red Velvet", createDate(7, 2, 2025), createDate(7, 2, 2026), 12, 1695.0);
    Product p3 = createProduct(003, "Velvet", createDate(7, 2, 2025), createDate(7, 2, 2026), 12, 1695.0);
    Product p4 = createProduct(004, "Fruit Festival", createDate(7, 2, 2025), createDate(7, 2, 2026), 12, 2250.0);

    addProductSortedByExp(&list, p1);
    addProductSortedByExp(&list, p2);
    addProductSortedByExp(&list, p3);
    addProductSortedByExp(&list, p4);

    printf("ID   | NAME              | MFG DATE         | EXP DATE         | QTY  | PRICE\n");
    printf("-----------------------------------------------------------------------------------\n");
    displayProducts(list);
    
    Date cutoff = createDate(7, 2, 2025);  
    list = removedProductOverDate(&list, cutoff);

    printf("\nPRODUCTS AFTER EXPIRED PRODUCTS DELETION\n");
    displayProducts(list);

    return 0;
}

Date createDate(int d, int m, int y) {
    Date petsa;
    petsa.day = d;
    petsa.month = m;
    petsa.year = y;
    return petsa;
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

bool updateProductQty(ProdList *list, int id, int newQty) {
    ProdNode *curr = *list;
    while (curr != NULL) {
        if (curr->prod.prodID == id) {
            curr->prod.prodQty = newQty;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void displayProduct(Product p) {
    printf("%03d  | %-16s | %02d %s %04d | %02d %s %04d | %-4d | Php %.2f\n",
        p.prodID,
        p.prodName,
        p.dateMfg.day,
        monthNames[p.dateMfg.month],
        p.dateMfg.year,
        p.dateExp.day,
        monthNames[p.dateExp.month],
        p.dateExp.year,
        p.prodQty,
        p.prodPrice
    );
}

void initProductList(ProdList *list) {
    *list = NULL;
}

bool addProductSortedByExp(ProdList *list, Product p) {
    ProdNode *newNode = (ProdNode *)malloc(sizeof(ProdNode));
    if (!newNode) return false;

    newNode->prod = p;
    newNode->next = NULL;

    if (*list == NULL || (*list)->prod.dateExp.year > p.dateExp.year ||
        (*list)->prod.dateExp.year == p.dateExp.year && (*list)->prod.dateExp.month > p.dateExp.month ||
        (*list)->prod.dateExp.year == p.dateExp.year && (*list)->prod.dateExp.month == p.dateExp.month && (*list)->prod.dateExp.day > p.dateExp.day) {
        
        newNode->next = *list;
        *list = newNode;
    } else {
        ProdNode *curr = *list;
        while (curr->next != NULL && !(curr->next->prod.dateExp.year > p.dateExp.year ||
            (curr->next->prod.dateExp.year == p.dateExp.year && curr->next->prod.dateExp.month > p.dateExp.month) ||
            (curr->next->prod.dateExp.year == p.dateExp.year && curr->next->prod.dateExp.month == p.dateExp.month && curr->next->prod.dateExp.day > p.dateExp.day))) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return true;
}

ProdList removedProductOverDate(ProdList *list, Date cutoffDate) {
    ProdNode *curr = *list, *prev = NULL;
    while (curr != NULL) {
        if (curr->prod.dateExp.year < cutoffDate.year ||
            (curr->prod.dateExp.year == cutoffDate.year && curr->prod.dateExp.month < cutoffDate.month) ||
            (curr->prod.dateExp.year == cutoffDate.year && curr->prod.dateExp.month == cutoffDate.month && curr->prod.dateExp.day < cutoffDate.day)) {
            
            if (prev == NULL) {
                *list = curr->next;
            } else {
                prev->next = curr->next;
            }
            
            ProdNode *temp = curr;
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return *list;
}

void displayProducts(ProdList list) {
    ProdNode *curr = list;
    while (curr != NULL) {
        displayProduct(curr->prod);
        curr = curr->next;
    }
}

/*******************************************************************************/
Product *getProduct(ProdList list, int qty_threshold){
    /*-get all products in list that the quantity is above the threshold
    -add at the very end a dummy product iwith id -1 to denote as end of product
    - if no product matches return the fummy product with id -1*/

    Product *produkto = malloc(sizeof(Product));
    produkto


}
void displayProductList(Product *aList){
    /*display products in the above list , if of -1 is empty or no list to display */
   
    // printf("%03d  | %-16s | %02d %s %04d | %02d %s %04d | %-4d | Php %.2f\n",
    //      aList->.prodID,
    //      aList->.prodName,
    //      aList->.dateMfg.day,
    //      aList->[p.dateMfg.month],
    //      aList->.dateMfg.year,
    //      aList->.dateExp.day,
    //      aList->[p.dateExp.month],
    //      aList->.dateExp.year,
    //      aList->.prodQty,
    //      aList->.prodPrice
    // );
}
bool addItemToStorage(Storage *item_storage, Product p){
    /*-adds the new product in the prods based on qty, the larger the quanitty the father it iwill be stored in prods 
    - if storage is full do not add
    -assume that current product p is unique/fast time to be added / no duplicates
    */
}
